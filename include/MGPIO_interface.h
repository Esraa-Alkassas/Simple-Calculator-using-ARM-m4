/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 22/1/2023                                                           */
/* Description                     : MGPIO_interface.h  -> Function Prototypes                           */
/* Module Features                 : 01- MGPIO_voidSetPinMode                                           */
/*                                 : 02- MGPIO_voidSetOutputType                                       */
/*                                 : 03- MGPIO_voidSetOutputPinSpeed                                  */
/*                                 : 04- MGPIO_voidSetPinPullType                                    */
/*                                 : 05- MGPIO_voidSetPinValue                                      */
/*                                 : 06- MGPIO_voidGetPinValue                                     */
/*  Future Updates:  (we will do them on our owns)
 *                07- MGPIO_VoidSetPinLock
 *                08- MGPIO_VoidSetResetPin
 *                09- MGPIO_VoidSetPinAltf            i think he said that these apis are tasks                    */
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

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

//note that all enums here can be defined as MACROs using #define as useual and we will define them as any number as we used to do.
// he -orignally- did that here in some cases like the four  modes of the pins.



/**************************************************************************************************************/
/*                                        GPIO_Name                                                          */
/************************************************************************************************************/
typedef enum
{
	MGPIO_PORTA,
	MGPIO_PORTB,
	MGPIO_PORTC
}MGPIOx_t;



/**************************************************************************************************************/
/*                                               PIN nUMBER_Name                                             */
/************************************************************************************************************/



typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;




/**************************************************************************************************************/
/*                                                     Speed Name                                            */
/************************************************************************************************************/
typedef enum
		{
	MGPO_SPEED_LOW,
	MGPO_SPEED_MID,
	MGPO_SPEED_HIGH,
	MGPO_SPEED_VHIGH,

		} speed_t ;



/**************************************************************************************************************/
/*                                             PIN Mode                                                      */
/************************************************************************************************************/
#define MGPIO_PIN_INPUT    0b00
#define MGPIO_PIN_OUTPUT   0b01
#define MGPIO_PIN_ALTF     0b10
#define MGPIO_PIN_ANALOG   0b11



/**************************************************************************************************************/
/*                                           Output Mode                                                     */
/************************************************************************************************************/
typedef enum
{
	MGPIO_PUSH_PULL,
	MGPIO_OPEN_DDRAIN
}OutputType_t;                    // the content of the enum should be as that because the data sheet said that if you want push pull connection, you should put the in the register zero and if you want open drain then you should put it one



/**************************************************************************************************************/
/*                                                          pull type                                        */
/************************************************************************************************************/
#define MGPIO_PIN_FLOAT         0b00
#define MGPIO_PIN_PULL_UP       0b01
#define MGPIO_PIN_PULL_DOWN     0b10



/**************************************************************************************************************/
/*                                            PIN value                                                      */
/************************************************************************************************************/
#define MGPIO_PIN_HIGH         1
#define MGPIO_PIN_LOW          0





/*#####################################################################################*/
/*                                Function ProtoTypes                                  */
/*#####################################################################################*/

/***************************************************************************************/
/*                          01- MGPIO_voidSetPinMode()                                 */
/*-------------------------------------------------------------------------------------*/
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

void MGPIO_voidSetPinMode (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PinMode);


/***************************************************************************************/
/*                          01- MGPIO_voidSetPinOutputType()                               */
/*-------------------------------------------------------------------------------------*/
// we should make a description about every API like that we did in the first API here but we won't do that for time consumption.
void MGPIO_voidSetPinOutputType (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, OutputType_t Copy_uddtPinOutputType);



/***************************************************************************************/
/*                          01- MGPIO_voidSetOutputPinSpeed()                          */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinOutputSpeed (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, speed_t Copy_uddtPinOutputSpeed);




/***************************************************************************************/
/*                          01- MGPIO_voidSetPinPullType                       */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinPullType (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PullType);





/***************************************************************************************/
/*                          01- MGPIO_voidGetPinValue()                       */
/*-------------------------------------------------------------------------------------*/
//void MGPIO_voidGetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8* Copy_pu8PinValue);
u8 MGPIO_voidGetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum);



/***************************************************************************************/
/*                          01- MGPIO_voidSetPinValue()                       */
/*-------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinValue (MGPIOx_t Copy_uddtPortNum, PIN_t Copy_uddtPinNum, u8 Copy_u8PinValue);
// this function is normal i thought that i have conflict about the reason why he made this function and what is the benefit from it, but it really normal
// if you remember with me in avr or ardino when we was first set the pin mode in or out and if it out we then set the value high or low(or i mean gave it a value; high or low)
// and if it was input we then get (or read) the value of it. so it is normal to implement a function for getting the value of the pin if it was input pin ,, and another funtion for setting the value of the pin if it was output pin.




void MGPIO_voidSetPortValue (MGPIOx_t Copy_uddtPortNum, u8 Copy_u8PortValue);

#endif /* MGPIO_INTERFACE_H_ */
