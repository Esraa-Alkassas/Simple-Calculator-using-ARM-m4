/************************************************************************************************************/
/* Auther                          :Esraa ElQassas                                                         */
/* Version                         : V0.0.0                                                               */
/* Date                            : 20/1/2023                                                           */
/* Description                     : MRCC_Config.h  -> Configuration                                    */

/*************************************************************************************************/


/************************************************************************************************************/
/* These are the options which the developer choose what is suitable to his application                    */
/****************************************************************************************    **************/


/**************************************************************************************************************/
/*                   Guard of the file  (every character in its Name must be a capital letter)               */
/************************************************************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/* 1- select the system clock source
 * options:
 *    1- HSI
 *    2- HSE
 *    3- PLL
 */

#define    MRCC_CLKSRC              HSI                       // for sure i can't replace text by text so we should define all these texts in the private file.


/* 2- select the type of the HSE
 * options:
 *    1- HSE_MECH
 *    2- HSE_RC
 */

#define    MRCC_HSETYP               HSE_MECH


/* 3- select the source of the PLL
 * options:
 *    1- PLL_HSE
 *    2- PLL_HSI
 */

#define    MRCC_PLL_SRC               PLL_HSE



#endif /* MRCC_CONFIG_H_ */
