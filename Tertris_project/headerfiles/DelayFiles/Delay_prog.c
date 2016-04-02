/*
 * Delay_prog.c
 *
 *  Created on: Feb 8, 2016
 *      Author: mahmoud
 */

/*
#ifndef DELAY_PROG_H_
#define DELAY_PROG_H_
*/

#include"Delay.h"
#define Delay(n) do{ u32 i; for(i=0; i <= ((n*DELAY_u32SYSCLOCK)/40000)+15 ;i++) {  __asm__("NOP"); }  }while(0)

/*#endif  DELAY_H_ */
