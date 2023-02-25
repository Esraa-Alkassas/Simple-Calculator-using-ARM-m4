/*
 * KPD_prog.c
 *
 *  Created on: Jan 27, 2023
 *      Author: Lenovo
 */



/**************************************************************************************************************/
/*                                           STD_TYPES_LIB_INCLUDE                                           */
/************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

/***************************************************************************************/
/*                           Lower Layer interface files                               */
/***************************************************************************************/
#include "MRCC_interface.h"
#include "SYS_interface.h"
#include "MGPIO_interface.h"

//#include "MGPIO_priv.h"

/***************************************************************************************/
/*                                    OWN Files                                        */
/***************************************************************************************/
#include "KPD_interface.h"
#include "KPD_priv.h"
#include "KPD_config.h"

/***************************************************************************************/
/*                                    Functions Implementation                          */
/***************************************************************************************/




static const u8 KPD_au8Array[4][4] =                 /*this is a two Darray,,, static to not be able to write extern in other files and use it,,, const because its values are fixedfor my design*/
{
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'c', '0', '=', '+'}
};


//u8* x;

u8 KPD_u8GetPressedKey (void)
{
	u8 u8SwVal = NOT_PRESSED;    /*because if we don't press any key, garbage value doesn't be returned*/
	u8 u8Col;
	u8 u8Row;

	for (u8Col = 0; u8Col<4; u8Col++)
	{
		MGPIO_voidSetPinValue (KPD_PORT, u8Col,  MGPIO_PIN_LOW);
		for (u8Row = 4; u8Row< 8; u8Row++)
		{
			//MGPIO_voidGetPinValue (KPD_PORT, u8Row,&x);
			//GET_BIT(MGPIOA->IDR , u8Row)
			if (MGPIO_voidGetPinValue (KPD_PORT, u8Row) ==MGPIO_PIN_LOW)
			{
				u8SwVal = KPD_au8Array [u8Row-4][u8Col];
				MSTK_voidDelay_ms(10);
				while (MGPIO_voidGetPinValue (KPD_PORT, u8Row) ==MGPIO_PIN_LOW);

			}
		}
		MGPIO_voidSetPinValue (KPD_PORT, u8Col,  MGPIO_PIN_HIGH);

	}

	return u8SwVal;
}




