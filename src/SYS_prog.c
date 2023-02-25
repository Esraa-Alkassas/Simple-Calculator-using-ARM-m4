
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

#include "SYS_priv.h"
#include "SYS_config.h"
#include "SYS_interface.h"


static void(*MSTK_CallBack)(void);                 //this is a global function to pointer to recieve the call back function of the interrupt, in it.
                                                    // he made it static because he won't it to be called in any other files(you knowthat, if the function is static in a file, that means that it won't be able to be called in any other file)

/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/

/***************************************************************************************/
/*                                    1- MSTK_voidInit(void)                           */
/***************************************************************************************/
void MSTK_voidInit(void)
{
	/*stop(Disabl) STK --->>>> because if we make this bit enablethis means that it will begin to count ! and i still didn't give it the preload and countervalue .. so we should disable it in the init function*/
	CLR_BIT(MSTK->CTRL , 0);

	/*Enable Interrupt mode status*/               // this means that if i won't work in the interrupt mode i must disable it ,,,,,,,, so i thint the better is to remove this step to not be have to disable it if i work in the polling mode,,,,,,,but i will remain it as he did for now only........
	SET_BIT(MSTK->CTRL , 1);

	/*Set the STK clock*/
	#if  STK_CLOCK == SYSTEM_CLOCK
	SET_BIT(MSTK->CTRL , 2);
	#elif STK_CLOCK == AHBDividedByEight
	CLR_BIT(MSTK->CTRL , 2);
	#else
	//return error
	#endif

}



void MSTK_voidStart(u32 Copy_u32Preload)
{
	//if F_CPU -> HSI = 16MHz , AHB = 16 MHz , F_Timer = AHB/8 = 2 MHz         // F_CPU -> HSI  means the input clock to the Systick is the system clock (HSI)
	// soooooooo (0.5 us for each count)

	/* put the preload value in the register,, assume that we will use the timer in the multishot mode. I think this should be assigned in the config whetther i'm in the single shot mode or multi shoot mode */
	MSTK->LOAD = Copy_u32Preload -1 ;     // Copy_u32Preload -1 because this is the multishot mode.

	/*write any value (0 for example) in the counter register to immediately reload the value in the preload register */
	Clr_ALL_BITS(MSTK->VAL);

	/* start (enable) STK, we should make the configuration first then enable the systick bit*/
	SET_BIT(MSTK->CTRL , 0);
}


u8 MSTK_voidReadValReg(void)              // the purpose of this function is to clear the timer flag
                                          // why he didn't make the return type of this function void?!!!!!!!!!!!!!!!!!!!
{
	GET_BIT(MSTK->CTRL , 16);
	return 0;
}


//u8 MSTK_voidReadValReg(void)              // the purpose of this function is to clear the timer flag
//                                          // why he didn't make the return type of this function void?!!!!!!!!!!!!!!!!!!!
//{
//
//	return GET_BIT(MSTK->CTRL , 16);
//}                                       // i should make this function not the above and use it in the next next function instead of read the flag using get bit




void MSTK_voidSetInterruptStatus(u8 Copy_u8IntStatus)
{
	switch (Copy_u8IntStatus)
	{
		case DISABLE:
			CLR_BIT(MSTK->CTRL , 1);
			break;
		case ENABLE:
			SET_BIT(MSTK->CTRL , 1);
			break;
		default:
			//report error
			break;
	}

}




//remember that:
//if F_CPU -> HSI = 16MHz , AHB = 16 MHz , F_Timer = AHB/8 = 2 MHz         // F_CPU -> HSI  means the input clock to the Systick is the system clock (HSI)
// soooooooo (0.5 us for each count)
void MSTK_voidDelay_ms(u32 Copy_u32Delayms)
{
	//Step 1 : Init Systick
	MSTK_voidInit();

	//Step 2 : Disable INT                      // this means that we work with polling mode
	MSTK_voidSetInterruptStatus(DISABLE);

	//Step 3 : Start Systick( Copy_u32Time )
	MSTK_voidStart(Copy_u32Delayms * 2000);

	//Step 4 : Wait Flag Polling
	while (GET_BIT(MSTK->CTRL , 16) == 0);                // take care, i don't have to clear the flag here after i polled on it (like AVR) because once I read it, it becomes cleared & here I already read it during the polling
}





void MSTK_voidDelay_Us(u32 Copy_u32DelayUs)             // Us  means delay in micro seconds
{
	//Step 1 : Init Systick
	MSTK_voidInit();

	//Step 2 : Disable INT
	MSTK_voidSetInterruptStatus(DISABLE);

	//Step 3 : Start Systick( Copy_u32Time )
	MSTK_voidStart(Copy_u32DelayUs * 2);                      // i'm not sure about 2 but i think it is 2 ,, the illustration of this point in the sec video at 1:10:50

	//Step 4 : Wait Flag Polling
	while (GET_BIT(MSTK->CTRL , 16) == 0);
}






void Mstk_voidSetCallBackFunc(void(*PFunc)(void))
{
	MSTK_CallBack = &PFunc;                              // why we don't put these ()?!! isn't that considered as function call?!
}


// I should write here the ISR function implementation but he said that he won't write it until he illustrate interrupts in the next session



// calling by Hardware if interrupt happens
void SysTick_Handler(void)
{
	// Execute CallBack Function
	MSTK_CallBack() ;
}                                                    // is this the ISR func?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
