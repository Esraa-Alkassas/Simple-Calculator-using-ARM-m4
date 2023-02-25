/*
 * SYS_interface.h
 *
 *  Created on: Jan 24, 2023
 *      Author: Lenovo
 */

#ifndef SYS_INTERFACE_H_
#define SYS_INTERFACE_H_


//typedef enum
//{
//	DISABLE,
//	ENABLE
//}INT_STAT_t;


#define      DISABLE       0
#define      ENABLE        1


void MSTK_voidInit(void);
void MSTK_voidStart(u32 Copy_u32Preload);
u8 MSTK_voidReadValReg(void);
void MSTK_voidSetInterruptStatus(u8 Copy_u8IntStatus);
void MSTK_voidDelay_ms(u32 Copy_u32Delayms);
void MSTK_voidDelay_Us(u32 Copy_u32DelayUs);
void Mstk_voidSetCallBackFunc(void(*PFunc)(void));




#endif /* SYS_INTERFACE_H_ */
