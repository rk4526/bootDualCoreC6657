/*
 * S29GL256P_NOR_Flash_SourceFile.c
 *
 *  Created on: 2021. 4. 20.
 *      Author: user
 */

#include "S29GL256P_NOR_Flash_HeaderFile.h"

inline void Hold_On(void)
{
    volatile uInt32  Hold_On_Counter = 0x0;

    while(Hold_On_Counter < 0x3000)
    {
        Hold_On_Counter++;
    }
}


uInt16 S29GL256P_NOR_Flash_Read_Manufacturer_ID(void)
{
    volatile uInt16  Manufacturer_ID = 0x0;

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)           = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;                  // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)           = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;                  // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Autoselect_Command_Address)       = (uInt16) S29GL256P_NOR_Flash_Autoselect_Command_Data;              // Write autoselect command

    Manufacturer_ID = HW_Register_16bit(S29GL256P_NOR_Flash_Read_Manufacturer_ID_Adress);                                               // Read manufacturer ID

    HW_Register_16bit(S29GL256P_NOR_Flash_Autoselect_Exit_Command_Address)   = (uInt16) S29GL256P_NOR_Flash_Autoselect_Exit_Command_Data;        // Exit autoselect

    // Reset
    S29GL256P_NOR_Flash_Reset();

    return Manufacturer_ID;
}



uInt16 S29GL256P_NOR_Flash_Read_Device_ID(void)
{
    volatile uInt16 Device_ID    = 0x0;
    // volatile uInt16 Temp         = 0x0;

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)           = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;                 // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)           = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;                 // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Autoselect_Command_Address)       = (uInt16) S29GL256P_NOR_Flash_Autoselect_Command_Data;             // Write autoselect command

    // Temp            = (uInt16) HW_Register_16bit(S29GL256P_NOR_Flash_Read_Device_ID_Word_1_Address);                                         // Read Device ID word 1
    Device_ID       = (uInt16) HW_Register_16bit(S29GL256P_NOR_Flash_Read_Device_ID_Word_2_Address);                                            // Read Device ID word 2
    // Temp            = (uInt16) HW_Register_16bit(S29GL256P_NOR_Flash_Read_Device_ID_Word_3_Address);                                         // Read Device ID word 3

    HW_Register_16bit(S29GL256P_NOR_Flash_Autoselect_Exit_Command_Address)   = (uInt16) S29GL256P_NOR_Flash_Autoselect_Exit_Command_Data;       // Exit autoselect

    // Reset
    S29GL256P_NOR_Flash_Reset();

    return Device_ID;
}


BOOL S29GL256P_NOR_Flash_Write_Word_Programming(uInt32 Destination_Address, uInt16 Source_Data)
{
    volatile BOOL   Return_Value    = BOOL_FALSE;
    uInt16          Read_Data       = 0x0;

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;     // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;     // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Program_Setup_Address)                                = (uInt16) S29GL256P_NOR_Flash_Program_Setup_Data;      // Write program setup command

#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Destination_Address << 1))   = (uInt16) Source_Data;                                // Write data to be programmed
#else
#ifdef __Using_Address_Align_Macro__
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ALIGN(Destination_Address))   = (uInt16) Source_Data;
#else
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + Destination_Address)   = (uInt16) *Source_Data;                                // Write data to be programmed
#endif
#endif

    Hold_On();

    // Reset
    S29GL256P_NOR_Flash_Reset();

#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Destination_Address << 1));
#else
#ifdef __Using_Address_Align_Macro__
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ALIGN(Destination_Address));
#else
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + Destination_Address);
#endif
#endif

    if(Read_Data == Source_Data)
    {
        Return_Value = BOOL_TRUE;
    }

    // Reset
    S29GL256P_NOR_Flash_Reset();

    return Return_Value;
}


BOOL S29GL256P_NOR_Flash_Sector_Erase(uInt32 Sector_Start_Address)
{
    volatile BOOL           Return_Value    = BOOL_FALSE;
    uInt16                  Read_Data       = 0x0;
    volatile uInt32         Address         = C6672_EMIF16_CE0_Data_Space_Start_Address + ((Sector_Start_Address << 1) & 0xFFFF0000);

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;                  // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;                  // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Program_Setup_Address)                                = (uInt16) S29GL256P_NOR_Flash_Setup_Command_Data;                   // Write program setup command

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;                  // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;                  // Write unlock cycle 2

#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ((Sector_Start_Address << 1) & 0xFFFF0000))  = (uInt16) S29GL256P_NOR_Flash_Sector_Erase_Command_Data;            // Write sector erase command
#else
#ifdef __Using_Address_Align_Macro__
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + SECTOR_START(Sector_Start_Address))  = (uInt16) S29GL256P_NOR_Flash_Sector_Erase_Command_Data;            // Write sector erase command
#else
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Sector_Start_Address & 0xFFFF0000))  = (uInt16) S29GL256P_NOR_Flash_Sector_Erase_Command_Data;                  // Write sector erase command
#endif
#endif

    Hold_On();

#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ((Sector_Start_Address << 1) & 0xFFFF0000));
#else
#ifdef __Using_Address_Align_Macro__
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + SECTOR_START(Sector_Start_Address));
#else
    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Sector_Start_Address & 0xFFFF0000));
#endif
#endif

    // Verification
#ifdef __NOR_FLASH_ADDRESS_SHIFT__
    if(Read_Data == 0xFFFF)
    {
        Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (((Sector_Start_Address << 1) & 0xFFFF0000) + 1));

        if(Read_Data == 0xFFFF)
        {
            Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (((Sector_Start_Address << 1) & 0xFFFF0000) + 2));

            if(Read_Data == 0xFFFF)
            {
                Return_Value = BOOL_TRUE;
            }
        }
    }
#else
#ifdef __Using_Address_Align_Macro__
    if(Read_Data == 0xFFFF)
    {
        Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (SECTOR_START(Sector_Start_Address) + 1));

        if(Read_Data == 0xFFFF)
        {
            Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (SECTOR_START(Sector_Start_Address) + 2));

            if(Read_Data == 0xFFFF)
            {
                Return_Value = BOOL_TRUE;
            }
        }
    }
#else
    if(Read_Data == 0xFFFF)
    {
        Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ((Sector_Start_Address & 0xFFFF0000) + 1));

        if(Read_Data == 0xFFFF)
        {
            Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + ((Sector_Start_Address & 0xFFFF0000) + 2));

            if(Read_Data == 0xFFFF)
            {
                Return_Value = BOOL_TRUE;
            }
        }
    }
#endif
#endif

    // Reset
    S29GL256P_NOR_Flash_Reset();

    return Return_Value;
}



BOOL S29GL256P_NOR_Flash_Chip_Erase(void)
{
    volatile BOOL   Return_Value    = BOOL_FALSE;
    uInt16          Read_Data       = 0x0;

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;               // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;               // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Program_Setup_Address)                                = (uInt16) S29GL256P_NOR_Flash_Setup_Command_Data;                // Write program setup command

    HW_Register_16bit(S29GL256P_NOR_Flash_Unlock_Cycle_1_Address)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_1_Data;               // Write unlock cycle 1
    HW_Register_16bit(S29GL256P_NOR_Flash_Unlcok_Cycle_2_Adderss)                               = (uInt16) S29GL256P_NOR_Flash_Unlock_Cycle_2_Data;               // Write unlock cycle 2
    HW_Register_16bit(S29GL256P_NOR_Flash_Chip_Erase_Command_Address)                           = (uInt16) S29GL256P_NOR_Flash_Chip_Erase_Command_Data;           // Write sector erase command

    Hold_On();

    S29GL256P_NOR_Flash_Reset();

    Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address);

    // Verification
    if(Read_Data == 0xFFFF)
    {
        Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (0x10 << 1));

        if(Read_Data == 0xFFFF)
        {
            Read_Data = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (0x20 << 1));

            if(Read_Data == 0xFFFF)
            {
                Return_Value = BOOL_TRUE;
            }
        }
    }

    // Reset
    S29GL256P_NOR_Flash_Reset();

    return Return_Value;
}



inline void S29GL256P_NOR_Flash_Reset(void)
{
    HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address) = (uInt16) S29GL256P_NOR_Flash_Software_Reset;      // Write software reset command

    Hold_On();
}
