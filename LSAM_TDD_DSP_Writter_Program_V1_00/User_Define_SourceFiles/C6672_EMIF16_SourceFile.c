/*
 * C6672_EMIF16_SourceFile.c
 *
 *  Created on: 2021. 4. 19.
 *      Author: user
 */

#include "C6672_EMIF16_HeaderFile.h"

void C6672_EMIF_CONFIGURATION(void)
{
    uInt32 ui32_HW_Register = 0x0;

    /* RCSR
     *
     */

    /* AWCCCR
     * 7-0 bit[MAX_EXT_WAIT]:   Maximum extended wait cycles. EMIF16 will wait for (MAX_EXT_WAIT + 1) x 16 cycles before an extended asynchronous cycles is terminated.
     * 15-8 bit:                Reserved.
     * 17-16 bit[CS2_WAIT]:     WAIT map bits for CE0. 0x0: WAIT[0] is used, 0x0: WAIT[1] is used, 0x0: Reserved, 0x0: Reserved.
     * 19-18 bit[CS3_WAIT]:     WAIT map bits for CE1. 0x0: WAIT[0] is used, 0x0: WAIT[1] is used, 0x0: Reserved, 0x0: Reserved.
     * 17-16 bit[CS4_WAIT]:     WAIT map bits for CE2. 0x0: WAIT[0] is used, 0x0: WAIT[1] is used, 0x0: Reserved, 0x0: Reserved.
     * 17-16 bit[CS5_WAIT]:     WAIT map bits for CE3. 0x0: WAIT[0] is used, 0x0: WAIT[1] is used, 0x0: Reserved, 0x0: Reserved.
     * 27-24 bit:               Reserved.
     * 28 bit[WP0]:             Defines the wait polarity for WAIT[0]. 0x0: Wait if WAIT[0] is low, 0x1: Wait if WAIT[0] is high.
     * 29 bit[WP1]:             Defines the wait polarity for WAIT[1]. 0x0: Wait if WAIT[1] is low, 0x1: Wait if WAIT[1] is high.
     * 31-30 bit:               Reserved.
     */
    ui32_HW_Register =  0x0;
    ui32_HW_Register = (0x80 << 0) |        // MAX_EXT_WAIT (configure default)
                       (0x0 << 16) |        // CS2_WAIT
                       (0x0 << 18) |        // CS3_WAIT
                       (0x0 << 20) |        // CS4_WAIT
                       (0x0 << 22) |        // CS5_WAIT
                       (0x0 << 16) |        // CS2_WAIT
                       (0x0 << 28) |        // WP0
                       (0x0 << 29);         // WP1

    HW_Register_32bit(C6672_EMIF16_AWCCR_Register_Address);

    /* AnCR
     * 1-0 bit[ASIZE]:      Asynchronous Memory Size. 0h: 8-bit data bus, 1h: 16-bit data bus, 2h-3h: Reserved.
     * 3-2 bit[TA]:         Turn Around cycle. Number of EMIF16 clock cycles between the end of one asynchronous memory access and the start of another asynchronous memory access, minus one cycle.
     * 6-4 bit[R_HOLD]:     Read Strobe Hold cycle.
     * 12-7 bit[R_STROBE]:  Read Strobe Duration cycle.
     * 16-13 bit[R_SETUP]:  Read Strobe Setup cycles.
     * 19-17 bit[W_HOLD]:   Write Strobe Hold cycles.
     * 25-20 bit[W_STROBE]: Write Strobe Duration cycles.
     * 29-26 bit[W_SETUP]:  Write Strobe Setup cycles.
     * 30 bit[EW]:          Extended Wait Mode. 0h: Disable extended wait mode, 1h: Enable extended wait mode on WAIT pins.
     * 31 bit[SS]:          Select Strobe mode. 0h: Disable Select Strobe mode, 1h: Enable Select Strobe mode.
     */
    ui32_HW_Register =  0x0;
    /*
    ui32_HW_Register = ((0x1 & 0x3) << 0) |     // ASIZE
                       ((0x3 & 0x3) << 2) |     // TA
                       ((0x3 & 0x7) << 4) |     // R_HOLD
                       ((0xC & 0x3F) << 7) |    // R_STROBE
                       ((0x7 & 0xF) << 13) |    // R_SETUP
                       ((0x7 & 0x7) << 17) |    // W_HOLD
                       ((0x3F & 0x3F) << 20) |   // W_STROBE
                       ((0xF & 0xF) << 26) |    // W_SETUP
                       ((0x0 & 0x1) << 30) |    // EW
                       ((0x0 & 0x1) << 31);     // SS
    */
    ui32_HW_Register = ((0x1 & 0x3) << 0) |     // ASIZE
                           ((0x1 & 0x3) << 2) |     // TA
                           ((0x7 & 0x7) << 4) |     // R_HOLD
                           ((0x3F & 0x3F) << 7) |    // R_STROBE
                           ((0xF & 0xF) << 13) |    // R_SETUP
                           ((0x7 & 0x7) << 17) |    // W_HOLD
                           ((0x3F & 0x3F) << 20) |   // W_STROBE
                           ((0xF & 0xF) << 26) |    // W_SETUP
                           ((0x0 & 0x1) << 30) |    // EW
                           ((0x0 & 0x1) << 31);     // SS

    HW_Register_32bit(C6672_EMIF16_A1CR_Register_Address) = ui32_HW_Register;

    ui32_HW_Register =  0x0;
    ui32_HW_Register = ((0x1 & 0x3) << 0) |     // ASIZE
                           ((0x1 & 0x3) << 2) |     // TA
                           ((0x7 & 0x7) << 4) |     // R_HOLD
                           ((0x3F & 0x3F) << 7) |    // R_STROBE
                           ((0xF & 0xF) << 13) |    // R_SETUP
                           ((0x3 & 0x3) << 17) |    // W_HOLD
                           ((0x3F & 0x3F) << 20) |   // W_STROBE
                           ((0xF & 0xF) << 26) |    // W_SETUP
                           ((0x0 & 0x1) << 30) |    // EW
                           ((0x1 & 0x1) << 31);     // SS

    HW_Register_32bit(C6672_EMIF16_A2CR_Register_Address) = ui32_HW_Register;

    ui32_HW_Register =  0x0;
    ui32_HW_Register = ((0x1 & 0x3) << 0) |     // ASIZE
                           ((0x3 & 0x3) << 2) |     // TA
                           ((0x7 & 0x7) << 4) |     // R_HOLD
                           ((0x3F & 0x3F) << 7) |    // R_STROBE
                           ((0xF & 0xF) << 13) |    // R_SETUP
                           ((0x3 & 0x3) << 17) |    // W_HOLD
                           ((0x3F & 0x3F) << 20) |   // W_STROBE
                           ((0xF & 0xF) << 26) |    // W_SETUP
                           ((0x0 & 0x1) << 30) |    // EW
                           ((0x1 & 0x1) << 31);     // SS

    HW_Register_32bit(C6672_EMIF16_A3CR_Register_Address) = ui32_HW_Register;

    ui32_HW_Register =  0x0;
    ui32_HW_Register = ((0x1 & 0x3) << 0) |     // ASIZE
                           ((0x3 & 0x3) << 2) |     // TA
                           ((0x7 & 0x7) << 4) |     // R_HOLD
                           ((0x3F & 0x3F) << 7) |    // R_STROBE
                           ((0xF & 0xF) << 13) |    // R_SETUP
                           ((0x3 & 0x3) << 17) |    // W_HOLD
                           ((0x3F & 0x3F) << 20) |   // W_STROBE
                           ((0xF & 0xF) << 26) |    // W_SETUP
                           ((0x0 & 0x1) << 30) |    // EW
                           ((0x1 & 0x1) << 31);     // SS

    HW_Register_32bit(C6672_EMIF16_A4CR_Register_Address) = ui32_HW_Register;

    /* PMCR
     * 0 bit[CS2_PG_MD_EN]:     Page Mode enable for NOR Flash connected on CE0. 0h: Disable page mode, 1h: Use page mode.
     * 1 bit[CS2_PG_SIZE]:      Page Size for NOR Flash connected on CE0. 0h: 4 Word page, 1h: 8 Word page.
     * 7-2 bit[CS2_PG_DEL]:     Page access delay for NOR Flash connected CE0. This value must not be set to 0.
     * 8 bit[CS3_PG_MD_EN]:     Page Mode enable for NOR Flash connected on CE1. 0h: Disable page mode, 1h: Use page mode.
     * 9 bit[CS3_PG_SIZE]:      Page Size for NOR Flash connected on CE1. 0h: 4 Word page, 1h: 8 Word page.
     * 15-10 bit[CS3_PG_DEL]:   Page access delay for NOR Flash connected CE1. This value must not be set to 0.
     * 16 bit[CS4_PG_MD_EN]:    Page Mode enable for NOR Flash connected on CE2. 0h: Disable page mode, 1h: Use page mode.
     * 17 bit[CS4_PG_SIZE]:     Page Size for NOR Flash connected on CE2. 0h: 4 Word page, 1h: 8 Word page.
     * 23-18 bit[CS4_PG_DEL]:   Page access delay for NOR Flash connected CE2. This value must not be set to 0.
     * 24 bit[CS5_PG_MD_EN]:    Page Mode enable for NOR Flash connected on CE3. 0h: Disable page mode, 1h: Use page mode.
     * 25 bit[CS5_PG_SIZE]:     Page Size for NOR Flash connected on CE3. 0h: 4 Word page, 1h: 8 Word page.
     * 31-26 bit[CS5_PG_DEL]:   Page access delay for NOR Flash connected CE3. This value must not be set to 0.
     */
    ui32_HW_Register =  0x0;
    ui32_HW_Register = (0x0 << 0) |         // CS2_PG_MD_EN
                       (0x1 << 1) |         // CS2_PG_SIZE
                       (0x3F << 2) |        // CS2_PG_DEL
                       (0x1 << 8) |         // CS3_PG_MD_EN
                       (0x1 << 9) |         // CS3_PG_SIZE
                       (0x3F << 10) |       // CS3_PG_DEL
                       (0x1 << 16) |        // CS4_PG_MD_EN
                       (0x1 << 17) |        // CS4_PG_SIZE
                       (0x3F << 18) |       // CS4_PG_DEL
                       (0x1 << 24) |        // CS5_PG_MD_EN
                       (0x1 << 25) |        // CS5_PG_SIZE
                       (0x3F << 26);        // CS5_PG_DEL

    HW_Register_32bit(C6672_EMIF16_PMCR_Register_Address) = ui32_HW_Register;

}
