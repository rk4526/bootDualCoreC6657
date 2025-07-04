/*
 * Fixed linker command file for C6657 dual-core (no BIOS/SYS, no DDR3)
 * Core0: code/data/stack fits below 0x0087FFC0
 * Core1: startup code at 0x00880000 (L2SRAM_CORE1)
 * BOOT_MAGIC at end of L2SRAM, NO OVERLAP
 */


MEMORY
{
    // L2SRAM for Core0: 0x00800000 up to 0x0087FFC0 (512KB - 64B)
    L2SRAM     : origin = 0x00800000, length = 0x0007FFC0
    // L2SRAM for Core1: 0x00880000, reserve 32KB (or adjust as needed)
    L2SRAM_CORE1 : origin = 0x00880000, length = 0x00008000
    // MSMCSRAM (optional shared)
    MSMCSRAM   : origin = 0x0C000000, length = 0x00040000
    // BOOT_MAGIC: last 64 bytes of L2SRAM
    BOOT_MAGIC : origin = 0x0087FFC0, length = 0x00000040
}

SECTIONS
{
    // Core0 application sections
    .text      > L2SRAM
    .const     > L2SRAM
    .cinit     > L2SRAM
    .pinit     > L2SRAM
    .bss       > L2SRAM
    .data      > L2SRAM
    .stack     > L2SRAM
    .cio       > L2SRAM
    .switch    > L2SRAM

    // Core1 entry point section (must match C file's CODE_SECTION)
    .core1text > L2SRAM_CORE1

    // Magic address used for secondary core boot
    boot_magic > BOOT_MAGIC

    // Optionally shared buffer (for inter-core comm)
     .sharedBuf > MSMCSRAM
}

/*
-c
-heap  0x40000
-stack 0x10000

MEMORY
{
    L1PSRAM     (RWX) : org = 0x00E00000, len = 0x0007FFF
    L1DSRAM     (RWX) : org = 0x00F00000, len = 0x0007FFF
    L2SRAM      (RWX) : org = 0x1800000,  len = 0x080000
    L2SRAM_2    (RWX) : org = 0x11800000, len = 0x080000
    MSMCSRAM    (RWX) : org = 0x0c001000, len = 0x00FF000
    CORE1_FLASH (RX)  : org = 0x00880000, len = 0x00100000   /
}

SECTIONS
{
    .text      : load = CORE1_FLASH, run = MSMCSRAM,  LOAD_START(_core1_load_start), RUN_START(_core1_run_start), SIZE(_core1_size)
    .cinit     : load = CORE1_FLASH, run = MSMCSRAM
    .const     : load = CORE1_FLASH, run = MSMCSRAM
    .bss       : run = MSMCSRAM
    .data      : run = MSMCSRAM
    .neardata  : run = MSMCSRAM
    .rodata    : run = MSMCSRAM
    .stack     : run = MSMCSRAM
    .sysmem    : run = MSMCSRAM
    .init_array: run = MSMCSRAM
    .switch    : run = MSMCSRAM
    .pinit     : run = MSMCSRAM
    .cio       : run = MSMCSRAM
    .args      : run = MSMCSRAM align = 0x4, fill = 0 {_argsize = 0x200; }
    .csl_vect  : run = MSMCSRAM
    .sharedPacket ALIGN(4096): {} > MSMCSRAM
    .boot_load : run = MSMCSRAM
    platform_lib : run = MSMCSRAM
    xdc.meta   : run = MSMCSRAM, type = COPY
}
*/
