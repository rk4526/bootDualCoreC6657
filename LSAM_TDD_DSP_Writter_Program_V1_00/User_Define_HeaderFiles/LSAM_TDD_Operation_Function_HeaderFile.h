/*
 * LSAM_TDD_Operation_Function_HeaderFile.h
 *
 *  Created on: 2021. 4. 12.
 *      Author: user
 */

#ifndef USER_DEFINE_HEADERFILES_LSAM_TDD_OPERATION_FUNCTION_HEADERFILE_H_
#define USER_DEFINE_HEADERFILES_LSAM_TDD_OPERATION_FUNCTION_HEADERFILE_H_

#include <APP_Code.h>
#include "User_Define_HeaderFile.h"
#include "User_Parameters_Define_HeaderFile.h"
#include "S29GL256P_NOR_Flash_HeaderFile.h"

#include <stdio.h>
#include <string.h>

/***********************************************************
*               DATA TYPES DEFINITION
************************************************************/
#define     DDR3_EMIF16_for_App_Code_Start_Address          (0xA0000000)
#define     C6672_EMIF16_CE0_Data_Space_Start_Address       (0x70000000)
#define     C6672_EMIF16_CE1_Data_Space_Start_Address       (0x74000000)
#define     C6672_EMIF16_CE2_Data_Space_Start_Address       (0x78000000)
#define     C6672_EMIF16_CE3_Data_Space_Start_Address       (0x7C000000)

/***********************************************************
*               VARIABLE DEFINITIONS
************************************************************/


/***********************************************************
 *              FUNCTION DEFINITIONS
 ***********************************************************/
// NOR FLASH
BOOL                                    Write_NOR_Flash_App_Code        (void);

// FPGA EMIF16
void                                    LSAM_FPGA_EMIF16_Initialization (void);

#endif /* USER_DEFINE_HEADERFILES_LSAM_TDD_OPERATION_FUNCTION_HEADERFILE_H_ */
