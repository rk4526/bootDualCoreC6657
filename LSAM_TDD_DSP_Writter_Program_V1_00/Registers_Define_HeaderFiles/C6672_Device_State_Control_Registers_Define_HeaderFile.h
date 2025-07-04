/*
 * C6672_Device_State_Control_Registers_Define_HeaderFile.h
 *
 *  Created on: 2021. 3. 30.
 *      Author: user
 */

#ifndef REGISTERS_DEFINE_HEADERFILES_C6672_DEVICE_STATE_CONTROL_REGISTERS_DEFINE_HEADERFILE_H_
#define REGISTERS_DEFINE_HEADERFILES_C6672_DEVICE_STATE_CONTROL_REGISTERS_DEFINE_HEADERFILE_H_

/*******************************************************************************
*                       Registers Address DEFINITION
*******************************************************************************/
// Start Address C6657·Î º¯°æ
#define C6672_Chip_Level_Registers_Start_Address        (0x02620000)

#define C6672_JTAGID_Address_Offset                     (0x18)
#define C6672_JTAGID_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_JTAGID_Address_Offset)

#define C6672_DEVSTAT_Address_Offset                    (0x20)
#define C6672_DEVSTAT_Register_Address                  (C6672_Chip_Level_Registers_Start_Address + C6672_DEVSTAT_Address_Offset)

#define C6672_KICK0_Address_Offset                      (0x38)
#define C6672_KICK0_Register_Address                    (C6672_Chip_Level_Registers_Start_Address + C6672_KICK0_Address_Offset)

#define C6672_KICK1_Addresss_Offset                     (0x3C)
#define C6672_KICK1_Register_Address                    (C6672_Chip_Level_Registers_Start_Address + C6672_KICK1_Addresss_Offset)

#define C6672_DSP_BOOT_ADDR0_Address_Offset             (0x40)
#define C6672_DSP_BOOT_ADDR0_Register_Address           (C6672_Chip_Level_Registers_Start_Address + C6672_DSP_BOOT_ADDR0_Address_Offset)

#define C6672_DSP_BOOT_ADDR1_Address_Offset             (0x44)
#define C6672_DSP_BOOT_ADDR1_Register_Address           (C6672_Chip_Level_Registers_Start_Address + C6672_DSP_BOOT_ADDR1_Address_Offset)

#define C6672_MACID_Address_Offset                      (0x110)
#define C6672_MACID_Resgister_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_MACID_Address_Offset)

#define C6672_LRSTNMIPINSTAT_CLR_Address_Offset         (0x130)
#define C6672_LRSTNMIPINSTAT_CLR_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_LRSTNMIPINSTAT_CLR_Address_Offset)

#define C6672_RESET_STAT_CLR_Address_Offset             (0x134)
#define C6672_RESET_STAT_CLR_Register_Address           (C6672_Chip_Level_Registers_Start_Address + C6672_RESET_STAT_CLR_Address_Offset)

#define C6672_BOOTCOMPLETE_Address_Offset               (0x13C)
#define C6672_BOOTCOMPLETE_Register_Address             (C6672_Chip_Level_Registers_Start_Address + C6672_BOOTCOMPLETE_Address_Offset)

#define C6672_RESET_STAT_Address_Offset                 (0x114)
#define C6672_RESET_STAT_Register_Address               (C6672_Chip_Level_Registers_Start_Address + C6672_RESET_STAT_Address_Offset)

#define C6672_LRSTNMIPINSTAT_Address_Offset             (0x148)
#define C6672_LRSTNMIPINSTAT_Register_Address           (C6672_Chip_Level_Registers_Start_Address + C6672_LRSTNMIPINSTAT_Address_Offset)

#define C6672_DEVCFG_Address_Offset                     (0x14C)
#define C6672_DEVCFG_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_DEVCFG_Address_Offset)

#define C6672_PWRSTATECTL_Address_Offset                (0x150)
#define C6672_PWRSTATECTL_Register_Address              (C6672_Chip_Level_Registers_Start_Address + C6672_PWRSTATECTL_Address_Offset)

#define C6672_SRIO_SERDES_STS_Address_Offset            (0x154)
#define C6672_SRIO_SERDES_STS_Register_Address          (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_STS_Address_Offset)

#define C6672_SGMII_SERDES_STS_Address_Offset           (0x158)
#define C6672_SGMII_SERDES_STS_Register_Address         (C6672_Chip_Level_Registers_Start_Address + C6672_SGMII_SERDES_STS_Address_Offset)

#define C6672_PCIE_SERDES_STS_Address_Offset            (0x15C)
#define C6672_PCIE_SERDES_STS_Register_Address          (C6672_Chip_Level_Registers_Start_Address + C6672_PCIE_SERDES_STS_Address_Offset)

#define C6672_HYPERLINK_SERDES_STS_Address_Offset       (0x160)
#define C6672_HYPERLINK_SERDES_STS_Register_Address     (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_STS_Address_Offset)

#define C6672_UPP_CLOCK_Address_Offset                  (0x16C)
#define C6672_UPP_CLOCK_Register_Address                (C6672_Chip_Level_Registers_Start_Address + C6672_UPP_CLOCK_Address_Offset)

#define C6672_NMIGR0_Address_Offset                     (0x200)
#define C6672_NMIGR0_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_NMIGR0_Address_Offset)

#define C6672_NMIGR1_Address_Offset                     (0x204)
#define C6672_NMIGR1_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_NMIGR1_Address_Offset)

#define C6672_IPCGR0_Address_Offset                     (0x240)
#define C6672_IPCGR0_Reigster_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCGR0_Address_Offset)

#define C6672_IPCGR1_Address_Offset                     (0x244)
#define C6672_IPCGR1_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCGR1_Address_Offset)

#define C6672_IPCGRH_Address_Offset                     (0x27C)
#define C6672_IPCGRH_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCGRH_Address_Offset)

#define C6672_IPCAR0_Address_Offset                     (0x280)
#define C6672_IPCAR0_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCAR0_Address_Offset)

#define C6672_IPCAR1_Address_Offset                     (0x284)
#define C6672_IPCAR1_Reigster_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCAR1_Address_Offset)

#define C6672_IPCARH_Address_Offset                     (0x2BC)
#define C6672_IPCARH_Register_Address                   (C6672_Chip_Level_Registers_Start_Address + C6672_IPCARH_Address_Offset)

#define C6672_TINPSEL_Address_Offset                    (0x300)
#define C6672_TINPSEL_Register_Address                  (C6672_Chip_Level_Registers_Start_Address + C6672_TINPSEL_Address_Offset)

#define C6672_TOUTPSEL_Address_Offset                   (0x304)
#define C6672_TOUTPSEL_Register_Address                 (C6672_Chip_Level_Registers_Start_Address + C6672_TOUTPSEL_Address_Offset)

#define C6672_RSTMUX0_Address_Offset                    (0x308)
#define C6672_RSTMUX0_Reigster_Address                  (C6672_Chip_Level_Registers_Start_Address + C6672_RSTMUX0_Address_Offset)

#define C6672_RSTMUX1_Address_Offset                    (0x30C)
#define C6672_RSTMUX1_Register_Address                  (C6672_Chip_Level_Registers_Start_Address + C6672_RSTMUX1_Address_Offset)

#define C6672_MAINPLLCTL0_Address_Offset                (0x328)
#define C6672_MAINPLLCTL0_Register_Address              (C6672_Chip_Level_Registers_Start_Address + C6672_MAINPLLCTL0_Address_Offset)

#define C6672_MAINPLLCTL1_Address_Offset                (0x32C)
#define C6672_MAINPLLCTL1_Register_Address              (C6672_Chip_Level_Registers_Start_Address + C6672_MAINPLLCTL1_Address_Offset)

#define C6672_DDR3PLLCTL0_Address_Offset                (0x330)
#define C6672_DDR3PLLCTL0_Register_Address              (C6672_Chip_Level_Registers_Start_Address + C6672_DDR3PLLCTL0_Address_Offset)

#define C6672_DDR3PLLCTL1_Address_Offset                (0x334)
#define C6672_DDR3PLLCTL1_Register_Address              (C6672_Chip_Level_Registers_Start_Address + C6672_DDR3PLLCTL1_Address_Offset)

#define C6672_SGMII_SERDES_CFGPLL_Address_Offset        (0x340)
#define C6672_SGMII_SERDES_CFGPLL_Register_Address      (C6672_Chip_Level_Registers_Start_Address + C6672_SGMII_SERDES_CFGPLL_Address_Offset)

#define C6672_SGMII_SERDES_CFGRX0_Address_Offset        (0x344)
#define C6672_SGMII_SERDES_CFGRX0_Register_Address      (C6672_Chip_Level_Registers_Start_Address + C6672_SGMII_SERDES_CFGRX0_Address_Offset)

#define C6672_SGMII_SERDES_CFGTX0_Address_Offset        (0x348)
#define C6672_SGMII_SERDES_CFGTX0_Register_Address      (C6672_Chip_Level_Registers_Start_Address + C6672_SGMII_SERDES_CFGTX0_Address_Offset)

#define C6672_PCIE_SERDES_CFGPLL_Address_Offset         (0x358)
#define C6672_PCIE_SERDES_CFGPLL_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_PCIE_SERDES_CFGPLL_Address_Offset)

#define C6672_SRIO_SERDES_CFGPLL_Address_Offset         (0x360)
#define C6672_SRIO_SERDES_CFGPLL_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGPLL_Address_Offset)

#define C6672_SRIO_SERDES_CFGRX0_Address_Offset         (0x364)
#define C6672_SRIO_SERDES_CFGRX0_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGRX0_Address_Offset)

#define C6672_SRIO_SERDES_CFGTX0_Address_Offset         (0x368)
#define C6672_SRIO_SERDES_CFGTX0_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGTX0_Address_Offset)

#define C6672_SRIO_SERDES_CFGRX1_Address_Offset         (0x36C)
#define C6672_SRIO_SERDES_CFGRX1_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGRX1_Address_Offset)

#define C6672_SRIO_SERDES_CFGTX1_Address_Offset         (0x370)
#define C6672_SRIO_SERDES_CFGTX1_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGTX1_Address_Offset)

#define C6672_SRIO_SERDES_CFGRX2_Address_Offset         (0x374)
#define C6672_SRIO_SERDES_CFGRX2_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGRX2_Address_Offset)

#define C6672_SRIO_SERDES_CFGTX2_Address_Offset         (0x378)
#define C6672_SRIO_SERDES_CFGTX2_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGTX2_Address_Offset)

#define C6672_SRIO_SERDES_CFGRX3_Address_Offset         (0x37C)
#define C6672_SRIO_SERDES_CFGRX3_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGRX3_Address_Offset)

#define C6672_SRIO_SERDES_CFGTX3_Address_Offset         (0x380)
#define C6672_SRIO_SERDES_CFGTX3_Register_Address       (C6672_Chip_Level_Registers_Start_Address + C6672_SRIO_SERDES_CFGTX3_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGPLL_Address_Offset    (0x3B4)
#define C6672_HYPERLINK_SERDES_CFGPLL_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGPLL_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGRX0_Address_Offset    (0x3B8)
#define C6672_HYPERLINK_SERDES_CFGRX0_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGRX0_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGTX0_Address_Offset    (0x3BC)
#define C6672_HYPERLINK_SERDES_CFGTX0_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGTX0_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGRX1_Address_Offset    (0x3C0)
#define C6672_HYPERLINK_SERDES_CFGRX1_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGRX1_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGTX1_Address_Offset    (0x3C4)
#define C6672_HYPERLINK_SERDES_CFGTX1_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGTX1_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGRX2_Address_Offset    (0x3CB)
#define C6672_HYPERLINK_SERDES_CFGRX2_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGRX2_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGTX2_Address_Offset    (0x3CC)
#define C6672_HYPERLINK_SERDES_CFGTX2_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGTX2_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGRX3_Address_Offset    (0x3D0)
#define C6672_HYPERLINK_SERDES_CFGRX3_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGRX3_Address_Offset)

#define C6672_HYPERLINK_SERDES_CFGTX3_Address_Offset    (0x3D4)
#define C6672_HYPERLINK_SERDES_CFGTX3_Register_Address  (C6672_Chip_Level_Registers_Start_Address + C6672_HYPERLINK_SERDES_CFGTX3_Address_Offset)

#define C6672_DEVSPEED_Address_Offset                   (0x3F8)
#define C6672_DEVSPEED_Register_Address                 (C6672_Chip_Level_Registers_Start_Address + C6672_DEVSPEED_Address_Offset)

#define C6672_CHIP_MISC_CTL_Address_Offset              (0x400)
#define C6672_CHIP_MISC_CTL_Register_Address            (C6672_Chip_Level_Registers_Start_Address + C6672_CHIP_MISC_CTL_Address_Offset)


/***********************************************************
*               KICK UNLOCK CODE DEFINITION
************************************************************/
#define C6672_KICK0_Unlock_Code                         (0x83E70B13)
#define C6672_KICK1_Unlock_Code                         (0x95A4F1E0)

#define C6672_KICK0_Lock_Code                           (0x12345678)        // Any value except C6672_KICK0_Unlock_Code.
#define C6672_KICK1_Lock_Code                           (0x98765432)        // Any value except C6672_KICK1_Unlock_Code.


#endif /* REGISTERS_DEFINE_HEADERFILES_C6672_DEVICE_STATE_CONTROL_REGISTERS_DEFINE_HEADERFILE_H_ */
