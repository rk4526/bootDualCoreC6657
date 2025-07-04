/*
 * C6672_PLL_Registers_Define_HeaderFile.h
 *
 *  Created on: 2021. 5. 3.
 *      Author: user
 */

#ifndef REGISTERS_DEFINE_HEADERFILES_C6672_PLL_REGISTERS_DEFINE_HEADERFILE_H_
#define REGISTERS_DEFINE_HEADERFILES_C6672_PLL_REGISTERS_DEFINE_HEADERFILE_H_

// Start Address C6657·Î º¯°æ
#define C6672_PLL_Controller_Start_Address              (0x02310000)

#define C6672_PLL_RSTYPE_Address_Offset                 (0x00E4)
#define C6672_PLL_RSTYPE_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_RSTYPE_Address_Offset)

#define C6672_PLL_RSCTRL_Address_Offset                 (0x00E8)
#define C6672_PLL_RSCTRL_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_RSCTRL_Address_Offset)

#define C6672_PLL_RSCFG_Address_Offset                  (0x00EC)
#define C6672_PLL_RSCFG_Register_Address                (C6672_PLL_Controller_Start_Address + C6672_PLL_RSCFG_Address_Offset)

#define C6672_PLL_RSISO_Address_Offset                  (0x00F0)
#define C6672_PLL_RSISO_Register_Address                (C6672_PLL_Controller_Start_Address + C6672_PLL_RSISO_Address_Offset)

#define C6672_PLL_PLLCTL_Address_Offset                 (0x0100)
#define C6672_PLL_PLLCTL_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLCTL_Address_Offset)

#define C6672_PLL_SECCTL_Address_Offset                 (0x0108)
#define C6672_PLL_SECCTL_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_SECCTL_Address_Offset)

#define C6672_PLL_PLLM_Address_Offset                   (0x0110)
#define C6672_PLL_PLLM_Register_Address                 (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLM_Address_Offset)

#define C6672_PLL_PLLDIV1_Address_Offset                (0x0118)
#define C6672_PLL_PLLDIV1_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV1_Address_Offset)

#define C6672_PLL_PLLDIV2_Address_Offset                (0x011C)
#define C6672_PLL_PLLDIV2_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV2_Address_Offset)

#define C6672_PLL_PLLDIV3_Address_Offset                (0x0120)
#define C6672_PLL_PLLDIV3_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV3_Address_Offset)

#define C6672_PLL_PLLCMD_Address_Offset                 (0x0138)
#define C6672_PLL_PLLCMD_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLCMD_Address_Offset)

#define C6672_PLL_PLLSTAT_Address_Offset                (0x013C)
#define C6672_PLL_PLLSTAT_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLSTAT_Address_Offset)

#define C6672_PLL_ALNCTL_Address_Offset                 (0x0140)
#define C6672_PLL_ALNCTL_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_ALNCTL_Address_Offset)

#define C6672_PLL_DCHANGE_Address_Offset                (0x0144)
#define C6672_PLL_DCHANGE_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_DCHANGE_Address_Offset)

#define C6672_PLL_SYSTAT_Address_Offset                 (0x0150)
#define C6672_PLL_SYSTAT_Register_Address               (C6672_PLL_Controller_Start_Address + C6672_PLL_SYSTAT_Address_Offset)

#define C6672_PLL_PLLDIV4_Address_Offset                (0x0160)
#define C6672_PLL_PLLDIV4_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV4_Address_Offset)

#define C6672_PLL_PLLDIV5_Address_Offset                (0x0164)
#define C6672_PLL_PLLDIV5_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV5_Address_Offset)

#define C6672_PLL_PLLDIV6_Address_Offset                (0x0168)
#define C6672_PLL_PLLDIV6_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV6_Address_Offset)

#define C6672_PLL_PLLDIV7_Address_Offset                (0x016C)
#define C6672_PLL_PLLDIV7_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV7_Address_Offset)

#define C6672_PLL_PLLDIV8_Address_Offset                (0x0170)
#define C6672_PLL_PLLDIV8_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV8_Address_Offset)

#define C6672_PLL_PLLDIV9_Address_Offset                (0x0174)
#define C6672_PLL_PLLDIV9_Register_Address              (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV9_Address_Offset)

#define C6672_PLL_PLLDIV10_Address_Offset               (0x0178)
#define C6672_PLL_PLLDIV10_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV10_Address_Offset)

#define C6672_PLL_PLLDIV11_Address_Offset               (0x017C)
#define C6672_PLL_PLLDIV11_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV11_Address_Offset)

#define C6672_PLL_PLLDIV12_Address_Offset               (0x0180)
#define C6672_PLL_PLLDIV12_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV12_Address_Offset)

#define C6672_PLL_PLLDIV13_Address_Offset               (0x0184)
#define C6672_PLL_PLLDIV13_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV13_Address_Offset)

#define C6672_PLL_PLLDIV14_Address_Offset               (0x0188)
#define C6672_PLL_PLLDIV14_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV14_Address_Offset)

#define C6672_PLL_PLLDIV15_Address_Offset               (0x018C)
#define C6672_PLL_PLLDIV15_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV15_Address_Offset)

#define C6672_PLL_PLLDIV16_Address_Offset               (0x0190)
#define C6672_PLL_PLLDIV16_Register_Address             (C6672_PLL_Controller_Start_Address + C6672_PLL_PLLDIV16_Address_Offset)


#endif /* REGISTERS_DEFINE_HEADERFILES_C6672_PLL_REGISTERS_DEFINE_HEADERFILE_H_ */
