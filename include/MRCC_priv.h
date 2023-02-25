/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 20/1/2023                                                           */
/* Description                     : MRCC_priv.h  -> Registers Definition                               */

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

#ifndef MRCC_PRIV_H_
#define MRCC_PRIV_H_

#define       MRCC_BASE_ADDRESS         0x40023800

#define        MRCC_CR                 (*((volatile u32*) (MRCC_BASE_ADDRESS + 0x00)))
#define        MRCC_PLLCFRG            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x04))
#define        MRCC_CFRG               *((volatile u32*) (MRCC_BASE_ADDRESS + 0x08))
#define        MRCC_CIR                *((volatile u32*) (MRCC_BASE_ADDRESS + 0x0C))
#define        MRCC_AHB1RSTR           *((volatile u32*) (MRCC_BASE_ADDRESS + 0x10))
#define        MRCC_AHB2RSTR           *((volatile u32*) (MRCC_BASE_ADDRESS + 0x14))
#define        MRCC_APB1RSTR           *((volatile u32*) (MRCC_BASE_ADDRESS + 0x20))
#define        MRCC_APB2RSTR           *((volatile u32*) (MRCC_BASE_ADDRESS + 0x24))
#define        MRCC_AHB1ENR            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x30))
#define        MRCC_AHB2ENR            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x34))
#define        MRCC_APB1ENR            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x40))
#define        MRCC_APB2ENR            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x44))
#define        MRCC_AHB1LPENR          *((volatile u32*) (MRCC_BASE_ADDRESS + 0x50))
#define        MRCC_AHB2LPENR          *((volatile u32*) (MRCC_BASE_ADDRESS + 0x54))
#define        MRCC_APB1LPENR          *((volatile u32*) (MRCC_BASE_ADDRESS + 0x60))
#define        MRCC_APB2LPENR          *((volatile u32*) (MRCC_BASE_ADDRESS + 0x64))
#define        MRCC_BDCR               *((volatile u32*) (MRCC_BASE_ADDRESS + 0x70))
#define        MRCC_CSR                *((volatile u32*) (MRCC_BASE_ADDRESS + 0x74))
#define        MRCC_SSCGR              *((volatile u32*) (MRCC_BASE_ADDRESS + 0x80))
#define        MRCC_PLLI2SCFGR         *((volatile u32*) (MRCC_BASE_ADDRESS + 0x84))
#define        MRCC_DCKCFGR            *((volatile u32*) (MRCC_BASE_ADDRESS + 0x8C))


#define HSI                   0
#define HSE                   1
#define PLL                   2

#define HSE_MECH              3
#define HSE_RC                4

#define PLL_HSE               5
#define PLL_HSI               6


#endif /* MRCC_PRIV_H_ */
