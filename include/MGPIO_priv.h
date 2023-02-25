/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 20/1/2023                                                           */
/* Description                     : MGPIO_priv.h  -> Registers Definition                               */

/*************************************************************************************************/


/************************************************************************************************************/
/* Developer can't edit this File:
 *this file contains registers definitions and these are the method through which we can define the registers
 *  1- MACROs
 *  2- Struct
 *  3- union                                                                                               */
/**********************************************************************************************************/


/**************************************************************************************************************/
/*                   Guard of the file  (every character in its Name must be a capital letter)               */
/************************************************************************************************************/

#ifndef MGPIO_PRIV_H_
#define MGPIO_PRIV_H_


//he said that registers definition can be implemented by three ways:
//1- struct
//2- union
//3- MACROs
//in the previous drivers we used to use macro
//here he used struct method



/***************************************************************************************/
/*                                 GPIO_BASE_ADRESS                                    */
/***************************************************************************************/
#define   MGPIOA_BASE_ADDRESS                                   (0x40020000)
#define   MGPIOB_BASE_ADDRESS                                   (0x40020400)
#define   MGPIOC_BASE_ADDRESS                                   (0x40020800)

typedef struct
{
	u32 volatile   MODER;
	u32 volatile   OTYPER;
	u32 volatile   OSPEEDR;
	u32 volatile   PUPDR;
	u32 volatile   IDR;
	u32 volatile   ODR;
	u32 volatile   BSRR;
	u32 volatile   LCKR;
	u32 volatile   AFRL;
	u32 volatile   AFRH;

}MGPIOREG_t;


#define   MGPIOA          ((MGPIOREG_t*) (MGPIOA_BASE_ADDRESS))
#define   MGPIOB          ((MGPIOREG_t*) (MGPIOB_BASE_ADDRESS))
#define   MGPIOC          ((MGPIOREG_t*) (MGPIOC_BASE_ADDRESS))

#endif /* MGPIO_PRIV_H_ */
