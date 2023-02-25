/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 22/1/2023                                                           */

/*************************************************************************************************/


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

/***************************************************************************************/
/*                                    OWN Files                                        */
/***************************************************************************************/
#include "LCD_interface.h"
#include "LCD_priv.h"
#include "LCD_config.h"

/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/


void HLCD_vidInit ( void)
{
	MSTK_voidDelay_ms(100);
	HLCD_vidsendCMD(LCD_FUNCSET_8BIT);
	MSTK_voidDelay_ms(2);
	HLCD_vidsendCMD (LCD_DISPON_CURSOFF);
	MSTK_voidDelay_ms(2);
	HLCD_vidsendCMD (LCD_CLR);
	MSTK_voidDelay_ms(2);
	HLCD_vidsendCMD (LCD_ENTRYMODE);

}


void HLCD_vidsendCMD (u8 Copy_u8CMD)
{

	//CLEAR RS PIN
	MGPIO_voidSetPinValue (LCD_RS_PORT,LCD_RS_PIN, MGPIO_PIN_LOW);
	//CLEAR RW PIN
	MGPIO_voidSetPinValue (LCD_RW_PORT , LCD_RW_PIN, MGPIO_PIN_LOW);
	//LOAD THE COMMAND
	MGPIO_voidSetPortValue (LCD_DATA_PORT, Copy_u8CMD);
	//SET E PIN TO HIGH
	MGPIO_voidSetPinValue (LCD_E_PORT, LCD_E_PIN, MGPIO_PIN_HIGH);
	//delay
	MSTK_voidDelay_ms(1);
	//CLEAR E PIN
	MGPIO_voidSetPinValue (LCD_E_PORT, LCD_E_PIN, MGPIO_PIN_LOW);
}


void HLCD_vidsendChar (u8 Copy_u8Char)
{

	//SET RS PIN (data mode)
	MGPIO_voidSetPinValue (LCD_RS_PORT,LCD_RS_PIN, MGPIO_PIN_HIGH);
	//MSTK_voidDelay_ms(1);
	//clear RW PIN(Write mode)
	MGPIO_voidSetPinValue (LCD_RW_PORT , LCD_RW_PIN, MGPIO_PIN_LOW);
	//MSTK_voidDelay_ms(1);
	//LOAD THE COMMAND
	MGPIO_voidSetPortValue (LCD_DATA_PORT, Copy_u8Char);
	//SET E PIN TO HIGH
	MGPIO_voidSetPinValue (LCD_E_PORT, LCD_E_PIN, MGPIO_PIN_HIGH);

	MSTK_voidDelay_ms(1);
	//CLEAR E PIN
	MGPIO_voidSetPinValue (LCD_E_PORT, LCD_E_PIN, MGPIO_PIN_LOW);
}



void HLCD_vidWriteStr (u8* pu8str)
{
	u8 i =0;
	while (pu8str[i] != '\0')  /*or != 0 */
	{
		MSTK_voidDelay_ms(1);
		 HLCD_vidsendChar (pu8str[i]);
		 i++;
	}
}


//	u8 i = 0;
//	u8 flag = 0;
//	for(i=0;i<16;i++)
//	{
//
//		if(*(pu8str+i) == '\0')
//		{
//			flag = 1;
//			break;
//		}
//		else
//		{
//			MSTK_voidDelay_ms(2);
//			HLCD_vidsendChar(*(pu8str+i));
//			MSTK_voidDelay_ms(2);
//		}
//	}
//	//limitation of overwritting when you are already in second line
//	//LCD_vidSendCMD(LCD_SETCURSLINE2);
//	if(flag == 0){
//
//		HLCD_vidGoToXY(1, 0);
//
//	for(i=16;i<32;i++)
//		{
//
//			if(*(pu8str+i) == '\0')
//			{
//			break;
//			}
//			else
//			{
//				MSTK_voidDelay_ms(2);
//				HLCD_vidsendChar(*(pu8str+i));
//				MSTK_voidDelay_ms(2);
//			}
//		}
//	}
//
//}


//void HLCD_vidGoToXY(u8 x, u8 y)
//{
//	if (x==0)
//	{
//		HLCD_vidsendCMD (LCD_SETCURSOR+y );
//	}
//	else if (x==1)
//	{
//		HLCD_vidsendCMD(LCD_DISPON_CURSOFF+y);
//	}
//	else
//	{
//		//report error;
//	}
//
//}




	void HLCD_vidGoToXY(u8 x, u8 y)
	{
		if (y==0)
		{
			HLCD_vidsendCMD (x | LCD_SETCURSOR );
		}
		else if (y==1)
		{
			HLCD_vidsendCMD((x+0x40) | LCD_SETCURSOR );
		}
		else
		{
			return ;
		}
	}
