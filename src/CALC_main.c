/*
 * CALC_main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Lenovo
 */



/**************************************************************************************************************/
/*                                           STD_TYPES_LIB_INCLUDE                                           */
/************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

#include <stdlib.h>


/***************************************************************************************/
/*                          MCAL Lower Layer interface files                           */
/***************************************************************************************/
#include "MRCC_interface.h"     // Rcc included to enable GPIO Peripheral clock & to init system clock
#include "MGPIO_interface.h"
#include "SYS_interface.h"


/***************************************************************************************/
/*                          HAL Lower Layer interface files                            */
/***************************************************************************************/
//#include "SYS_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KPD_interface.h"


int main()
{
	u8 key;                                             // act as temp variable because key won't save the variable to store the data to be monitored on the screen.
	u8 NUM1[5];
	u8 NUM2[5];
	u8 count;
	u8 flag = 0;
	u8 operation;
	u16 res;
	u16 rr [5];

	MRCC_voidInitSystemCloak ();
	MRCC_voidEnablePeripheralCloak(AHB1, MRCC_PERIPHERIAL_EN_GPIOA);
	MRCC_voidEnablePeripheralCloak(AHB1, MRCC_PERIPHERIAL_EN_GPIOB);

	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN0,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN1,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN2,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN3,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN4,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN5,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN6,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN7,  MGPIO_PIN_OUTPUT);



	MGPIO_voidSetPinMode (MGPIO_PORTA, LCD_RS_PIN,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA, LCD_RW_PIN,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,LCD_E_PIN ,  MGPIO_PIN_OUTPUT);



	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN0 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN1 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN2 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN3 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN4 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN4, MGPIO_PIN_PULL_UP);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN5 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN5, MGPIO_PIN_PULL_UP);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN6 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN6, MGPIO_PIN_PULL_UP);

	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN7 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN7, MGPIO_PIN_PULL_UP);

	/* Init LCD */
	HLCD_vidInit();


	while (1)
	{
		key = KPD_u8GetPressedKey ();
		//HLCD_vidsendChar(key);                     // this action will result in infinity loop of printing
		if(key != NOT_PRESSED)
		{
			HLCD_vidsendChar(key);
			if((key == '+') || (key == '-') || (key == '/') || (key == '*'))
			{
				operation = key;
				count =0;
				flag = 1;

			}



			else if(key == '=')
			{
				flag = 0;

				switch (operation)
					{
						case '+':
							res = atoi (NUM1) + atoi(NUM2);
							itoa (res, rr, 10);
							HLCD_vidGoToXY(2 , 1);
							HLCD_vidWriteStr (rr);

							for (u8 i=0; i <5; i++)
							{
								NUM1[i]=0;


							}

							for (u8 i=0; i <5; i++)
							{

								NUM2 [i] =0;
							}





							break;

						case '-' :
							res = atoi (NUM1) - atoi(NUM2);
							itoa (res, rr, 10);
							HLCD_vidGoToXY(2 , 1);
							//if (atoi(NUM2)>atoi (NUM1))
							//{
								//HLCD_vidsendChar ('-');
								//HLCD_vidWriteStr (rr);
							//}                            // i think this is not true, i think i should think from the point of negative numbers that had been explained by saif
							//else
							//{
								HLCD_vidWriteStr (rr);
							//}



							for (u8 i=0; i <5; i++)
							{
								NUM1[i]=0;

							}

							for (u8 i=0; i <5; i++)
							{

								NUM2 [i] =0;
							}





							break;

						case '/' :
							res = atoi (NUM1) / atoi(NUM2);

							if (atoi(NUM2) == 0)
							{
								HLCD_vidGoToXY(2 , 1);
								HLCD_vidWriteStr ("Error!");
							}
							else
							{
								itoa (res, rr, 10);
								HLCD_vidGoToXY(2 , 1);
								HLCD_vidWriteStr (rr);
							}



							for (u8 i=0; i <5; i++)
							{
								NUM1[i]=0;

							}

							for (u8 i=0; i <5; i++)
							{

								NUM2 [i] =0;
							}





							break;

						case '*' :
							res = atoi (NUM1) * atoi(NUM2);
							itoa (res, rr, 10);
							HLCD_vidGoToXY(2 , 1);
							HLCD_vidWriteStr (rr);

							for (u8 i=0; i <5; i++)
							{
								NUM1[i]=0;

							}

							for (u8 i=0; i <5; i++)
							{

								NUM2 [i] =0;
							}




							break;

						default :
							// do nothing;
							break;

					}






			}
			else if (key == 'c')
			{
				 HLCD_vidsendCMD(LCD_CLR);

					for (u8 i=0; i <5; i++)
					{
						NUM1[i]=0;

					}

					for (u8 i=0; i <5; i++)
					{

						NUM2 [i] =0;
					}

					flag = 0;
					count =0;




			}
			else
			{
				if(flag == 0)
				{
					NUM1[count] = key;
					count++;

				}
				else
				{
					NUM2[count] = key;
					count++;
				}




			}




		}


	}




}



