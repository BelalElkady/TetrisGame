/*
 * ADC_Prog.c
 *
 *  Created on: Mar 13, 2016
 *      Author: mahmoud
 */

#include"../headerfiles/types.h"
#include "../headerfiles/util.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"

/*comment:! to initialize  the ADC */
void ADC_voidinit(void)
{
//	ADC_ADCSRA
    ADC_ADCSRA=ADC_u8privADCSRA;
//	ADC_ADMUX
	ADC_ADMUX=ADC_u8privADMUX;
}

/*comment:! to ReadChannelFiltered (3 reading /3)  the ADC */

extern u16 ADC_u16ReadChannelFiltered(u8 copy_u8ChannelNo,u8 *copy_u8completeflag){}

/*comment:! to ADC_u16ReadChannelOneShot  the ADC  dont forget to enable the adc befor using this api */
extern u16 ADC_u16ReadChannelOneShot(u8 copy_u8ChannelNo,u8 *copy_u8completeflag) {
		u16 local_u16valToReturn=0;
		u8 local_u8tempLowval=0;
	//configure the channel
	if (copy_u8ChannelNo >= ADC_U8Channel1 && copy_u8ChannelNo <= ADC_U8Channel8) {

		ADC_ADMUX &=0b11111000;
		ADC_ADMUX |= copy_u8ChannelNo;
		//TODO make it none bussy loop and use the complete flag
		//wait fr the convertion to happens
		//wait till the adc flag is set
		//start conversion
	    ADC_ADCSRA = Setbit(ADC_ADCSRA, ADC_U8ADMUX_ADSC);
		while(GetBit(ADC_ADCSRA,ADC_U8ADMUX_ADIF)==0)
				{}

		switch (ADC_u8TheReadingDirection) {
		case ADC_u8RIGHTADJUST:
			local_u8tempLowval=ADC_ADCL;
			local_u16valToReturn=ADC_ADCH;
			local_u16valToReturn<<=8;
			local_u16valToReturn|=local_u8tempLowval;
			break;
		case ADC_u8LEFTADJUST:
			local_u8tempLowval=ADC_ADCL;
			local_u8tempLowval>>=6;
			local_u16valToReturn=ADC_ADCH;
			local_u16valToReturn<<=2;
			local_u16valToReturn|=local_u8tempLowval;
			break;
		default:

			break;

		}
		ADC_ADCSRA=Setbit(ADC_ADCSRA,ADC_U8ADMUX_ADIF);
	} else {

	}
return(local_u16valToReturn);
}

/*comment:! to ADC_structReadGroup from copy_u8FirstADCToRead to  copy_u8LastADCToRead  the ADC */
extern ADC_StructADCAll ADC_structReadGroup(u8 copy_u8FirstADCToRead,u8 copy_u8LastADCToRead){}

/*comment:! to  Enable  the ADC */
extern void ADC_voidEnable(void) {
	ADC_ADCSRA = Setbit(ADC_ADCSRA, ADC_U8ADMUX_ADEN);
}
/*comment:! to  disable  the ADC */
extern void ADC_voidDisable(void) {
	ADC_ADCSRA = Clrbit(ADC_ADCSRA, ADC_U8ADMUX_ADEN);
}

/*
extern s16 ADC_u8voidVoltageConvertion(u16 copy_u16ADCResult)
{s16 local_u8ADCResult =0;

local_u8ADCResult=u8((copy_u16ADCResult*ADC_u8Vref)/ADC_u16maxNoInADC);

}*/
