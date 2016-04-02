/*
 * LCD_Interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: mahmoud
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/*******************************************************************/
/****************Public Definitions*********************************/
/*******************************************************************/
#define LCD_u8M 0x00
#define LCD_u87 0x01
#define LCD_u8O 0x02
#define LCD_u8D 0x03
#define LCD_u8c1 0x04
#define LCD_u8c2 0x05
#define LCD_u8c3 0x06
#define LCD_u8c4 0x07
#define LCD_u8c5 0x08
#define LCD_u8c6 0x09



/*******************************************************************/
/****************Public function*********************************/
/*******************************************************************/
/*comment!: initialize the LCD */
extern void LCD_VOIDInit(void);
/*comment!:Write Command to the LCD*/
extern u8 LCD_u8Writecommand(u8 copy_u8Command);
/*comment!:Write Data to LCD */
extern u8 LCD_u8WriteData(u8 copy_u8Data);
/*comment!: initialize the special char in gcRAM */
extern void LCD_voidInitSpecialchar(void);
extern u8 lCD_u8CLRScreen(void);

#endif /* LCD_INTERFACE_H_ */
