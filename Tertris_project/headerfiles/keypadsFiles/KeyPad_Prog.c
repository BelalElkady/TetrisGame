/*
 * KeyPad_Prog.c
 *
 *  Created on: Feb 25, 2016
 *      Author: mahmoud
 */

/***********************************************/
/********** includes****************************/
/***********************************************/
#include "../types.h"
#include "../util.h"
#include "KeyPad_Private.h"
#include "KeyPad_Interface.h"
#include "../DIOFiles/DIO_Interface.h"
/***********************************************/
/********** public definition ******************/
/***********************************************/
#define KEYPAD_u8BUTTON DIO_u8PIN24

/***********************************************/
/********** Public Definnitions ****************/
/***********************************************/
enum counterRange
{
	 MINCOUNTER = 0,
	 MAXCOUNTER = 50
};

enum ButtonState
{
	 RELEASED=0,
	 PRESSED=1,
	 DEBOUNCING=2
};


/***********************************************/
/********** Public function ********************/
/***********************************************/

/*comment!:to initialize the KeyPad Acording to the config file */
extern void KeyPad_voidInit(void) {
	u8 local_u8Counter = 0;
//initializing the rows as output
	for (local_u8Counter = KEYPAD_PRIVATE_u8ArrayOfRowZeroElement;
			local_u8Counter < KEYPAD_PRIVATE_u8ArrayOfRowLastElement;
			local_u8Counter++) {
		DIO_u8WritePinDir(KEYPAD_PRIVATE_u8ArrayOfRows[local_u8Counter],
		DIO_u8OUTPUT);
	}

	//initializing the Cols as input
	for (local_u8Counter = KEYPAD_PRIVATE_u8ArrayOfColZeroElement;
			local_u8Counter < KEYPAD_PRIVATE_u8ArrayOfColLastElement;
			local_u8Counter++) {

		DIO_u8WritePinDir(KEYPAD_PRIVATE_u8ArrayOfCols[local_u8Counter],
		DIO_u8INPUT);
	}
}

/*comment!:to loop for the Keypad and check for one button only at atime  */
extern u8 KeyPad_u8Read(FBF_keyPad * Copy_unionFBF_keyPadPtrToVal) {
	u8 local_u8OperationStatus = ok;

	//TODO add the body of the read after handling the bouncing

	return local_u8OperationStatus;

}

/*comment!:to Read and chek for aspecific Button */
extern u8 KeyPad_u8checkSwitch(u8 Copy_u8KeyIndex, u8 Copy_u8PtrtoVal) {
	u8 local_u8OperationStatus = ok;

	//TODO add the body of the checkSwitch after handling the bouncing

	return local_u8OperationStatus;

}


/***********************************************/
/********** Private function ********************/
/***********************************************/

//TODO make the KeyPad_u8DebouncingSol static and delete it proto type from the Interfsce
extern u8 KeyPad_u8DebouncingSol(u8 Copy_u8KeyIndex, u8 *Copy_u8PtrtoVal) {
	//local_u8OperationStatus --> will return the status of the operation
	//Local_u8CurrentVal -->the value the i will read the value of button in
	u8 local_u8OperationStatus = ok, Local_u8CurrentVal;
	//local_u8StaticUpCounter -->a static variable to count the times the button is pressed
	//local_u8StaticDownCounter -->a static variable to count the times the button is released
	//Local_U8State -->astatic variable that determine the current state of the button
	u8 static local_u8StaticUpCounter = MAXCOUNTER, local_u8StaticDownCounter =
			MAXCOUNTER, Local_U8State = RELEASED;
	//local_u8StaticOldVal -->astatic variable that determine the previous  state of the button
	//to use in debouncing state to know each state i came from to return that value till i get out the debouncing state
	u8 static local_u8StaticOldVal;
	//switch the state of the button initialy is released
	switch (Local_U8State) {
	// realesed state
	case RELEASED:
		//return the released state
		*Copy_u8PtrtoVal = RELEASED;
		//read the piv val
		local_u8OperationStatus = DIO_u8ReadPinValue(Copy_u8KeyIndex,
				&Local_u8CurrentVal);
		//if the readed value is high so SAVE THE Current state in the old state and go to debouncing
		if (Local_u8CurrentVal == DIO_u8HIGH) {
			local_u8StaticOldVal = RELEASED;
			Local_U8State = DEBOUNCING;
		} else {
			//do Nothing
		}
		break;
		// realesed state
	case PRESSED:
		//return the released state
		*Copy_u8PtrtoVal = PRESSED;
		//read the piv val
		local_u8OperationStatus = DIO_u8ReadPinValue(Copy_u8KeyIndex,
				&Local_u8CurrentVal);
		//if the readed value is LOW so SAVE THE Current state in the old state and go to debouncing
		if (Local_u8CurrentVal == DIO_u8LOW) {
			local_u8StaticOldVal = PRESSED;
			Local_U8State = DEBOUNCING;
		} else {
			//do Nothing
		}
		break;
		//	DEBOUNCING STATE
	case DEBOUNCING:
		//try to return the val of the old saved value as debouncing didnt determine yet the true current state
		*Copy_u8PtrtoVal = local_u8StaticOldVal;
		//read the piv val
		local_u8OperationStatus = DIO_u8ReadPinValue(Copy_u8KeyIndex,
				&Local_u8CurrentVal);
		//switch the value of the Pin
		switch (Local_u8CurrentVal) {
		// in the case of High decrement the  local_u8StaticUpCounter if it reach MINCOUNTER=0
		//if local_u8StaticUpCounter=MAXCOUNTER=50 then the status will turn into PRESSED
		case DIO_u8HIGH:
			local_u8StaticUpCounter--;
			if (local_u8StaticUpCounter == MINCOUNTER) {
				local_u8StaticDownCounter = MAXCOUNTER;
				local_u8StaticUpCounter = MAXCOUNTER;
				Local_U8State = PRESSED;
			} else {
				//do Nothing
			}

			break;
			// in the case of lOW READING decrement the  local_u8StaticdOWNCounter if it reach MINCOUNTER=0
			//if local_u8StaticUpCounter=MAXCOUNTER=50 then the status will turn into RELEASED
		case DIO_u8LOW:
			local_u8StaticDownCounter--;
			if (local_u8StaticDownCounter == MINCOUNTER) {
				local_u8StaticDownCounter = MAXCOUNTER;
				local_u8StaticUpCounter = MAXCOUNTER;
				Local_U8State = RELEASED;
			} else {
				//do Nothing
			}

			break;
		default:
			//do Nothing
			break;

		}
		break;
	default:
		//do Nothing
		break;

	}
	// RETURN THE STATUS OF READING
	return local_u8OperationStatus;

}
