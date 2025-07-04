#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ti/csl/csl_chip.h"
#include "ti/csl/csl_cacheAux.h"
#include "platform.h"

#define SHARED_MEM_BASE       0x0C000000
#define SHARED_MEM_OFFSET     2700
#define SHARED_MEM_ADDR       (SHARED_MEM_BASE + SHARED_MEM_OFFSET)
#define BUFFER_SIZE           4096

#define DEVICE_REG32_W(x,y)   *(volatile uint32_t *)(x)=(y)
#define DEVICE_REG32_R(x)    (*(volatile uint32_t *)(x))
// IPC register macros
#define IPCGR1    (*(volatile uint32_t *)0x02620244U)
#define IPCAR1    (*(volatile uint32_t *)0x02620284U)

// Boot magic address stuff (adapted from TI example)
#define CHIP_LEVEL_REG  0x02620000
#define KICK0           (CHIP_LEVEL_REG + 0x0038)
#define KICK1           (CHIP_LEVEL_REG + 0x003C)
#define MAGIC_ADDR      0x8FFFFC
#define BOOT_MAGIC_ADDR(core)  (MAGIC_ADDR + (1<<28) + ((core)<<24))
#define IPCGR(core)            (0x02620240 + (core)*4)
#define NUMBER_OF_CORES        2
#define BOOT_MAGIC_NUMBER      0xBABEFACE
#define BOOT_UART_BAUDRATE     115200

typedef struct {
    volatile uint32_t flag;
    volatile uint32_t size;
    volatile char buffer[BUFFER_SIZE];
} SharedPacket;

volatile SharedPacket* shared = (SharedPacket*)SHARED_MEM_ADDR;

// Simple pacing
void short_delay() {
    volatile int i;
    for (i = 0; i < 100000; i++) {}
}

// --- Platform memory allocation hooks for platform lib (if needed) ---
uint8_t *Osal_platformMalloc (uint32_t num_bytes, uint32_t alignment) { return malloc(num_bytes); }
void Osal_platformFree (uint8_t *dataPtr, uint32_t num_bytes) { if (dataPtr) free(dataPtr); }
void Osal_platformSpiCsEnter(void) { return; }
void Osal_platformSpiCsExit (void) { return; }

// --- UART helper for baremetal output ---
void write_uart(char* msg) {
    uint32_t i, len = strlen(msg);
    for (i = 0; i < len; i++) platform_uart_write(msg[i]);
}

// --- Used for secondary core boot entry ---
void write_boot_magic_number(void) {
    *(volatile uint32_t*)MAGIC_ADDR = BOOT_MAGIC_NUMBER;
    DEVICE_REG32_W(MAGIC_ADDR, BOOT_MAGIC_NUMBER);
    while(1); // Spin forever (simulate simple bootloader "done" state)
}

// --- IPC Hello World (after boot) ---
void sendFromCore0(uint32_t id) {
    shared->size = snprintf((char*)shared->buffer, BUFFER_SIZE, "Hello from CORE0: msg %u", id);
    shared->flag = 0xA5A50000 | id;
    CACHE_wbL1d((void*)shared, sizeof(SharedPacket), CACHE_WAIT);
    IPCGR1 = 1;  // Trigger Core1
    printf("[C66xx_0] Sent msg %u: \"%s\"\n", id, shared->buffer);
}

void waitReplyCore0() {
    while (1) {
        CACHE_invL1d((void*)shared, sizeof(SharedPacket), CACHE_WAIT);
        if (shared->flag == 0) break;
        short_delay();
    }
    printf("[C66xx_0] Got reply: \"%s\"\n", shared->buffer);
}

void handleCore1() {
    CACHE_invL1d((void*)shared, sizeof(SharedPacket), CACHE_WAIT);
    if (shared->flag != 0) {
        uint32_t msgId = shared->flag & 0xFFFF;
        printf("[C66xx_1] Got msg %u: \"%s\"\n", msgId, shared->buffer);
        snprintf((char*)shared->buffer, BUFFER_SIZE, "CORE1 ACK: msg %u", msgId);
        shared->size = strlen((char*)shared->buffer);
        shared->flag = 0;
        CACHE_wbL1d((void*)shared, sizeof(SharedPacket), CACHE_WAIT);
    }
}
uint32_t coreNum,cnt1,cnt2;
// --- Main boot+IPC entry point for all cores ---
void main(void)
{
    coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);
    uint32_t count = 0;
    uint32_t core;
    char boot_msg[80];
    if (coreNum == 0)
    {
        /* Unlock the chip registers */
        DEVICE_REG32_W(KICK0, 0x83e70b13);
        DEVICE_REG32_W(KICK1, 0x95a4f1e0);
        platform_delay(1);
        DEVICE_REG32_W(0x118ffffc, BOOT_MAGIC_NUMBER);

        /* Writing the entry address to other cores */
         for (core = 1; core < NUMBER_OF_CORES; core++)
         {
             sprintf(boot_msg, "\r\n\r\nBooting Hello World image on Core %d from Core 0 ...", core);
             printf("%s\n",boot_msg);
             DEVICE_REG32_W(BOOT_MAGIC_ADDR(core), (uint32_t)write_boot_magic_number);
             /* Delay 1 sec */
             platform_delay(1);
         }
         for (core = 1; core < NUMBER_OF_CORES; core++)
         {
             /* IPC interrupt other cores */
             DEVICE_REG32_W(IPCGR(core), 1);
             platform_delay(1000);
         }

        // Core0: Boot sequence for Core1, then enter IPC test
        platform_uart_init();
        platform_uart_set_baudrate(BOOT_UART_BAUDRATE);
        printf("\r\n[Core0] Dual-core Boot+IPC Example (C6657)\r\n");

        // Unlock chip registers
//        *(volatile uint32_t*)KICK0 = 0x83e70b13;
//        *(volatile uint32_t*)KICK1 = 0x95a4f1e0;

        // Boot Core1
        printf("[Core0] Booting Core1...\r\n");
//        *(volatile uint32_t*)BOOT_MAGIC_ADDR(1) = (uint32_t)write_boot_magic_number;
//        platform_delay(1);
//        *(volatile uint32_t*)IPCGR(1) = 1;
//        platform_delay(100); // Wait a bit for Core1 startup

        // Begin shared memory IPC test
        printf("[Core0] Starting IPC handshake...\r\n");
        while (1) {
            sendFromCore0(count);
            waitReplyCore0();
            count++;
            cnt1++;
            // short_delay();
        }
    }
    else if (coreNum == 1)
    {
        // Core1: Boot entry ("write_boot_magic_number" from Core0), then run IPC responder
        // If RBL boot, first check/wait for magic
        volatile uint32_t *magic = (volatile uint32_t*)MAGIC_ADDR;
        if (*magic == BOOT_MAGIC_NUMBER) {
            printf("[Core1] Booted by Core0 (magic detected)\n");
            *magic = 0; // Clear boot magic for safety
        }
        else {
            printf("[Core1] Booting directly (no magic)\n");
        }
        printf("[C66xx_1] IPC responder loop...\n");
        while (1) {
            handleCore1();
            write_uart("hjid\n");
            cnt2++;
        }
    }
    else {
        // Not used for dual-core C6657, but placeholder for >2-core
        while (1);
    }
}
