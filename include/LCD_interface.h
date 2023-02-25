/*
 * LCD_interface.h
 *
 *  Created on: Jan 24, 2023
 *      Author: Lenovo
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/* LCD control commands */

#define LCD_CLR         			0x01
#define LCD_Home        			0x02
#define LCD_ENTRYMODE   			0x06
#define LCD_DISPOFF     			0x08
#define LCD_DISPON_CURSON           0x0E
#define LCD_FUNCRSET                0x30
#define LCD_FUNCSET_8BIT            0x38
#define LCD_SETCURSOR               0x80
#define LCD_DISPON_CURSLINK         0x0F
#define LCD_DISPON_CURSOFF          0x0C



void HLCD_vidInit ( void);
void HLCD_vidsendCMD (u8 Copy_u8CMD);
void HLCD_vidsendChar (u8 Copy_u8Char);
void HLCD_vidWriteStr (u8* pu8str);
void HLCD_vidGoToXY(u8 x, u8 y);
void HLCD_vidSaveInCGRAM (void);

//void APP_voidDelayMS(u32 Copy_u32Delay);



#endif /* LCD_INTERFACE_H_ */
