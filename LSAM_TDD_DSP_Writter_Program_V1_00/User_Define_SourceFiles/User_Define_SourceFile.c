/*
 * User_Define_SourceFile.c
 *
 *  Created on: 2021. 6. 1.
 *      Author: user
 */

#include "User_Define_HeaderFile.h"


inline uInt32 Waiting_Function(uInt32 Waiting_Counter)
{
    uInt32 Return_Value = Waiting_Counter;

    while(Return_Value > 0)
    {
        Return_Value--;
    }

    return Return_Value;
}
