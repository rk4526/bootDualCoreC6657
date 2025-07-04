/*
 * C6672_EMIF16_Registers_Define_HeaderFile.h
 *
 *  Created on: 2021. 4. 14.
 *      Author: user
 */

#ifndef REGISTERS_DEFINE_HEADERFILES_C6672_EMIF16_REGISTERS_DEFINE_HEADERFILE_H_
#define REGISTERS_DEFINE_HEADERFILES_C6672_EMIF16_REGISTERS_DEFINE_HEADERFILE_H_

// Start Address C6657·Î º¯°æ
#define C6672_EMIF16_Configuration_Start_Address        (0x20C00000)

// Revision Code and Status Register
#define C6672_EMIF16_RCSR_Address_Offset                (0x0000)
#define C6672_EMIF16_RCSR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_RCSR_Address_Offset)

// Async Wait Cycle Config Register
#define C6672_EMIF16_AWCCR_Address_Offset               (0x0004)
#define C6672_EMIF16_AWCCR_Register_Address             (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_AWCCR_Address_Offset)

// Async 1 Config Register
#define C6672_EMIF16_A1CR_Address_Offset                (0x0010)
#define C6672_EMIF16_A1CR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_A1CR_Address_Offset)

// Async 2 Config Register
#define C6672_EMIF16_A2CR_Address_Offset                (0x0014)
#define C6672_EMIF16_A2CR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_A2CR_Address_Offset)

// Async 3 Config Register
#define C6672_EMIF16_A3CR_Address_Offset                (0x0018)
#define C6672_EMIF16_A3CR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_A3CR_Address_Offset)

// Async 4 Config Register
#define C6672_EMIF16_A4CR_Address_Offset                (0x001C)
#define C6672_EMIF16_A4CR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_A4CR_Address_Offset)

// Interrupt Raw Register
#define C6672_EMIF16_IRR_Address_Offset                 (0x0040)
#define C6672_EMIF16_IRR_Register_Address               (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_IRR_Address_Offset)

// Interrupt Masked Register
#define C6672_EMIF16_IMR_Address_Offset                 (0x0044)
#define C6672_EMIF16_IMR_Register_Address               (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_IMR_Address_Offset)

// Interrupt Mask Set Register
#define C6672_EMIF16_IMSR_Address_Offset                (0x0048)
#define C6672_EMIF16_IMSR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_IMSR_Address_Offset)

// Interrupt Mask Clear Register
#define C6672_EMIF16_IMCR_Address_Offset                (0x004C)
#define C6672_EMIF16_IMCR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_IMCR_Address_Offset)

// NAND Flash Control Register
#define C6672_EMIF16_NANDFCR_Address_Offset             (0x0060)
#define C6672_EMIF16_NANDFCR_Register_Address           (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFCR_Address_Offset)

// NAND Flash Status Register
#define C6672_EMIF16_NANDFSR_Address_Offset             (0x0064)
#define C6672_EMIF16_NANDFSR_Register_Address           (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFSR_Address_Offset)

// Page Mode Control Register
#define C6672_EMIF16_PMCR_Address_Offset                (0x0068)
#define C6672_EMIF16_PMCR_Register_Address              (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_PMCR_Address_Offset)

// NAND Flash CS2 (CE0) 1-Bit ECC Register
#define C6672_EMIF16_NFECCCS2_Address_Offset            (0x0070)
#define C6672_EMIF16_NFECCCS2_Register_Address          (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NFECCCS2_Address_Offset)

// NAND Flash CS3 (CE1) 1-Bit ECC Register
#define C6672_EMIF16_NFECCCS3_Address_Offset            (0x0074)
#define C6672_EMIF16_NFECCCS3_Register_Address          (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NFECCCS3_Address_Offset)

// NAND Flash CS4 (CE2) 1-Bit ECC Register
#define C6672_EMIF16_NFECCCS4_Address_Offset            (0x0078)
#define C6672_EMIF16_NFECCCS4_Register_Address          (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NFECCCS4_Address_Offset)

// NAND Flash CS5 (CE3) 1-Bit ECC Register
#define C6672_EMIF16_NFECCCS5_Address_Offset            (0x007C)
#define C6672_EMIF16_NFECCCS5_Register_Address          (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NFECCCS5_Address_Offset)

// NAND Flash 4-Bit ECC Load Register
#define C6672_EMIF16_NANDF4BECCLR_Address_Offset        (0x00BC)
#define C6672_EMIF16_NANDF4BECCLR_Register_Address      (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDF4BECCLR_Address_Offset)

// NAND Flash 4-Bit ECC 1 Register
#define C6672_EMIF16_NANDF4BECC1R_Address_Offset        (0x00C0)
#define C6672_EMIF16_NANDF4BECC1R_Register_Address      (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDF4BECC1R_Address_Offset)

// NAND Flash 4-Bit ECC 2 Register
#define C6672_EMIF16_NANDF4BECC2R_Address_Offset        (0x00C4)
#define C6672_EMIF16_NANDF4BECC2R_Register_Address      (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDF4BECC2R_Address_Offset)

// NAND Flash 4-Bit ECC 3 Register
#define C6672_EMIF16_NANDF4BECC3R_Address_Offset        (0x00C8)
#define C6672_EMIF16_NANDF4BECC3R_Register_Address      (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDF4BECC3R_Address_Offset)

// NAND Flash 4-Bit ECC 4 Register
#define C6672_EMIF16_NANDF4BECC4R_Address_Offset        (0x00CC)
#define C6672_EMIF16_NANDF4BECC4R_Register_Address      (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDF4BECC4R_Address_Offset)

// NAND Flash Error Address 1 Register
#define C6672_EMIF16_NANDFEA1R_Address_Offset           (0x00D0)
#define C6672_EMIF16_NANDFEA1R_Register_Address         (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFEA1R_Address_Offset)

// NAND Flash Error Address 2 Register
#define C6672_EMIF16_NANDFEA2R_Address_Offset           (0x00D4)
#define C6672_EMIF16_NANDFEA2R_Register_Address         (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFEA2R_Address_Offset)

// NAND Flash Error Value 1 Register
#define C6672_EMIF16_NANDFEV1R_Address_Offset           (0x00D8)
#define C6672_EMIF16_NANDFEV1R_Register_Address         (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFEV1R_Address_Offset)

// NAND Flash Error Value 2 Register
#define C6672_EMIF16_NANDFEV2R_Address_Offset           (0x00DC)
#define C6672_EMIF16_NANDFEV2R_Register_Address         (C6672_EMIF16_Configuration_Start_Address + C6672_EMIF16_NANDFEV2R_Address_Offset)

#endif /* REGISTERS_DEFINE_HEADERFILES_C6672_EMIF16_REGISTERS_DEFINE_HEADERFILE_H_ */
