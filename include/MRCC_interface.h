/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 20/1/2023                                                           */
/* Description                     : MRCC_interface.h  -> Function Prototypes                           */
/* Module Features                 : 01- MRCC_voidEnablePeripheralCloak                                */
/*                                 : 02- MRCC_voidDisablePeripheralCloak                              */
/*                                 : 03- MRCC_voidInitSystemCloak                                    */
/*                                 : 04- MRCC_voidEnableClockSecuritySystem                         */
/*                                 : 05- MRCC_voidDisableClockSecuritySystem                       */
/*                                 : 06- MRCC_voidSetSystemClock                                  */
/*************************************************************************************************/


/************************************************************************************************************/
/* What I sell to the customer     : The Architecture Gives:  -the APIs                                    */
/*                                                            -Function Names                             */
/*                                                            -Function Inputs                           */
/*                                                            -Function Outputs                         */
/*                                                            -MACROs                                  */
/******************************************************************************************************/


/**************************************************************************************************************/
/*                   Guard of the file  (every character in its Name must be a capital letter)               */
/************************************************************************************************************/



#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/**************************************************************************************************************/
/*                                           Function Prototypes                                             */
/************************************************************************************************************/

// he said that bus options could be defined as macros or enum, he made them in enum.
typedef enum
{
	AHB1 =0,   // zero doesen't have to
	AHB2   ,
	APB1   ,
	APB2   ,
}BusName_t ;


/*******************************************************************************************************************/

void MRCC_voidEnablePeripheralCloak  (BusName_t Copy_uddtBusName,u8 Copy_u8PerName);            //uddt (user defined data type)
void MRCC_voidDisablePeripheralCloak (BusName_t Copy_uddtBusName,u8 Copy_u8PerName);
void MRCC_voidInitSystemCloak (void);
void MRCC_voidEnableClockSecuritySystem (void);
void MRCC_voidDisableClockSecuritySystem (void);
//void MRCC_voidSetSystemClock ()   he asked us to implement this function..

/********************************************************************************************************************/

/* pins definition (he said we will define them here because the user -in the application- will use them) */

/***************************************************************************************/
/*                      MACROS of : RCC AHB1 CLOCK  Enable                             */
/***************************************************************************************/

#define MRCC_PERIPHERIAL_EN_GPIOA       0U
#define MRCC_PERIPHERIAL_EN_GPIOB       1U
#define MRCC_PERIPHERIAL_EN_GPIOC       2U
#define MRCC_PERIPHERIAL_EN_GPIOD       3U
#define MRCC_PERIPHERIAL_EN_GPIOE       4U
#define MRCC_PERIPHERIAL_EN_GPIOH       7U
#define MRCC_PERIPHERIAL_EN_CRC         12U
#define MRCC_PERIPHERIAL_EN_DMA1        21U
#define MRCC_PERIPHERIAL_EN_DMA2        22U

/***************************************************************************************/
/*                      MACROS of : RCC AHB2 CLOCK  Enable                             */
/***************************************************************************************/
//TODO


/***************************************************************************************/
/*                      MACROS of : RCC APB1 CLOCK  Enable                             */
/***************************************************************************************/
//TODO



/***************************************************************************************/
/*                      MACROS of : RCC APB2 CLOCK  Enable                             */
/***************************************************************************************/
//TODO


#endif /* MRCC_INTERFACE_H_ */
