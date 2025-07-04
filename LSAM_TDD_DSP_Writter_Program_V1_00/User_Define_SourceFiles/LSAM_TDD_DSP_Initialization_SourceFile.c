/*
 * LSAM_TDD_DSP_Initialization_SourceFile.c
 *
 *  Created on: 2021. 3. 31.
 *      Author: user
 */


#include "LSAM_TDD_DSP_Initialization_HeaderFile.h"


void LSAM_TDD_Initializatoin(void)
{
    // Configure PLL
    LSAM_TDD_PLL_Initialization();

    // Configure EMIF16
    C6672_EMIF_CONFIGURATION();

    // Configure FPGA EMIF16
    // LSAM_FPGA_EMIF16_Initialization();
}


void LSAM_TDD_PLL_Initialization(void)
{
    // Configure Main PLL
    C6672_Main_PLL_Configuration(LSAM_TDD_Main_PLL_M, LSAM_TDD_Main_PLL_D);

    // Configure DDR3 PLL
    C6672_DDR3_PLL_Confiugration(LSAM_TDD_DDR3_PLL_M, LSAM_TDD_DDR3_PLL_D);
}
