/*
 * KeyPad_Private.h
 *
 *  Created on: Feb 25, 2016
 *      Author: mahmoud
 */

#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_
#include "KeyPad_Config.h"
#include "../DIOFiles/DIO_Interface.h"

/***********************************************/
/********** private defines  *******************/
/***********************************************/
//will be used to loop the KEYPAD_PRIVATE_u8ArrayOfRows array as not to be able
//to use magic no
#define KEYPAD_PRIVATE_u8ArrayOfRowZeroElement 0
#define KEYPAD_PRIVATE_u8ArrayOfRowLastElement 4
#define BOUNCING 2

//will be used to loop the KEYPAD_PRIVATE_u8ArrayOfCols array as not to be abble
//to use magic no
#define KEYPAD_PRIVATE_u8ArrayOfColZeroElement 0
#define KEYPAD_PRIVATE_u8ArrayOfColLastElement 4
/***********************************************/
/********** private array  *********************/
/***********************************************/
u8 KEYPAD_PRIVATE_u8ArrayOfRows [4]={KEYPAD_u8Row0,KEYPAD_u8Row1,KEYPAD_u8Row2,KEYPAD_u8Row3};
u8 KEYPAD_PRIVATE_u8ArrayOfCols [4]={KEYPAD_u8Col0,KEYPAD_u8Col1,KEYPAD_u8Col2,KEYPAD_u8Col3};

#endif /* KEYPAD_PRIVATE_H_ */
