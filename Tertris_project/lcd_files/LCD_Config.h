/*
 * LCD_Config.h
 *
 *  Created on: Mar 9, 2016
 *      Author: mahmoud
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Comments!:  PIN Initial Direction   */
/*Range!   : DIO_u8PIN0 to  DIO_u8PIN31  */
// data Ranges of the lCD
#define LCD_u8D0 DIO_u8PIN8
#define LCD_u8D1 DIO_u8PIN9
#define LCD_u8D2 DIO_u8PIN10
#define LCD_u8D3 DIO_u8PIN11
#define LCD_u8D4 DIO_u8PIN12
#define LCD_u8D5 DIO_u8PIN13
#define LCD_u8D6 DIO_u8PIN14
#define LCD_u8D7 DIO_u8PIN15

//Controll bus
#define LCD_u8RS DIO_u8PIN18
#define LCD_u8RW DIO_u8PIN17
#define LCD_u8Enable DIO_u8PIN16

//INIT STATE OF THE LCD
//TODO make the define of the status on or off
#define LCD_U8INITIALLCD




#endif /* LCD_CONFIG_H_ */
