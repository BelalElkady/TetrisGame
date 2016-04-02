/*
 * ADC_Private.h
 *
 *  Created on: Mar 13, 2016
 *      Author: mahmoud
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define conc(x7,x6,x5,x4,x3,x2,x1,x0)    helper(x0,x1,x2,x3,x4,x5,x6,x7)
#define helper(y0,y1,y2,y3,y4,y5,y6,y7) 0b##y7##y6##y5##y4##y3##y2##y1##y0


#define ADC_u8privADMUX   conc(ADC_u8voltageRefSelection1,ADC_u8voltageRefSelection0,ADC_u8TheReadingDirection,0,0,0,0,0 )
#define ADC_u8privADCSRA  conc(ADC_u8startState,0,ADC_u8AutoTriger,0,ADC_u8InteruptEnable,ADC_u8Prescaler2,ADC_u8Prescaler1,ADC_u8Prescaler0 )

/*******************************************************************/
/****************PRIVATE Definitions*********************************/
/*******************************************************************/

#define ADC_ADCSRA                     *((volatile u8*)(0x26))
#define ADC_ADMUX                      *((volatile u8*)(0x27))
#define ADC_ADCL                       *((volatile u8*)(0x24))
#define ADC_ADCH                       *((volatile u8*)(0x25))
// ADCSRA BITS
#define ADC_U8ADCSRA_REFS1 7
#define ADC_U8ADCSRA_REFS0 6
#define ADC_U8ADCSRA_ADLAR 5
#define ADC_U8ADCSRA_MUX4  4
#define ADC_U8ADCSRA_MUX3  3
#define ADC_U8ADCSRA_MUX2  2
#define ADC_U8ADCSRA_MUX1  1
#define ADC_U8ADCSRA_MUX0  0

//ADMUX BITS
#define ADC_U8ADMUX_ADEN   7
#define ADC_U8ADMUX_ADSC   6
#define ADC_U8ADMUX_ADATE  5
#define ADC_U8ADMUX_ADIF   4
#define ADC_U8ADMUX_ADIE   3
#define ADC_U8ADMUX_ADPS2  2
#define ADC_U8ADMUX_ADPS1  1
#define ADC_U8ADMUX_ADPS0  0



#define ADC_u8RIGHTADJUST 0
#define ADC_u8LEFTADJUST  1

#define ADC_u8Vref 5
#define ADC_u16maxNoInADC 1024
#endif /* ADC_PRIVATE_H_ */
