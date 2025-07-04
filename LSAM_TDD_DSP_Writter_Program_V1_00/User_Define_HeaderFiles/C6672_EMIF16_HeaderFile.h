/*
 * C6672_EMIF16_HeaderFile.h
 *
 *  Created on: 2021. 4. 19.
 *      Author: user
 */

#ifndef USER_DEFINE_HEADERFILES_C6672_EMIF16_HEADERFILE_H_
#define USER_DEFINE_HEADERFILES_C6672_EMIF16_HEADERFILE_H_

#include "C6672_EMIF16_Registers_Define_HeaderFile.h"
#include "User_Define_HeaderFile.h"

/***********************************************************
*               DATA TYPES DEFINITION
************************************************************/
// AWCCR
typedef enum {WAIT_0_is_Used = 0x0, WAIT_1_is_Used = 0x1} CSn_WAIT;
typedef enum {Wait_if_WAIT_0_is_Low = 0x0, Wait_if_WAIT_1_is_High = 0x1} WP;

// AnCR
typedef enum {Data_Bus_8_Bit = 0x0, Data_Bus_16_Bit = 0x1} ASIZE;
typedef enum {Disable_Extended_Wait_Mode = 0x0, Enable_Extended_Wait_Mode_on_WAIT_Pins = 0x1} EW;
typedef enum {Disable_Select_Strobe_Mode = 0x0, Enable_Select_Strobe_Mode = 0x1} SS;

/***********************************************************
*               VARIABLE DEFINITIONS
************************************************************/
typedef struct C6672_EMIF_AWCCR_CONFIGURATION
{
    uInt8           MAX_EXT_WAIT;
    CSn_WAIT        CS2_WAIT;
    CSn_WAIT        CS3_WAIT;
    CSn_WAIT        CS4_WAIT;
    CSn_WAIT        CS5_WAIT;
    WP              WP0;
    WP              WP1;
} C6672_EMIF_AWCCR_CONFIGURATION, *pC6672_EMIF_AWCCR_CONFIGURATION;


typedef struct C6672_EMIF_AnCR_CONFIGURATOIN
{
    ASIZE           A_Size;
    uInt8           TA;
    uInt8           R_Hold;
    uInt8           R_Strobe;
    uInt8           R_Setup;
    uInt8           W_Hold;
    uInt8           W_Strobe;
    uInt8           W_Setup;
    EW              Extended_Wait_Mode;
    SS              Select_Strobe_Mode;
} C6672_EMIF_AnCR_CONFIGURATOIN, *pC6672_EMIF_AnCR_CONFIGURATOIN;


/***********************************************************
 *              FUNCTION DEFINITIONS
 ***********************************************************/
void    C6672_EMIF_CONFIGURATION            (void);


#endif /* USER_DEFINE_HEADERFILES_C6672_EMIF16_HEADERFILE_H_ */
