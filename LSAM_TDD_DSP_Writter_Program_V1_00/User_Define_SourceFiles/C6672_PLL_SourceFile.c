/*
 * C6672_PLL_SourceFile.c
 *
 *  Created on: 2021. 5. 3.
 *      Author: user
 */

#include "C6672_PLL_HeaderFile.h"


void C6672_Main_PLL_Configuration(uInt32 PLL_M, uInt32 PLL_D)
{
    uInt32  Waiting_Counter = 0x0;
    uInt32  HW_Register     = 0x0;

    // 0. Unlock
    // (a) KICK0
    HW_Register_32bit(C6672_KICK0_Register_Address) = C6672_KICK0_Unlock_Code;
    // (b) KICK1
    HW_Register_32bit(C6672_KICK1_Register_Address) = C6672_KICK1_Unlock_Code;

    // 1. If executing this sequence immediately after device power-up, you must allow time for the PLL to become stable. PLL stabilization time is 100 us.
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x100)
    {
        Waiting_Counter++;
    }

    // 2. Check the status of BYPASS bit in SECCTL register, execute following steps if BYPASS == 1 (if bypass enabled), if BYPASS == 0 then Jump to Step 3.
    HW_Register = HW_Register_32bit(C6672_PLL_SECCTL_Register_Address);
    if( (HW_Register & (0x1 << 23)) == (0x1 << 23) )
    {
        // (a) In MAINPLLCTL1, write ENSAT = 0 (for optimal PLL operation)
        HW_Register_32bit(C6672_MAINPLLCTL1_Register_Address) &= (0x1 << 6);                            // MAINPLLCTL 6 bit: ENSAT. Must be set to 1 for proper operation of PLL.

        // (b) In PLLCTL, write PLLEN = 0 (bypass enabled in PLL Controller mux)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 0));                 // PLLCTL 0 bit: PLL enable bit. 0x0: Bypass mode, 0x1: PLL mode.

        // (c) In PLLCTL, write PLLENSRC = 0 (enable PLLEN to control PLL Controller mux)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 5));                 // PLLCTL 5 bit: PLL enable source bit. 0x0: PLLEN bit is enabled, 0x1:PLLEN bit is disabled.

        // (d) Wait 4 cycles of the reference clock CLKIN (to make sure the PLL Controller mux switches properly to the bypass)
        Waiting_Counter = 0x0;
        while(Waiting_Counter < 0x10)
        {
            Waiting_Counter++;
        }

        // (e) In SECCTL, write BYPASS = 1 (bypass enabled in PLL mux)
        HW_Register_32bit(C6672_PLL_SECCTL_Register_Address) |= (0x1 << 23);                                // SECCTL 23 bit: PLL Bypass Enable. 0x0: PLL Bypass disabled, 0x1: PLL Bypass enabled.

        // (f) In PLLCTL, write PLLPWRDN = 1 (power down the PLL)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) |= (0x1 << 1);                                 // PLLCTL 1 bit: PLL power-down mode select bit. 0x0: PLL is operational, 0x1: PLL is placed in a power-down state.

        // (g) Wait for at least 5 us based on the reference clock CLKIN (PLL power down toggling time)
        Waiting_Counter = 0x0;
        while(Waiting_Counter < 0x200)
        {
            Waiting_Counter++;
        }

        // (h) In PLLCTL, write PLLPWRDN = 0 (power up the PLL) => Jump to Step 4)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 1));                     // PLLCTL 1 bit: PLL power-down mode select bit. 0x0: PLL is operational, 0x1: PLL is placed in a power-down state.
    }
    else
    {
        // 3. Enable BYPASS in the PLL Controller
        // (a) In PLLCTL, write PLLEN = 0 (bypass enabled in PLL Controller mux)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 0));                     // PLLCTL 0 bit: PLL enable bit. 0x0: Bypass mode, 0x1: PLL mode.

        // (b) In PLLCTL, write PLLENSRC = 0 (enable PLLEN to control PLL controller mux)
        HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 5));                     // PLLCTL 5 bit: PLL enable source bit. 0x0: PLLEN bit is enabled, 0x1:PLLEN bit is disabled.

        // (c) Wait 4 cycles of the reference clock CLKIN (to make sure the PLL Controller mux switches properly to the bypass)
        Waiting_Counter = 0x0;
        while(Waiting_Counter < 0x10)
        {
            Waiting_Counter++;
        }
    }

    // 4. PLLM is split in two different registers. Program PLLM[5:0] in PLL multiplier control register (PLLM) and PLLM[12:6] in MAINPLLCTL0 register.
    HW_Register_32bit(C6672_PLL_PLLM_Register_Address)      &= ~((uInt32) 0x3F);                    // Clear
    HW_Register_32bit(C6672_PLL_PLLM_Register_Address)      |= ( (PLL_M & 0x3F) << 0 );             // Configure
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0x1FC0);                  // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ( (PLL_M & 0x1FC0) << 12 );            // Configure

    // 5. BWADJ is split in to different registers. Program BWADJ[7:0] in MAINPLLCTL0 and BWADJ[11:8] in MAINPLLCTL1 register. BWADJ[11:0] should be programmed to a value related to PLLM[12:0] value based on the equation: BWADJ = ((PLLM+1) >> 1) - 1.
    uInt32 BWADJ = ((PLL_M+1) >> 1) - 1;
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0xFF000000);              // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ((BWADJ & 0xFF) << 24);              // Configure
    HW_Register_32bit(C6672_MAINPLLCTL1_Register_Address)   &= ~((uInt32) 0xF);                     // Clear
    HW_Register_32bit(C6672_MAINPLLCTL1_Register_Address)   |= (((BWADJ & 0xF00) >> 8) << 0);       // Configure

    // 6. Program PLLD in MAINPLLCTL0 register
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0x3F);                    // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ((PLL_D & 0x3F) << 0);               // Configure

    // 7. In SECCTL, write OD (Output Divide) = 1 (that is divide-by-2)
    HW_Register_32bit(C6672_PLL_SECCTL_Register_Address)    |= (0x1 << 19);

    // 8. If necessary, program PLLDIVn.
    //    Do not re-program the PLLDIVn values if the PLL has previously been placed in PLL mode and is being re-programmed during this initialization.
    //    Note that you must apply the GO operation to change these dividers to a new ratios.

    // 9. In PLLCTL, write PLLRST = 1 (PLL reset is asserted)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address)    |= (0x1 << 3);                          // PLLCTL 3 bit: PLL reset bit. 0x1: PLL reset is released, 0x1: PLL reset is asserted.

    // 10. Wait for at least 7 us based on the reference clock CLKIN (PLL reset time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x100)
    {
        Waiting_Counter++;
    }

    // 11. In PLLCTL, write PLLRST = 0 (PLL reset is de-asserted)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address)    &= ~((uInt32) (0x1 << 3));             // PLLCTL 3 bit: PLL reset bit. 0x1: PLL reset is released, 0x1: PLL reset is asserted.

    // 12. Wait for at least 500 x CLKIN cycles x (PLLD + 1) (PLL lock time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x200)
    {
        Waiting_Counter++;
    }

    // 13. In SECCTL, write BYPASS = 0 (enable PLL mux to switch to PLL mode)
    HW_Register_32bit(C6672_PLL_SECCTL_Register_Address)    &= ~((uInt32) (0x1 << 23));             // SECCTL 23 bit: PLL Bypass Enable. 0x0: PLL Bypass disabled, 0x1: PLL Bypass enable.

    // 14. In PLLCTL, write PLLEN = 1 (enable PLL Controller mux to switch to PLL mode)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address)    |= (0x1 << 0);                          // PLLCTL 0 bit: PLL enable bit. 0x0: Bypass mode, 0x1: PLL mode.

    // 15. The PLL and PLL Controller are now initialized in PLL mode.

    // 0. Lock
    // (a) KICK0
    HW_Register_32bit(C6672_KICK0_Register_Address) = C6672_KICK0_Lock_Code;
    // (b) KICK1
    HW_Register_32bit(C6672_KICK1_Register_Address) = C6672_KICK1_Lock_Code;
}


void C6672_Main_PLL_Wake_Up(uInt32 PLL_M, uInt32 PLL_D)
{
    uInt32  Waiting_Counter = 0x0;

    // 1. In SECCTL, write BYPASS = 1 (bypass mode).
    HW_Register_32bit(C6672_PLL_SECCTL_Register_Address) |= (0x1 << 23);                // SECCTL 23 bit: PLL Bypass Enable. 0x0: PLL Bypass disabled, 0x1: PLL Bypass enabled.

    // 2. In PLLCTL, write PLLPWRDN = 0 to wake up the PLL
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 1));     // PLLCTL 1 bit: PLL power-down mode select bit. 0x0: PLL is operational, 0x1: PLL is placed in a power-down state.

    // 3. Follow the PLL reset sequence in Section 3.1.1 (step 3 to 9) to reset the PLL.
    // Wait for the PLL to lock and to switch from bypass to PLL mode.
    // (3) Enable BYPASS in the PLL Controller
    // (a) In PLLCTL, write PLLEN = 0 (bypass enabled in PLL Controller mux)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 0));     // PLLCTL 0 bit: PLL enable bit. 0x0: Bypass mode, 0x1: PLL mode.

    // (b) In PLLCTL, write PLLENSRC = 0 (enable PLLEN to control PLL controller mux)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address) &= ~((uInt32) (0x1 << 5));     // PLLCTL 5 bit: PLL enable source bit. 0x0: PLLEN bit is enabled, 0x1:PLLEN bit is disabled.

    // (c) Wait 4 cycles of the reference clock CLKIN (to make sure the PLL Controller mux switches properly to the bypass)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x100)
    {
        Waiting_Counter++;
    }

    // 4. PLLM is split in two different registers. Program PLLM[5:0] in PLL multiplier control register (PLLM) and PLLM[12:6] = in MAINPLLCTL0 register.
    HW_Register_32bit(C6672_PLL_PLLM_Register_Address)      &= ~((uInt32) 0x3F);                    // Clear
    HW_Register_32bit(C6672_PLL_PLLM_Register_Address)      |= ( (PLL_M & 0x3F) << 0 );             // Configure
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0x1FC0);                  // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ( (PLL_M & 0x1FC0) << 12 );            // Configure

    // 5. BWADJ is split in to different registers. Program BWADJ[7:0] in MAINPLLCTL0 and BWADJ[11:8] in MAINPLLCTL1 register. BWADJ[11:0] should be programmed to a value related to PLLM[12:0] value based on the equation: BWADJ = ((PLLM+1) >> 1) - 1.
    uInt32 BWADJ = ((PLL_M+1) >> 1) - 1;
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0xFF000000);              // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ((BWADJ & 0xFF) << 24);              // Configure
    HW_Register_32bit(C6672_MAINPLLCTL1_Register_Address)   &= ~((uInt32) 0xF);                     // Clear
    HW_Register_32bit(C6672_MAINPLLCTL1_Register_Address)   |= (((BWADJ & 0xF00) >> 8) << 0);       // Configure

    // 6. Program PLLD in MAINPLLCTL0 register
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   &= ~((uInt32) 0x3F);                    // Clear
    HW_Register_32bit(C6672_MAINPLLCTL0_Register_Address)   |= ((PLL_D & 0x3F) << 0);               // Configure

    // 7. In SECCTL, write OD (Output Divide) = 1 (that is divide-by-2)
    HW_Register_32bit(C6672_PLL_SECCTL_Register_Address)    |= (0x1 << 19);

    // 8. If necessary, program PLLDIVn.
    //    Do not re-program the PLLDIVn values if the PLL has previously been placed in PLL mode and is being re-programmed during this initialization.
    //    Note that you must apply the GO operation to change these dividers to a new ratios.

    // 9. In PLLCTL, write PLLRST = 1 (PLL reset is asserted)
    HW_Register_32bit(C6672_PLL_PLLCTL_Register_Address)    |= (0x1 << 3);                          // PLLCTL 3 bit: PLL reset bit. 0x1: PLL reset is released, 0x1: PLL reset is asserted.

    // 10. Wait for at least 7 us based on the reference clock CLKIN (PLL reset time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x200)
    {
        Waiting_Counter++;
    }
}



void C6672_DDR3_PLL_Confiugration(uInt32 PLL_M, uInt32 PLL_D)
{
    uInt32 Waiting_Counter = 0x0;

    // PLLOUT = DDRCLK(N|P) / PLLD * PLLM / 2 or PLLOUT = DDRCLK(N|P) when bypass mode
    // The Main PLL and PLL Controller must always be initialized prior to initializing the DDR3 PLL.
    // 1. In DDR3PLLCTL1, write ENSAT = 1 (for optimal PLL operation)
    HW_Register_32bit(C6672_DDR3PLLCTL1_Register_Address)       |= (0x1 << 6);                      // DDR3PLLCTL1 6 bit: Must be set to 1 for proper operation of PLL

    // 2. In DDR3PPLCTL0, write BYPASS = 1 (set the PLL in Bypass)
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       |= (0x1 << 23);                     // DDR3PLLCTL0 23 bit: Enable bypass mode. 0x0: Bypass disabled, 0x1: Bypass enabled.

    // 3. Program PLLM and PLLD in DDR3PLLCTL0 register
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       &= ~((uInt32) 0x3F);                // Clear
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       |= ((PLL_D & 0x3F) << 0);
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       &= ~((uInt32) 0x7FFC0);             // Clear
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       |= ((PLL_M & 0x1FFF) << 6);

    // 4. Program BWADJ[7:0] in DDR3PLLCTL0 and BWADJ[11:8] in the DDR3PLLCTL1 register.
    //    BWADJ[11:0] should be programmed to a value related to PLLM[12:0] value based on the equation:
    //    BWADJ = ((PLLM + 1) >> 1) -1
    uInt32 BWADJ = ((PLL_M + 1) >> 1) -1;
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       &= ~((uInt32) 0xFF000000);          // Clear
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       |= ((BWADJ & 0xFF) << 24);

    // 5. In DDR3PLLCTL1, write PLLRST = 1 (PLL is asserted)
    HW_Register_32bit(C6672_DDR3PLLCTL1_Register_Address)       |= (0x1 << 13);                     // DDR3PLLCTL1 13 bit: PLLRST reset bit. 0x0: PLL reset is released, 0x1: PLL reset is asserted.

    // 6. Wait for at least 5 us based on the reference clock (PLL reset time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x100)
    {
        Waiting_Counter++;
    }

    // 7. In DDR3PLLCTL1, write PLLTST = 0 (PLL reset is de-asserted)
    HW_Register_32bit(C6672_DDR3PLLCTL1_Register_Address)       &= ~((uInt32) (0x1 << 13));

    // 8. Wait for at least 500 * REFCLK cycle * (PLLD + 1) (PLL lock time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x200)
    {
        Waiting_Counter++;
    }

    // 9. In DDR3PLLCTL0, write BYPASS = 0 (switch to PLL mode)
    HW_Register_32bit(C6672_DDR3PLLCTL0_Register_Address)       &= ~((uInt32) (0x1 << 23));

    // 10. DDR PLL is now initialized.
}

/*
void C6672_PASS_PLL_Configuration(uInt32 PLL_M, uInt32 PLL_D)
{
    uInt32 Waiting_Counter = 0x0;
    // The Main PLL and PLL Controller must always be initialize prior to initializing the PASS PLL.
    // 1. In PASSPLLCTL1, write ENSAT = 1 (for optimal PLL operation)
    HW_Register_32bit(C6672_PASSPLLCTL1_Register_Address)       |= (0x1 << 6);                      // PASSPLLCTL1 6 bit: Must be set to 1 for proper operation of the PLL

    // 2. In PASSPLLCTL0, write BYPASS = 1 (set the PLL in Bypass)
    HW_Register_32bit(C6672_PASSPLLCTL0_Register_Address)       |= (0x1 << 23);                     // PASSPLLCTL0 23 bit: Enable bypass mode. 0x0: PLL reset is released, 0x1: PLL reset is asserted.

    // 3. Program PLLM and PLLD in the PASSPLLCTL0 register

    // 4. Program BWADJ[7:0] in PASPLLCTL0 and BWADJ[11:8] in the PASSPLLCTL1 register.
    //    BWADJ[11:0] should be programmed to a value related to PLLM[12:0] value based on the equation:
    //    BWADJ = ((PLLM + 1) >> 1) - 1.

    // 5. In PASSPLLCTL1, write PLLRST = 1 (PLL is asserted)

    // 6. Wait for at least 5 us based on the reference clock (PLL reset time)

    // 7. In PASSPLLCTL1, write PLLSELECT = 1 (for selecting the output of PASS PLL as the input to PASS)

    // 8. In PASSPLLCTL1, write PLLRST = 0 (PLL reset is de-asserted)

    // 9. Wait for at least 500 * REFCLK cycles * (PLLD + 1) (PLL lock time)
    Waiting_Counter = 0x0;
    while(Waiting_Counter < 0x200)
    {
        Waiting_Counter++;
    }

    // 10. In PASSPLLCTL0, write BYPASS = 0 (switch to PLL mode)

    // 11. PASS PLL is now initialized.
}
*/
