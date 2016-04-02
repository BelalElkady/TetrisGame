/*
 * LCD_Prog.c
 *
 *  Created on: Mar 9, 2016
 *      Author: mahmoud
 */

#include"../headerfiles/types.h"
#include"../headerfiles/util.h"
#include"../headerfiles/DelayFiles/Delay_prog.c"
#include"../headerfiles/DIOFiles/DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"

u8 global_u8LCDPins[LCD_U8DATAPINS]={LCD_u8D0,LCD_u8D1,LCD_u8D2,LCD_u8D3,LCD_u8D4,LCD_u8D5,LCD_u8D6,LCD_u8D7};

static u8 LCD_u8writeToDataPins(u8 copy_u8Data)
{u8 local_u8Counter;
u8 local_u8Temp;
u8 local_u8OperationStatus=ok;
for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
{
//	copy_u8Data>>=local_u8Counter;

	local_u8Temp=GetBit(copy_u8Data,local_u8Counter);
	local_u8OperationStatus=DIO_u8WritePinVal(global_u8LCDPins[local_u8Counter],local_u8Temp);
}

return local_u8OperationStatus;
}

/*comment!:Write Command to the LCD returns the statuw */
extern u8 LCD_u8Writecommand(u8 copy_u8Command) {
	u8 local_u8OperationStatus = ok;

	//make the data on the data
	LCD_u8writeToDataPins(copy_u8Command);
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8RS, LCD_U8RS_COMMAND_VAL);
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8RW, DIO_u8LOW);
	//Make apulse on the enable pins
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8Enable, DIO_u8HIGH);
	Delay(1);
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8Enable, DIO_u8LOW);

	return local_u8OperationStatus;
}
/*comment!:Write Data to LCD */
extern u8 LCD_u8WriteData(u8 copy_u8Data) {

	u8 local_u8OperationStatus = ok;

	//make the data on the data BUS
	LCD_u8writeToDataPins(copy_u8Data);
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8RS, LCD_U8RS_DATA_VAL);
	//wrting to hte data BUS
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8RW, DIO_u8LOW);
	//Make apulse on the enable pins
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8Enable, DIO_u8HIGH);
	Delay(1);
	local_u8OperationStatus = DIO_u8WritePinVal(LCD_u8Enable, DIO_u8LOW);

	return local_u8OperationStatus;

}

extern void LCD_VOIDInit(void) { //making the start Activity diagram  of the LC
//delay 15 milli second as the LCD ooperating on 5v
	Delay(15);
	LCD_u8Writecommand(0b00110000);
	Delay(5);
	LCD_u8Writecommand(0b00110000);
	Delay(1);
	LCD_u8Writecommand(0b00110000);
// STARTING INITIALIZATION
	// Function Set intialization
	LCD_u8Writecommand(0b00111000);
	//Entery mod set
	LCD_u8Writecommand(0b00000110);
	//Display mode set
	LCD_u8Writecommand(0b00001100);
	//end initialization
}
/*comment!:goto specific position on the screen*/
extern u8 LCD_u8GotoXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition) {
	u8 local_u8OperationStatus = ok;
	u8 local_u8firstAddress[2] = {0x80,0xC0};

	LCD_u8Writecommand(local_u8firstAddress[Copy_u8XPosition-1] + Copy_u8YPosition-1);

	return local_u8OperationStatus;

}

/*comment!:clr the screen */
extern u8 lCD_u8CLRScreen(void) {
	u8 local_u8OperationStatus = ok;
	//SENDING an command to clr the screen
	local_u8OperationStatus = LCD_u8Writecommand(LCD_CLRSCREEN);
	//put the cursor at the fiirst line
	local_u8OperationStatus = 1;
	return local_u8OperationStatus;

}

/*comment!:setting the mode to arabic mode*/
void LCD_arabicmode()
{	LCD_u8Writecommand(0b00000100);
}

/*comment!:setting the mode to english mode*/
void LCD_englishmode()
{	LCD_u8Writecommand(0b00000110);
}


void LCD_voidUploadCustomChar(u8 copy_u8location, u8 *copy_u8character)

{
	u8 local_u8ArrayIndex;
	/* the Add offset must be 0 to 7*/
	if (copy_u8location < 8) {
		LCD_u8Writecommand(LCD_u8FIRSTPLACEINCGMEM + (copy_u8location * 8));
		for (local_u8ArrayIndex = 0; local_u8ArrayIndex < 8; local_u8ArrayIndex++) {
			LCD_u8WriteData(copy_u8character[local_u8ArrayIndex]);
		}
	} else {
		/* TODO: return Error */
	}

}
