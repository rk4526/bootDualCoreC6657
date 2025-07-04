/*
 * @file User_Define_HeaderFile.h
 * @brief this header file is to define user defines
 * @data 2019-07-08(Modified) @n 2019-04-17(Created)
 * @author HanJin LEE(Modified) @n HanJin LEE(Created)
 * @version 0.10
 * @details
 * @see History
*/

#ifndef USER_DEFINE_HEADERFILE_H_
#define USER_DEFINE_HEADERFILE_H_

/***********************************************************
 *              MACROS DEFINITION
 ***********************************************************/
// If you want use printf function to indicate code state, use this #define __USING_PRINTF_FUNTION__
// #define __USING_PRINTF_FUNTION__

#define HW_Register_32bit(Register_Address)         (*((volatile unsigned int *)(Register_Address)))
#define HW_Register_16bit(Register_Address)         (*((volatile unsigned short *)(Register_Address)))
#define EMIF16_Address_Shift(Address)               (Address << 1)


/***********************************************************
 * 				UNITS DEFINITION
 ***********************************************************/
#define Unit_K				(1000)
#define Unit_M				(1000*1000)
#define Unit_G				(1000*1000*1000)
#define Unit_m				(0.001)
#define Unit_u				(0.001*0.001)
#define Unit_n				(0.001*0.001*0.001)
#define Unit_p				(0.001*0.001*0.001*0.001)


/***********************************************************
 * 				DATA TYPES DEFINITION
 ***********************************************************/
#define uInt8				unsigned char		// Define uint8 (8 bit = 1 byte)
#define uInt16				unsigned short		// Define unit16 (16 bit = 2 byte)
#define uInt32				unsigned int		// Define unint32 (32 bit = 4 byte)

typedef enum {BOOL_FALSE = 0, BOOL_TRUE = 1} 	BOOL;




/***********************************************************
 * 				FUNCTIONS DEFINITION
 ***********************************************************/
inline uInt32                 Waiting_Function        (uInt32 Waiting_Counter);


#endif /* USER_DEFINE_HEADERFILE_H_ */
