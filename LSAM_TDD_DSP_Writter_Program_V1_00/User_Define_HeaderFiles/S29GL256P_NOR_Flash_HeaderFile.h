/*
 * S29GL256P_NOR_Flash_HeaderFile.h
 *
 *  Created on: 2021. 4. 20.
 *      Author: user
 */

#ifndef USER_DEFINE_HEADERFILES_S29GL256P_NOR_FLASH_HEADERFILE_H_
#define USER_DEFINE_HEADERFILES_S29GL256P_NOR_FLASH_HEADERFILE_H_

#include "User_Define_HeaderFile.h"

/***********************************************************
*               DATA TYPES DEFINITION
************************************************************/

#define __NOR_FLASH_ADDRESS_SHIFT__
// #define __Using_Address_Align_Macro__

#ifdef __Using_Address_Align_Macro__
#define SECTOR_START(address) (address & 0xFFFF0000)
#define SECTOR_ADDRESS(sector) ((((sector) << 17) & 0xFFFF0000))
#define ALIGN(a) (a & 0xFFFFFFFE)
#define DELAY(n) for(z=0;z<n*60000;z++);
#endif

#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    #define S29GL256P_NOR_Flash_Unlock_Cycle_1_Offset_Address           (0x555 << 1)
    #define S29GL256P_NOR_Flash_Unlock_Cycle_2_Offset_Address           (0x2AA << 1)
    #define S29GL256P_NOR_Flash_Autoselect_Command_offset_Address       (0x555 << 1)
    #define S29GL256P_NOR_Flash_Read_Manufacturer_ID_Offset_Address     (0x000 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Offset_Address    (0x00E << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Offset_Address    (0x00F << 1)
    #define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Offset_Address  (0x000 << 1)
    #define S29GL256P_NOR_Flash_Program_Setup_Offset_Address            (0x555 << 1)
    #define S29GL256P_NOR_Flash_Setup_Command_Offset_Address            (0x555 << 1)
    #define S29GL256P_NOR_Flash_Chip_Erase_Command_Offset_Address       (0x555 << 1)
#else
#ifdef __Using_Address_Align_Macro__
/*
    #define S29GL256P_NOR_Flash_Unlock_Cycle_1_Offset_Address           (ALIGN(0x555))
    #define S29GL256P_NOR_Flash_Unlock_Cycle_2_Offset_Address           (ALIGN(0x2AA))
    #define S29GL256P_NOR_Flash_Autoselect_Command_offset_Address       (ALIGN(0x555))
    #define S29GL256P_NOR_Flash_Read_Manufacturer_ID_Offset_Address     (ALIGN(0x000))
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (ALIGN(0x001))
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (ALIGN(0x001))
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Offset_Address    (ALIGN(0x00E))
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Offset_Address    (ALIGN(0x00F))
    #define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Offset_Address  (ALIGN(0x000))
    #define S29GL256P_NOR_Flash_Program_Setup_Offset_Address            (ALIGN(0x555))
    #define S29GL256P_NOR_Flash_Setup_Command_Offset_Address            (ALIGN(0x555))
    #define S29GL256P_NOR_Flash_Chip_Erase_Command_Offset_Address       (ALIGN(0x555))
    */
    #define S29GL256P_NOR_Flash_Unlock_Cycle_1_Offset_Address           (0x555 << 1)
    #define S29GL256P_NOR_Flash_Unlock_Cycle_2_Offset_Address           (0x2AA << 1)
    #define S29GL256P_NOR_Flash_Autoselect_Command_offset_Address       (0x555 << 1)
    #define S29GL256P_NOR_Flash_Read_Manufacturer_ID_Offset_Address     (0x000 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001 << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Offset_Address    (0x00E << 1)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Offset_Address    (0x00F << 1)
    #define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Offset_Address  (0x000 << 1)
    #define S29GL256P_NOR_Flash_Program_Setup_Offset_Address            (0x555 << 1)
    #define S29GL256P_NOR_Flash_Setup_Command_Offset_Address            (0x555 << 1)
    #define S29GL256P_NOR_Flash_Chip_Erase_Command_Offset_Address       (0x555 << 1)
#else
    #define S29GL256P_NOR_Flash_Unlock_Cycle_1_Offset_Address           (0x555)
    #define S29GL256P_NOR_Flash_Unlock_Cycle_2_Offset_Address           (0x2AA)
    #define S29GL256P_NOR_Flash_Autoselect_Command_offset_Address       (0x555)
    #define S29GL256P_NOR_Flash_Read_Manufacturer_ID_Offset_Address     (0x000)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address    (0x001)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Offset_Address    (0x00E)
    #define S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Offset_Address    (0x00F)
    #define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Offset_Address  (0x000)
    #define S29GL256P_NOR_Flash_Program_Setup_Offset_Address            (0x555)
    #define S29GL256P_NOR_Flash_Setup_Command_Offset_Address            (0x555)
    #define S29GL256P_NOR_Flash_Chip_Erase_Command_Offset_Address       (0x555)
#endif
#endif

/* Address offset */
#define S29GL256P_NOR_Flash_Unlock_Cycle_1_Address                  (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Unlock_Cycle_1_Offset_Address)
#define S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss                  (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Unlock_Cycle_2_Offset_Address)

// Autoselect
#define S29GL256P_NOR_Flash_Autoselect_Command_Address              (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Autoselect_Command_offset_Address)
#define S29GL256P_NOR_Flash_Read_Manufacturer_ID_Adress             (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Read_Manufacturer_ID_Offset_Address)
#define S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Address           (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Offset_Address)
#define S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Address           (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Offset_Address)
#define S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Address           (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Offset_Address)
#define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Address         (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Autoselect_Exit_Command_Offset_Address)

// Single Word Programming
#define S29GL256P_NOR_Flash_Program_Setup_Address                   (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Program_Setup_Offset_Address)
// Sector Erase

#define S29GL256P_NOR_Flash_Setup_Command_Address                   (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Setup_Command_Offset_Address)
// Chip Erase

#define S29GL256P_NOR_Flash_Chip_Erase_Command_Address              (C6672_EMIF16_CE0_Data_Space_Start_Address + S29GL256P_NOR_Flash_Chip_Erase_Command_Offset_Address)

/* Data */
#define S29GL256P_NOR_Flash_Unlock_Cycle_1_Data                     (0x00AA)
#define S29GL256P_NOR_Flash_Unlock_Cycle_2_Data                     (0x0055)
// Autoselect
#define S29GL256P_NOR_Flash_Autoselect_Command_Data                 (0x0090)
#define S29GL256P_NOR_Flash_Autoselect_Exit_Command_Data            (0x00F0)
// Single Word Programming
#define S29GL256P_NOR_Flash_Program_Setup_Data                      (0x00A0)
// Write Buffer Programming
#define S29GL256P_NOR_Flash_Write_Buffer_Command_Data               (0x0025)
#define S29GL256P_NOR_Flash_Write_Buffer_to_Flash_Data              (0x0029)
// Sector Erase
#define S29GL256P_NOR_Flash_Setup_Command_Data                      (0x0080)
#define S29GL256P_NOR_Flash_Sector_Erase_Command_Data               (0x0030)
// Chip Erase
#define S29GL256P_NOR_Flash_Chip_Erase_Command_Data                 (0x0010)
// Software Reset
#define S29GL256P_NOR_Flash_Software_Reset                          (0x00F0)

/***********************************************************
*               VARIABLE DEFINITIONS
************************************************************/
#define     C6672_EMIF16_CE0_Data_Space_Start_Address       (0x70000000)
#define     C6672_EMIF16_CE1_Data_Space_Start_Address       (0x74000000)
#define     C6672_EMIF16_CE2_Data_Space_Start_Address       (0x78000000)
#define     C6672_EMIF16_CE3_Data_Space_Start_Address       (0x7C000000)


/***********************************************************
 *              FUNCTION DEFINITIONS
 ***********************************************************/
inline void     Hold_On                                         (void);
uInt16          S29GL256P_NOR_Flash_Read_Manufacturer_ID        (void);
uInt16          S29GL256P_NOR_Flash_Read_Device_ID              (void);
BOOL            S29GL256P_NOR_Flash_Write_Word_Programming      (uInt32 Destination_Address, uInt16 Source_Data);
BOOL            S29GL256P_NOR_Flash_Sector_Erase                (uInt32 Sector_Start_Address);
BOOL            S29GL256P_NOR_Flash_Chip_Erase                  (void);
inline void     S29GL256P_NOR_Flash_Reset                       (void);


#endif /* USER_DEFINE_HEADERFILES_S29GL256P_NOR_FLASH_HEADERFILE_H_ */
