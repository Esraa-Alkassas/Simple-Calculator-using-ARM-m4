/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 20/1/2023                                                           */
/* Description                     : MRCC_programe.c  -> Function Implementations                       */
/* Module Features                 : 01- MRCC_voidEnablePeripheralCloak                                */
/*                                 : 02- MRCC_voidDisablePeripheralCloak                              */
/*                                 : 03- MRCC_voidInitSystemCloak                                    */
/*                                 : 04- MRCC_voidEnableClockSecuritySystem                         */
/*                                 : 05- MRCC_voidDisableClockSecuritySystem                       */
/*                                 : 06- MRCC_voidSetSystemClock                                  */
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


/***************************************************************************************/
/*                                    OWN Files                                        */
/***************************************************************************************/


#include "MRCC_priv.h"
#include "MRCC_config.h"
#include "MRCC_interface.h"             // he included this file last.....why????????????????????????????????????????????????????????????


/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/

/***************************************************************************************/
/*                         01- MRCC_voidEnablePeripheralClock                          */
/***************************************************************************************/
void MRCC_voidEnablePeripheralCloak(BusName_t Copy_uddtBusName,u8 Copy_u8PerName)
{
	switch (Copy_uddtBusName)
	{
	case AHB1 :
		SET_BIT(MRCC_AHB1ENR, Copy_u8PerName);
		break;
	case AHB2 :
		SET_BIT(MRCC_AHB2ENR, Copy_u8PerName);
		break;
	case APB1 :
		SET_BIT(MRCC_APB1ENR , Copy_u8PerName);
		break;
	case APB2 :
		SET_BIT(MRCC_APB2ENR , Copy_u8PerName);
		break;
	default :
		//return error;
		break;
	}
}



/***************************************************************************************/
/*                         02- MRCC_voidDisablePeripheralClock                         */
/***************************************************************************************/

void MRCC_voidDisablePeripheralCloak (BusName_t Copy_uddtBusName,u8 Copy_u8PerName)
{
	switch (Copy_uddtBusName)
	{
	case AHB1 :
		CLR_BIT(MRCC_AHB1ENR, Copy_u8PerName);
		break;
	case AHB2 :
		CLR_BIT(MRCC_AHB2ENR, Copy_u8PerName);
		break;
	case APB1 :
		CLR_BIT(MRCC_APB1ENR , Copy_u8PerName);
		break;
	case APB2 :
		CLR_BIT(MRCC_APB2ENR , Copy_u8PerName);
		break;
	default :
		//return error;
		break;
	}
}


/***************************************************************************************/
/*                            03- MRCC_voidInitSystemClock                             */
/***************************************************************************************/
void MRCC_voidInitSystemCloak (void)
{
	/* HSI case */
	#if MRCC_CLKSRC == HSI                  // it's the first time to discover that #if doesn't have () or {}
	/*Step 1 : Enable HSI*/
	SET_BIT(MRCC_CR,0U) ;
	/*Step 2: Wait Till HSI is ready */
	while(GET_BIT(MRCC_CR,1) == 0) ;
	/*Step 3 : Switch to HSI*/
	CLR_BIT(MRCC_CFRG,0U) ;
	CLR_BIT(MRCC_CFRG,1U) ;
	// i think there should be step four for reading the sws !   or this is a HardwarePrcess?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	#elif MRCC_CLKSRC == HSE
		 /*Step 1 : Enable HSE*/
		 SET_BIT(MRCC_CR,16U) ;
		 /*Step 2 : Wait Till HSI is ready */
		 while(GET_BIT(MRCC_CR,17) == 0) ;
	   #if   MRCC_HSE_SRC == HSE_MECH
		 /*Step 3 : Disable BYPass*/
		 CLR_BIT(MRCC_CR,18U) ;
		 /*Step 4 : Switch to HSE*/
		 SET_BIT(MRCC_CFGR,0U) ;
		 CLR_BIT(MRCC_CFGR,1U) ;

		#elif MRCC_HSE_SRC == HSE_RC
		 /*Step 3 : Enable BYPass*/
	    SET_BIT(MRCC_CR,18U) ;
	     /*Step 3 : Switch to HSE*/
	    SET_BIT(MRCC_CFGR,0U) ;
	 	CLR_BIT(MRCC_CFGR,1U) ;

		#else
	 	//reteurn error
		#endif

	#elif MRCC_CLKSRC == PLL
	   //TO_DO
	#else
		/*Error*/
	#endif

}


/***************************************************************************************/
/*                        05- MRCC_voidEnableClockSecuritySystem                       */
/***************************************************************************************/

void MRCC_voidEnableClockSecuritySystem (void)
{
	SET_BIT(MRCC_CR,19U) ;
}


/***************************************************************************************/
/*                        05- MRCC_voidDisableClockSecuritySystem                      */
/***************************************************************************************/

void MRCC_voidDisableClockSecuritySystem (void)
{
	CLR_BIT(MRCC_CR,19U) ;
}





