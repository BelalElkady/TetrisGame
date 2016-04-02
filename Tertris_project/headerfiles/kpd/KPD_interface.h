/*
 * KPD_interface.h
 *
 *  Created on: Feb 26, 2016
 *      Author: m.mamdooh
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_
#include "../types.h"
//////////////////////////////////
/////////////MACROS///////////////
//////////////////////////////////

#define KPD_u8SW1_IDX 		1
#define KPD_u8SW2_IDX 		2
#define KPD_u8SW3_IDX 		3
#define KPD_u8SW4_IDX 		4
#define KPD_u8SW5_IDX	 	5
#define KPD_u8SW6_IDX 		6
#define KPD_u8SW7_IDX 		7
#define KPD_u8SW8_IDX 		8
#define KPD_u8SW9_IDX 		9
#define KPD_u8SW10_IDX      10
#define KPD_u8SW11_IDX      11
#define KPD_u8SW12_IDX		12
#define KPD_u8SW13_IDX		13
#define KPD_u8SW14_IDX		14
#define KPD_u8SW15_IDX		15
#define KPD_u8SW16_IDX		16

///////////////////////////////////
////////////API's//////////////////
///////////////////////////////////
extern void KPD_u8Read(u8 *Copy_BtnIdx);
extern void KPD_voidInit();
extern u8 KPD_GetBtn(u8 Copy_u8BtnIdx,u8 *Copy_u8BtnVal);
#endif /* KPD_INTERFACE_H_ */
