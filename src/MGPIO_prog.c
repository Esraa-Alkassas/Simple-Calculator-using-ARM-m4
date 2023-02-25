/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 22/1/2023                                                           */
/* Description                     : MGPIO_programe.h  -> Function Implementations                           */
/* Module Features                 : 01- MGPIO_voidSetPinMode                               */
/*                                 : 02- MGPIO_voidSetOutputType                                 */
/*                                 : 03- MGPIO_voidSetOutputPinSpeed                                    */
/*                                 : 04- MGPIO_voidSetPinPullType                        */
/*                                 : 05- MGPIO_voidSetPinValue                       */
/*                                 : 06- MGPIO_voidGetPinValue                                  */
/*  Future Updates:  (we will do them on our owns)
 *                07- MGPIO_VoidSetPinLock
 *                08- MGPIO_VoidSetResetPin
 *                09- MGPIO_VoidSetPinAltf                                                 */
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
// #include "MRCC_interface.h"   he didn't include rcc here and i don't know why?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/***************************************************************************************/
/*                                    OWN Files                                        */
/***************************************************************************************/
#include "MGPIO_priv.h"
#include "MGPIO_config.h"
#include "MGPIO_interface.h"



/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/

/***************************************************************************************/
/*                                    1- MGPIO_voidSetPinMode                          */
/***************************************************************************************/
/* @fu MGPIO_voidSetPinMode                                                            */
/* @brief  This Function used to set Pin MODE                                          */
/*             - INPUT                                                                 */
/*             - OUTPUT                                                                */
/*             - ALTF                                                                  */
/*             - ANALOG                                                                */
/* @param[in] Copy_uddtPortNum : The port of the PIN                                   */
/*    [MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC ] Detect The Required Register          */
/* @param[in] Copy_uddtPinNum : the Pin Number                                         */
/*        [PIN0 : PIN15]                                                               */
/* @param[in] Copy_u8PinMode:The Pin Mode                                              */
/*     [MGPIO_PIN_INPUT - MGPIO_PIN_OUTPUT - MGPIO_PIN_ALTF - MGPIO_PIN_AnALOG]        */
/***************************************************************************************/
// as we used to do, we will say the same descriptin of the faunction in the interface file before the implementaion but i won't do that in the next functions for time consumig */

void MGPIO_voidSetPinMode (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PinMode)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PORTA:
		Clr_BITS(MGPIOA->MODER , 3<<(Copy_uddtPinNum * 2));
		MGPIOA->MODER |= (u32)(Copy_u8PinMode<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTB:
		Clr_BITS(MGPIOB->MODER , 3<<(Copy_uddtPinNum * 2));
		MGPIOB->MODER |= (u32)(Copy_u8PinMode<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTC:
		Clr_BITS(MGPIOC->MODER , 3<<(Copy_uddtPinNum * 2));
		MGPIOC->MODER |= (u32)(Copy_u8PinMode<< (Copy_uddtPinNum * 2));
		break;

	default:
		//return error
		break;
	}
}



/***************************************************************************************/
/*                              2- MGPIO_voidSetPinOutputType                          */
/***************************************************************************************/
// we should make a description about every API like that we did in the first API here but we won't do that for time consumption.
void MGPIO_voidSetPinOutputType (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, OutputType_t Copy_uddtPinOutputType)
{
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA:
		//Clr_BITS(MGPIOA->OTYPER , 1<<Copy_uddtPinNum );          he didn't write this line and i don't understand why ?!!!!!!!!!!!!!!!!!!!!!!!!!!!
		// he was wrong>>> we should put this line before we conduct oring >>>>>>>>>>>>>>>>>>>>>!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!take care & return this line in all functions here

		//CLR_BIT(MGPIO_PORTA , Copy_uddtPinNum);
		MGPIOA->OTYPER |= (u32) (Copy_uddtPinOutputType << Copy_uddtPinNum);
		break;

	case MGPIO_PORTB:
		//CLR_BIT(MGPIO_PORTB , Copy_uddtPinNum);
		MGPIOB->OTYPER |= (u32) (Copy_uddtPinOutputType << Copy_uddtPinNum);
		break;

	case MGPIO_PORTC:
		//CLR_BIT(MGPIO_PORTC , Copy_uddtPinNum);
		MGPIOC->OTYPER |= (u32) (Copy_uddtPinOutputType << Copy_uddtPinNum);
		break;

	default:
		//return error
		break;
	}
}



/***************************************************************************************/
/*                          03- MGPIO_voidSetOutputPinSpeed()                          */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinOutputSpeed (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, speed_t Copy_uddtPinOutputSpeed)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PORTA:
		Clr_BITS(MGPIOA->OSPEEDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOA->OSPEEDR |= (u32)(Copy_uddtPinOutputSpeed<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTB:
		Clr_BITS(MGPIOB->OSPEEDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOB->OSPEEDR |= (u32)(Copy_uddtPinOutputSpeed<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTC:
		Clr_BITS(MGPIOC->OSPEEDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOC->OSPEEDR |= (u32)(Copy_uddtPinOutputSpeed<< (Copy_uddtPinNum * 2));
		break;

	default:
		//return error
		break;
	}
}



/***************************************************************************************/
/*                          04- MGPIO_voidSetPinPullType                               */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinPullType (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PullType)
{
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA:
		Clr_BITS(MGPIOA->PUPDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOA->PUPDR |= (u32)(Copy_u8PullType<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTB:
		Clr_BITS(MGPIOB->PUPDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOB->PUPDR |= (u32)(Copy_u8PullType<< (Copy_uddtPinNum * 2));
		break;

	case MGPIO_PORTC:
		Clr_BITS(MGPIOC->PUPDR , 3<<(Copy_uddtPinNum * 2));
		MGPIOC->PUPDR |= (u32)(Copy_u8PullType<< (Copy_uddtPinNum * 2));
		break;

	default:
		//return error
		break;
	}
}




/***************************************************************************************/
/*                          05- MGPIO_voidGetPinValue()                               */
/*-------------------------------------------------------------------------------------*/
//void MGPIO_voidGetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8* Copy_pu8PinValue)
//{
//	switch(Copy_uddtPortNum)
//	{
//	case MGPIO_PORTA:
//		*Copy_pu8PinValue = GET_BIT(MGPIOA->IDR , Copy_uddtPinNum);
//		break;
//
//	case MGPIO_PORTB:
//		*Copy_pu8PinValue = GET_BIT(MGPIOB->IDR , Copy_uddtPinNum);
//		break;
//
//	case MGPIO_PORTC:
//		*Copy_pu8PinValue = GET_BIT(MGPIOC->IDR , Copy_uddtPinNum);
//		break;
//
//	default:
//		//return error
//		break;
//	}
//}
// i'm not sure about my implementation of the previous driver.... so  you will have to ask about it.................................................
u8 MGPIO_voidGetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum)
{
	u8 value = 0;
	switch(Copy_uddtPortNum)
	{
		case MGPIO_PORTA:
			value = GET_BIT(MGPIOA->IDR , Copy_uddtPinNum);
			break;

		case MGPIO_PORTB:
			value = GET_BIT(MGPIOB->IDR , Copy_uddtPinNum);
			break;

		case MGPIO_PORTC:
			value = GET_BIT(MGPIOC->IDR , Copy_uddtPinNum);
			break;

			default:
				//return error
				break;
	}
	return value;
}








/***************************************************************************************/
/*                          01- MGPIO_voidSetPinValue()                                */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PinValue)
{
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA:
		CLR_BIT(MGPIOA->ODR , Copy_uddtPinNum);
		//Clr_BITS(MGPIOA->ODR , 1<<Copy_uddtPinNum );
		MGPIOA->ODR |= (u32)(Copy_u8PinValue << Copy_uddtPinNum);
		break;

	case MGPIO_PORTB:
		CLR_BIT(MGPIOB->ODR , Copy_uddtPinNum);
		//Clr_BITS(MGPIOB->ODR , 1<<Copy_uddtPinNum );
		MGPIOB->ODR |= (u32)(Copy_u8PinValue << Copy_uddtPinNum);
		break;

	case MGPIO_PORTC:
		CLR_BIT(MGPIOC->ODR , Copy_uddtPinNum);
		//Clr_BITS(MGPIOC->ODR , 1<<Copy_uddtPinNum );
		MGPIOC->ODR |= (u32)(Copy_u8PinValue << Copy_uddtPinNum);
		break;

	default:
		//return error
		break;
	}
}


void MGPIO_voidSetPortValue (MGPIOx_t Copy_uddtPortNum, u8 Copy_u8PortValue)
{
	if(Copy_uddtPortNum <= MGPIO_PORTC)
	{
		switch (Copy_uddtPortNum)
		{
		case MGPIO_PORTA:
			MGPIOA->ODR = Copy_u8PortValue;
			break;

		case MGPIO_PORTB:
			MGPIOB->ODR =  Copy_u8PortValue;
			break;


		case MGPIO_PORTC:
			MGPIOC->ODR = Copy_u8PortValue;
			break;

		default:
			//return error
			break;


		}
	}


	else
	{
		// report error
	}






//	switch(Copy_uddtPortNum)
//	{
//	case MGPIO_PORTA:
//		Clr_ALL_BITS(MGPIOA->ODR);
//		MGPIOA->ODR |= (u32)(Copy_u8PortValue);
//		break;
//
//	case MGPIO_PORTB:
//		Clr_ALL_BITS(MGPIOB->ODR);
//		MGPIOB->ODR |= (u32)(Copy_u8PortValue);
//		break;
//
//	case MGPIO_PORTC:
//		Clr_ALL_BITS(MGPIOC->ODR);
//		MGPIOC->ODR |= (u32)(Copy_u8PortValue);
//		break;
//
//	default:
//		//return error
//		break;
//	}
}
