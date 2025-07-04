/*
 * C6672_PLL_HeaderFile.h
 *
 *  Created on: 2021. 5. 3.
 *      Author: user
 */

#ifndef USER_DEFINE_HEADERFILES_C6672_PLL_HEADERFILE_H_
#define USER_DEFINE_HEADERFILES_C6672_PLL_HEADERFILE_H_

#include "C6672_PLL_Registers_Define_HeaderFile.h"
#include "User_Define_HeaderFile.h"
#include "C6672_Device_State_Control_Registers_Define_HeaderFile.h"

#include <stdio.h>
#include <string.h>

/***********************************************************
*               DATA TYPES DEFINITION
************************************************************/
// PLLCTL
typedef enum {Bypass_Mode = 0x0, PLL_Mode = 0x1} PLLEN;
typedef enum {PLL_is_Operational = 0x0, PLL_is_Placed_in_a_Power_Down_State = 0x1} PLLPWRDN;
typedef enum {PLL_Reset_is_Released = 0x0, PLL_Reset_is_Asserted = 0x1} PLLRST;
typedef enum {PLLEN_Bit_is_Enabled = 0x0, PLLEN_Bit_is_Disabled = 0x1} PLLENSRC;

// SECCTL
typedef enum {PLL_Bypass_Diabled = 0x0, PLL_Bypass_Enabled = 0x1} BYPASS;

// PLLM
typedef enum {PLL_Multiplier_x1 = 0x0, PLL_Multiplier_x2 = 0x1, PLL_Multiplier_x3 = 0x2, PLL_Multiplier_x4 = 0x3, PLL_Multiplier_x5 = 0x4} PLLM;

// PLLDIV
typedef enum {Divider_n_is_Diabled = 0x0, Divider_n_is_Enable = 0x1} DnEN;

// PLLCMD
typedef enum {No_Effect = 0x0, Initiates_GO_Operation = 0x1} GOSET;

// PLLSTAT
typedef enum {GO_Opeartion_is_Not_in_Progress = 0x0, GO_Opeartion_is_in_Progress = 0x1} GOSTAT;

/***********************************************************
*               VARIABLES DEFINITION
************************************************************/
typedef struct C6672_PLL_PLLCTL_CONFIGURATION
{
    PLLEN               PLL_Enable_Bit;
    PLLPWRDN            PLL_Power_Down_Mode_Select_Bit;
    PLLRST              PLL_Reset_Bit;
    PLLENSRC            PLL_Enable_Source_Bit;
} C6672_PLL_PLLCTL_CONFIGURATION, *pC6672_PLL_PLLCTL_CONFIGURATION;


typedef struct C6672_PLL_SECCTL_CONFIGURATION
{
    uInt16              OUTPUT_DIVIDE;
    BYPASS              PLL_Bypass_Enable;
} C6672_PLL_SECCTL_CONFIGURATION, *pC6672_PLL_SECCTL_CONFIGURATION;


typedef struct C6672_PLL_PLLM_CONFIGURATION
{
    PLLM                PLL_Multiplier_Bit;
} C6672_PLL_PLLM_CONFIGURATION, *pC6672_PLL_PLLM_CONFIGURATION;


typedef struct C6672_PLL_PLLDIVn_CONFIGURATION
{
    uInt8               Divider_Ratio_Bits;
    DnEN                Divider_D_n_Enable_Bit;
} C6672_PLL_PLLDIVn_CONFIGURATION, *pC6672_PLL_PLLDIVn_CONFIGURATION;


typedef struct C6672_PLL_PLLCMD_CONFIGURATION
{
    GOSET               GO_Operation_Command;
} C6672_PLL_PLLCMD_CONFIGURATION, *pC6672_PLL_PLLCMD_CONFIGURATION;


/***********************************************************
 *              FUNCTIONS DEFINITION
 ***********************************************************/
void    C6672_Main_PLL_Configuration            (uInt32 PLL_M, uInt32 PLL_D);
void    C6672_Main_PLL_Wake_Up                  (uInt32 PLL_M, uInt32 PLL_D);
void    C6672_DDR3_PLL_Confiugration            (uInt32 PLL_M, uInt32 PLL_D);
// void    C6672_PASS_PLL_Configuration            (uInt32 PLL_M, uInt32 PLL_D);


#endif /* USER_DEFINE_HEADERFILES_C6672_PLL_HEADERFILE_H_ */
