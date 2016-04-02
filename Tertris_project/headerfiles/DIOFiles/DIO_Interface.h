/*

 * DIO_interface.h
 *
 *  Created on: Jan 30, 2016
 *      Author: mahmoud


#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

*************************************************************
******************Public Definition**************************
*************************************************************

comment!:Pin Index values
#define DIO_u8PIN0		0
#define DIO_u8PIN1		1
#define DIO_u8PIN2		2
#define DIO_u8PIN3		3
#define DIO_u8PIN4		4
#define DIO_u8PIN5		5
#define DIO_u8PIN6		6
#define DIO_u8PIN7		7
#define DIO_u8PIN8		8
#define DIO_u8PIN9		9
#define DIO_u8PIN10		10
#define DIO_u8PIN11		11
#define DIO_u8PIN12		12
#define DIO_u8PIN13		13
#define DIO_u8PIN14		14
#define DIO_u8PIN15		15
#define DIO_u8PIN16		16
#define DIO_u8PIN17		17
#define DIO_u8PIN18		18
#define DIO_u8PIN19		19
#define DIO_u8PIN20		20
#define DIO_u8PIN21		21
#define DIO_u8PIN22		22
#define DIO_u8PIN23		23
#define DIO_u8PIN24		24
#define DIO_u8PIN25		25
#define DIO_u8PIN26		26
#define DIO_u8PIN27		27
#define DIO_u8PIN28		28
#define DIO_u8PIN29		29
#define DIO_u8PIN30		30
#define DIO_u8PIN31		31
comment!:PORT Index values
#define DIO_		31



*************************************************************
******************Public Definition**************************
*************************************************************


#endif  DIO_INTERFACE_H_


 * DIO_Interface.h
 *
 *  Created on: Jan 27, 2016
 *      Author: mahmoud
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../types.h"

/*******************************************************************/
/****************Public Definitions*********************************/
/*******************************************************************/

/* comment!:Pin Index Values */
#define DIO_u8PIN0    0
#define DIO_u8PIN1    1
#define DIO_u8PIN2    2
#define DIO_u8PIN3    3
#define DIO_u8PIN4    4
#define DIO_u8PIN5    5
#define DIO_u8PIN6    6
#define DIO_u8PIN7    7
#define DIO_u8PIN8    8
#define DIO_u8PIN9    9
#define DIO_u8PIN10   10
#define DIO_u8PIN11   11
#define DIO_u8PIN12   12
#define DIO_u8PIN13   13
#define DIO_u8PIN14   14
#define DIO_u8PIN15   15
#define DIO_u8PIN16   16
#define DIO_u8PIN17   17
#define DIO_u8PIN18   18
#define DIO_u8PIN19   19
#define DIO_u8PIN20   20
#define DIO_u8PIN21   21
#define DIO_u8PIN22   22
#define DIO_u8PIN23   23
#define DIO_u8PIN24   24
#define DIO_u8PIN25   25
#define DIO_u8PIN26   26
#define DIO_u8PIN27   27
#define DIO_u8PIN28   28
#define DIO_u8PIN29   29
#define DIO_u8PIN30   30
#define DIO_u8PIN31   31


/* comment!: Port Index Values*/
#define DIO_u8PORT0      0
#define DIO_u8PORT1      1
#define DIO_u8PORT2      2
#define DIO_u8PORT3      3

/*comment!: Digital I/O Value*/
#define DIO_u8HIGH      1
#define DIO_u8LOW       0

/*comment!: Digital I/O Direction */

#define DIO_u8OUTPUT     1
#define DIO_u8INPUT      0

/***********************************************************/
/******************public functions*************************/
/***********************************************************/

/*comment!:Read Pin Value */
extern u8 DIO_u8ReadPinValue(u8 CopyPINIdx_u8,u8* Copy_u8PtrToVal);

/*comment!: write pin Value */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PINIdx, u8 Copy_u8PinVal);

/*comment!: Read Port Value*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PINIdx,u8* Copy_u8PtrToVal);

/*comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal);

/*comment!:Write Pin Direction*/
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir);

/*comment!:Write Port Direction*/
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir);

/*comment!:Read Pin Direction*/
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PtrToDir);

/*comment!:Read Port Direction*/
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PtrToDir);

/*comment!:goto specific position on the screen*/
extern u8 LCD_u8GotoXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

/*comment!:clr the screen */
extern u8 lCD_u8CLRScreen(void);

/*comment!:intialization function*/
extern void DIO_voidInit(void);

/*comment!:setting the mode to arabic mode*/
void LCD_arabicmode();

/*comment!:setting the mode to english mode*/
void LCD_englishmode();

void LCD_voidUploadCustomChar(u8 copy_u8location, u8 *copy_u8character);


#endif /* DIO_INTERFACE_H_ */
