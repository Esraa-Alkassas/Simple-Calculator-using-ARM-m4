/*
 * SYS_priv.h
 *
 *  Created on: Jan 24, 2023
 *      Author: Lenovo
 */

#ifndef SYS_PRIV_H_
#define SYS_PRIV_H_

/* Systick Base Address */
#define   MSTK_BASE_ADDRESS              0xE000E010


/* Registers Definition */
typedef struct
{
	u32 volatile CTRL;
	u32 volatile LOAD;
	u32 volatile VAL;
	u32 volatile CALIB;
}MSTK_t;


#define MSTK                   ((MSTK_t*)(MSTK_BASE_ADDRESS))



#define     SYSTEM_CLOCK               1
#define     AHBDividedByEight          0

#endif /* SYS_PRIV_H_ */
