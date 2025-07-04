/*
 * User_Parameters_Define_HeaderFile.h
 *
 *  Created on: 2021. 3. 31.
 *      Author: user
 */

#ifndef USER_DEFINE_HEADERFILES_USER_PARAMETERS_DEFINE_HEADERFILE_H_
#define USER_DEFINE_HEADERFILES_USER_PARAMETERS_DEFINE_HEADERFILE_H_

#include "User_Define_HeaderFile.h"

/*******************************************************************************
*                              System Parameters
*******************************************************************************/



// #define APP_CODE_BINARY_IMAGE_FILE_NAME                 "D:\\software\\AltC_Project\\LSAM_TDD_DSP_Writter_Program_V1_00\\APP_Code.h"
#define APP_CODE_BINARY_IMAGE_FILE_NAME                 "..\\APP_Code.h"
#define __PROPGRAM_APP_CODE__

/*******************************************************************************
*                              For PLL Parameters
*******************************************************************************/
// +--------------------+---------------+--------+--------+
// | (CLK)Desired       | (CLKIN) Input |        |        |
// | Device Speed (MHz) | Clock (MHz)   | PLL1_M | PLL1_D |
// +--------------------+---------------+--------+--------+
// | 1000               | 100           | 19     | 0      |
// | 1000               | 100 (EVM)     | 39     | 1      |
// | 1250               | 100           | 24     | 0      |
// | 1000               | 50            | 39     | 1      |
// | 1000               | 156.25        | 63     | 4      |
// +--------------------+---------------+--------+--------+
//
// +--------------------+---------------+--------+--------+
// | DDR3 PLL VCO       | (CLKIN) Input |        |        |
// | Rate (MHz)         | Clock (MHz)   | PLL1_M | PLL1_D |
// +--------------------+---------------+--------+--------+
// | 1333               | 66.667 (EVM)  | 19     | 0      |
// | 1066               | 66.667        | 31     | 1      |
// | 800                | 66.667        | 11     | 0      |
// +--------------------+---------------+--------+--------+

// C6657 EVM으로 변경
/*
#define LSAM_TDD_Main_PLL_M            ((uInt32) (20 - 1))
#define LSAM_TDD_Main_PLL_D            ((uInt32) (1 - 1))
*/
#define LSAM_TDD_Main_PLL_M            (39)
#define LSAM_TDD_Main_PLL_D            (1)

#define LSAM_TDD_DDR3_PLL_M            ((uInt32) (40 - 1))
#define LSAM_TDD_DDR3_PLL_D            ((uInt32) (3 - 1))


#endif /* USER_DEFINE_HEADERFILES_USER_PARAMETERS_DEFINE_HEADERFILE_H_ */
