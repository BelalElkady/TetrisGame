/*
 * KeyPad_Interface.h
 *
 *  Created on: Feb 25, 2016
 *      Author: mahmoud
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
/***********************************************/
/********** type def ***************************/
/***********************************************/
//new type specialy fo the Key Pad can be used in two wayes
//as awhole 16 bit or you can use it as bit by bit

typedef union{
	u16 Switches;
	struct{
		u16 Switche1:1;
		u16 Switche2:1;
		u16 Switche3:1;
		u16 Switche4:1;
		u16 Switche5:1;
		u16 Switche6:1;
		u16 Switche7:1;
		u16 Switche8:1;
		u16 Switche9:1;
		u16 Switche10:1;
		u16 Switche11:1;
		u16 Switche12:1;
		u16 Switche13:1;
		u16 Switche14:1;
		u16 Switche15:1;
		u16 Switche16:1;
	}Switche;
}FBF_keyPad;
/***********************************************/
/********** Public function ********************/
/***********************************************/
/*comment!:to initialize the KeyPad Acording to the config file */
extern void KeyPad_voidInit(void);
/*comment!:to loop for the Keypad and check for one button only at atime  */
extern u8 KeyPad_u8Read(FBF_keyPad *Copy_unionFBF_keyPadPtrToVal);
/*comment!:to Read and chek for aspecific Button */
extern u8 KeyPad_u8checkSwitch(u8 Copy_u8KeyIndex,u8 Copy_u8PtrtoVal);
/*comment!:to Read and solve the bouncing problem */
extern u8 KeyPad_u8DebouncingSol(u8 Copy_u8KeyIndex, u8 *Copy_u8PtrtoVal);
#endif /* KEYPAD_INTERFACE_H_ */
