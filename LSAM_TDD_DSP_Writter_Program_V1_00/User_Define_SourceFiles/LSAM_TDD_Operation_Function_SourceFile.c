/*
 * LSAM_TDD_Operation_Function_SourceFile.c
 *
 *  Created on: 2021. 4. 12.
 *      Author: user
 */

#include "LSAM_TDD_Operation_Function_HeaderFile.h"


BOOL Write_NOR_Flash_App_Code(void)
{
    volatile uInt32     i                               = 0x0;
    volatile uInt32     Program_Counter                 = 0x0;
    volatile uInt32     Address_Counter                 = 0x0;
    volatile uInt32     Code_Size                       = 0x0;
    volatile uInt16     Code_MSB                        = 0x0;
    volatile uInt16     Code_LSB                        = 0x0;
    volatile uInt16     Word_Code                       = 0x0;
    volatile uInt8      Byte_Code                       = 0x0;
    BOOL                Write_Verification              = BOOL_FALSE;
    BOOL                Return_Value                    = BOOL_FALSE;
    Code_Size = sizeof(data_array) / sizeof(unsigned int);

    // Chip Eraser
    // S29GL256P_NOR_Flash_Chip_Erase();

    // Reset
    S29GL256P_NOR_Flash_Reset();

    // Program
    printf("##################### Program App Code Binary Image File to NOR Flash ############################ \n");

    Address_Counter = 0x0;
    for(Program_Counter = 0x0; Program_Counter < Code_Size; Program_Counter++)
    {
        Code_MSB = (uInt16) ((data_array[Program_Counter] & 0xFFFF0000) >> 16);
        Code_LSB = (uInt16) (data_array[Program_Counter] & 0x0000FFFF);

        if(Address_Counter == 0)
        {
            printf("INFO: %d Bytes Writting done(Total: %d Bytes).\r\n", Program_Counter, Code_Size);
            printf("\n##INFOR: Sector ( Number: %d ) is erased. \n", ((Address_Counter >> 16) & 0x0000FFFF));
            // If Write_Address is first of Sector Start Address, Execute sector erase
            S29GL256P_NOR_Flash_Sector_Erase(Address_Counter);

            // Hold on
            Hold_On();

            // Reset
            S29GL256P_NOR_Flash_Reset();

            // Hold on
            for(i = 0; i < 2000; i++)
            {
                Hold_On();
            }
        }
        else if(Address_Counter == (Address_Counter & 0xFFFF0000))
        {
            printf("INFO: %d Bytes Writting done(Total: %d Bytes).\r\n", Program_Counter, Code_Size);
            printf("\n##INFOR: Sector ( Number: %d ) is erased. \n", ((Address_Counter >> 16) & 0x0000FFFF));
            // If Write_Address is first of Sector Start Address, Execute sector erase
            S29GL256P_NOR_Flash_Sector_Erase(Address_Counter);

            // Hold on
            Hold_On();

            // Reset
            S29GL256P_NOR_Flash_Reset();
        }

        if(Program_Counter == 576)
        {
            printf("INFO: Entry point: 0x%04x%04x .\r\n", Code_MSB, Code_LSB);
        }

        if((Program_Counter % 1000) == 0)
        {
            printf("INFO: %d / %d .\r\n", Program_Counter, Code_Size);
        }

        // Write program
        Write_Verification = S29GL256P_NOR_Flash_Write_Word_Programming(Address_Counter, (uInt16) Code_LSB);
        Address_Counter++;

        Write_Verification = S29GL256P_NOR_Flash_Write_Word_Programming(Address_Counter, (uInt16) Code_MSB);
        Address_Counter++;


        if(Write_Verification == BOOL_FALSE)
        {
            printf("\n##ERROR: NOR Flash programming fail...\n");
            printf("##ERROR: Trial number: %d .\n", Program_Counter);

            return Return_Value;
        }

    }
    /*
     * For Test
     */
    /*
    FILE* fp = fopen("Verification_File.txt", "w");     // Text 파일 쓰기("w") 모드로 열기
    for(Program_Counter = 0x0; Program_Counter < Code_Size; Program_Counter++)
    {
        Code_LSB = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Program_Counter << 1));
        Program_Counter++;
        Code_MSB = (uInt16) HW_Register_16bit(C6672_EMIF16_CE0_Data_Space_Start_Address + (Program_Counter << 1));

        fprintf(fp, "0x%04x%04x,\n", Code_MSB, Code_LSB);
    }
    fclose(fp);     // 파일 포인터 닫기
    */

    // Reset
    S29GL256P_NOR_Flash_Reset();

    printf("##INFO: Boot file writting DONE...\r\n");
    printf("##################################################################################################\n");
    Return_Value = BOOL_TRUE;

    return Return_Value;
}



void LSAM_FPGA_EMIF16_Initialization(void)
{
    uInt32 FPGA_EMIF16_Address = 0x0;

    // Trigger_set(); // 적외선 / 지연 트리거 선택관련
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00003FF8);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x02;

    // Need 1us delay
    Waiting_Function(0x10000);

    // Trigger_set(); // 적외선 / 지연 트리거 선택관련
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00003FFA);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x00;

    // Need 1us delay
    Waiting_Function(0x10000);

    // Trigger_set(); // 적외선 / 지연 트리거 선택관련
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00003FF9);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x7D0;            // 0x7D0 = 2000

    // Need 1us delay
    Waiting_Function(0x10000);

    // adcReg_set
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002301);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x00;

    // Need 10us delay
    Waiting_Function(0xA0000);

    // adcReg_set(0x00,36,1500)
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002302);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x92;             // 0x24 = 36

    // Need 10us delay
    Waiting_Function(0xA0000);

    // adcReg_set(0x00,36,1500)
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002303);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x9C4;            // 0x5DC = 1500

    // Need 10us delay
    Waiting_Function(0xA0000);

    // fpga_adcMem_addReset(); // FPGA DPRAM address reset for adc data(i, q)
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002310);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 1us delay
    Waiting_Function(0x10000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 10us delay
    Waiting_Function(0xA0000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 1us delay
    Waiting_Function(0x10000);

    // adc_start(0); // adc_start_trg set(0: adc stop, 1: adc start)
    // adc_start(1); // adc_start_trg set(0: adc stop, 1: adc start)
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002304);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 20us delay
    Waiting_Function(0xB0000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 10us delay
    Waiting_Function(0xA0000);

    // sdlc_dataNum_set();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002546);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1E;             // 송신데이터 수 -1
    // Need 1us delay
    Waiting_Function(0x10000);

    // sdlc_dataNum_set();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002548);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0xE;             // 수신데이터 수 -1
    // Need 1us delay
    Waiting_Function(0x10000);

    // sdlc_rst();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002544);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 5us delay
    Waiting_Function(0x50000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    // sdlc_SFR_set();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002531);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    // sdlc_setting - sdlc_SFR_set
    // Need 5us delay
    Waiting_Function(0x50000);
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002534);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    // sdlc_SFR_set();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002536);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    // sdlc_SFR_write();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002540);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 5us delay
    Waiting_Function(0x50000);

    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 10ms delay
    Waiting_Function(0xA00000);

    // sdlc_tstate_write();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x0000253B);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0002;
    // Need 5us delay
    Waiting_Function(0xA0000);

    // sdlc_tstate_write();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002541);
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 100us delay
    Waiting_Function(0xA00000);

    // sdlc_rstate_write();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x0000253D);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0002;
    // Need 10us delay
    Waiting_Function(0xA0000);

    // sdlc_rstate_write();
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002543);
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 10us delay
    Waiting_Function(0xA0000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 10us delay
    Waiting_Function(0xA0000);

    // sdlc_intClr
    FPGA_EMIF16_Address                     = (uInt32) C6672_EMIF16_CE1_Data_Space_Start_Address + EMIF16_Address_Shift(0x00002545);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 5us delay
    Waiting_Function(0x50000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x1;
    // Need 5us delay
    Waiting_Function(0x50000);
    HW_Register_16bit(FPGA_EMIF16_Address)  = 0x0;
    // Need 1us delay
    Waiting_Function(0x10000);

}
