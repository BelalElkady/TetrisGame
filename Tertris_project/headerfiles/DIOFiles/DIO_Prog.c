/*
 * DIO_Prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: nada
 */
#include "../util.h"
#include "../types.h"
#include "DIO_PRIVATE.H"
#include "DIO_CONFIG.H"
#include "DIO_iNTERFACE.H"

/***********************************************************/
/******************public functions*************************/
/***********************************************************/

/*comment!:initialization function*/
extern void DIO_voidInit(void) {

	DDRA = DIO_u8PORTADIR;
	DDRB = DIO_u8PORTBDIR;
	DDRC = DIO_u8PORTCDIR;
	DDRD = DIO_u8PORTDDIR;

	PORTA &= ~DIO_u8PORTADIR;
	PORTB &= ~DIO_u8PORTBDIR;
	PORTC &= ~DIO_u8PORTCDIR;
	PORTD &= ~DIO_u8PORTDDIR;

	PORTA |= (DIO_u8PORTADIR & DIO_u8ValuePortA);
	PORTB |= (DIO_u8PORTBDIR & DIO_u8ValuePortB);
	PORTC |= (DIO_u8PORTCDIR & DIO_u8ValuePortC);
	PORTD |= (DIO_u8PORTDDIR & DIO_u8ValuePortD);
}

/*comment!:Read Pin Value */
extern u8 DIO_u8ReadPinValue(u8 Copy_u8PINIdx, u8* Copy_u8PtrToVal) {
	u8 local_u8OperationStatus, local_u8CheckPort;
	local_u8CheckPort = Copy_u8PINIdx / DIO_u8PINSPERPORT;

	switch (local_u8CheckPort) {
	case DIO_u8PORT0:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToVal = GetBit(PINA, Copy_u8PINIdx);
		break;
	case DIO_u8PORT1:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToVal = GetBit(PINB, Copy_u8PINIdx);
		break;
	case DIO_u8PORT2:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToVal = GetBit(PINC, Copy_u8PINIdx);
		break;
	case DIO_u8PORT3:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToVal = GetBit(PIND, Copy_u8PINIdx);
		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;

}

/*comment!:Write Pin Value */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PINIdx, u8 Copy_u8PinVal) {
	u8 local_u8OperationStatus, local_u8CheckPort;
	local_u8CheckPort = Copy_u8PINIdx / DIO_u8PINSPERPORT;

	switch (local_u8CheckPort) {
	case DIO_u8PORT0:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		switch (Copy_u8PinVal) {

		case DIO_u8HIGH:
			PORTA=Setbit(PORTA, Copy_u8PINIdx);
			break;
		case DIO_u8LOW:
			PORTA=Clrbit(PORTA, Copy_u8PINIdx);
			break;
		default:
			break;
		}
		break;
	case DIO_u8PORT1:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		switch (Copy_u8PinVal) {

		case DIO_u8HIGH:
			PORTB=Setbit(PORTB, Copy_u8PINIdx);
			break;
		case DIO_u8LOW:
			PORTB=Clrbit(PORTB, Copy_u8PINIdx);
			break;
		default:
			break;
		}
		break;
	case DIO_u8PORT2:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		switch (Copy_u8PinVal) {

		case DIO_u8HIGH:
			PORTC=Setbit(PORTC, Copy_u8PINIdx);
			break;
		case DIO_u8LOW:
			PORTC=Clrbit(PORTC, Copy_u8PINIdx);
			break;
		default:
			break;
		}
		break;
	case DIO_u8PORT3:
		local_u8OperationStatus = ok;
		Copy_u8PINIdx = Copy_u8PINIdx % DIO_u8PINSPERPORT;
		switch (Copy_u8PinVal) {

		case DIO_u8HIGH:
			PORTD=Setbit(PORTD, Copy_u8PINIdx);
			break;
		case DIO_u8LOW:
			PORTD=Clrbit(PORTD, Copy_u8PINIdx);
			break;
		default:
			break;
		}
		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;
}

/*comment!: Read Port Value*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PINIdx, u8* Copy_u8PtrToVal) {
	u8 local_u8Counter, local_u8incommingValue, local_u8Check,
			local_u8OperationStatus;
	Copy_u8PtrToVal = 0x00;
	for (local_u8Counter = 0; local_u8Counter < DIO_u8PINSPERPORT;
			local_u8Counter++) {
		Copy_u8PINIdx += local_u8Counter;
		local_u8Check = DIO_u8ReadPinValue(Copy_u8PINIdx,
				&local_u8incommingValue);
		switch (local_u8Check) {
		case ok:
			local_u8OperationStatus = ok;
			*Copy_u8PtrToVal |= local_u8incommingValue;
			*Copy_u8PtrToVal <<= 1;
			break;
		case error:
			local_u8OperationStatus = error;
			break;
		default:
			break;
		}

	}
	return local_u8OperationStatus;
}

/*comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal) {

	u8	local_u8OperationStatus;
	switch (Copy_u8PortIdx) {
	case DIO_u8PORT0:
		local_u8OperationStatus = ok;
		PORTA = Copy_u8PortVal;

		break;
	case DIO_u8PORT1:
		local_u8OperationStatus = ok;
		PORTB = Copy_u8PortVal;
		break;
	case DIO_u8PORT2:
		local_u8OperationStatus = ok;
		PORTC = Copy_u8PortVal;
		break;
	case DIO_u8PORT3:
		local_u8OperationStatus = ok;
		PORTD = Copy_u8PortVal;
		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;

}

/*comment!:Read Pin Direction*/
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrToDir) {

	u8 local_u8OperationStatus, local_u8CheckPort;
	local_u8CheckPort = Copy_u8PinIdx / DIO_u8PINSPERPORT;

	switch (local_u8CheckPort) {
	case DIO_u8PORT0:
		local_u8OperationStatus = ok;
		Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToDir = GetBit(DDRA, Copy_u8PinIdx);
		break;
	case DIO_u8PORT1:
		local_u8OperationStatus = ok;
		Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToDir = GetBit(DDRB, Copy_u8PinIdx);
		break;
	case DIO_u8PORT2:
		local_u8OperationStatus = ok;
		Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToDir = GetBit(DDRC, Copy_u8PinIdx);
		break;
	case DIO_u8PORT3:
		local_u8OperationStatus = ok;
		Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
		*Copy_u8PtrToDir = GetBit(DDRD, Copy_u8PinIdx);
		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;

}

/*comment!:Read Port Direction*/
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToDir) {

	u8 local_u8OperationStatus=ok;
	switch (Copy_u8PortIdx) {
	case DIO_u8PORT0:
		*Copy_u8PtrToDir = DDRA;

		break;
	case DIO_u8PORT1:
		*Copy_u8PtrToDir = DDRB;

		break;
	case DIO_u8PORT2:
		*Copy_u8PtrToDir = DDRC;

		break;
	case DIO_u8PORT3:
		*Copy_u8PtrToDir = DDRD;

		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;

}


/*comment!:Write Port Direction*/
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir) {

	u8 local_u8OperationStatus=ok;
	switch (Copy_u8PortIdx) {
	case DIO_u8PORT0:
		DDRA = Copy_u8PortDir;
		break;
	case DIO_u8PORT1:
		DDRB = Copy_u8PortDir;
		break;
	case DIO_u8PORT2:
		DDRC = Copy_u8PortDir;
		break;
	case DIO_u8PORT3:
		DDRD = Copy_u8PortDir;
		break;
	default:
		local_u8OperationStatus = error;
		break;

	}

	return local_u8OperationStatus;

}



/*comment!:Write Pin Direction*/
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir) {

	u8 local_u8OperationStatus, local_u8CheckPort;
		local_u8CheckPort = Copy_u8PinIdx / DIO_u8PINSPERPORT;

		switch (local_u8CheckPort) {
		case DIO_u8PORT0:
			local_u8OperationStatus = ok;
			Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
			switch (Copy_u8PinDir) {

			case DIO_u8HIGH:
				DDRA=Setbit(DDRA, Copy_u8PinIdx);
				break;
			case DIO_u8LOW:
				DDRA=Clrbit(DDRA, Copy_u8PinIdx);
				break;
			default:
				break;
			}
			break;
		case DIO_u8PORT1:
			local_u8OperationStatus = ok;
			Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
			switch (Copy_u8PinDir) {

			case DIO_u8HIGH:
				DDRB=Setbit(DDRB, Copy_u8PinIdx);
				break;
			case DIO_u8LOW:
				DDRB=Clrbit(DDRB, Copy_u8PinIdx);
				break;
			default:
				break;
			}
			break;
		case DIO_u8PORT2:
			local_u8OperationStatus = ok;
			Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
			switch (Copy_u8PinDir) {

			case DIO_u8HIGH:
				DDRC=Setbit(DDRC, Copy_u8PinIdx);
				break;
			case DIO_u8LOW:
				DDRC=Clrbit(DDRC, Copy_u8PinIdx);
				break;
			default:
				break;
			}
			break;
		case DIO_u8PORT3:
			local_u8OperationStatus = ok;
			Copy_u8PinIdx = Copy_u8PinIdx % DIO_u8PINSPERPORT;
			switch (Copy_u8PinDir) {

			case DIO_u8HIGH:
				DDRD=Setbit(DDRD, Copy_u8PinIdx);
				break;
			case DIO_u8LOW:
				DDRD=Clrbit(DDRD, Copy_u8PinIdx);
				break;
			default:
				break;
			}
			break;
		default:
			local_u8OperationStatus = error;
			break;

		}

		return local_u8OperationStatus;
}
