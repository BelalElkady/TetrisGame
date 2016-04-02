/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: m.mamdooh
 */

#include "Delay_config.h"
#ifndef DELAY_H_
#define DELAY_H_
#define DELAY(Copy_u8DelayVal)  do{ \
							u32 x,y=Copy_u8DelayVal;\
							 while(y --){x=2600; while(x--);}\
							} while(0)
#endif /* DELAY_H_ */
