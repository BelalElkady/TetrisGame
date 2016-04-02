/*
 * ADC_Interface.h
 *
 *  Created on: Mar 13, 2016
 *      Author: mahmoud
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct{
	u16 ADC_u16readvalADC0;
	u16 ADC_u16readvalADC1;
	u16 ADC_u16readvalADC2;
	u16 ADC_u16readvalADC3;
	u16 ADC_u16readvalADC4;
	u16 ADC_u16readvalADC5;
	u16 ADC_u16readvalADC6;
	u16 ADC_u16readvalADC7;
} ADC_StructADCAll;



#define ADC_U8Channel1 0
#define ADC_U8Channel2 1
#define ADC_U8Channel3 2
#define ADC_U8Channel4 3
#define ADC_U8Channel5 4
#define ADC_U8Channel6 5
#define ADC_U8Channel7 6
#define ADC_U8Channel8 7

/*comment:! to initialize  the ADC */
void ADC_voidinit(void);

/*comment:! to ReadChannelFiltered (3 reading /3)  the ADC */

u16 ADC_u16ReadChannelFiltered(u8 copy_u8ChannelNo,u8 *copy_u8completeflag);

/*comment:! to ADC_u16ReadChannelOneShot  the ADC */
u16 ADC_u16ReadChannelOneShot(u8 copy_u8ChannelNo,u8 *copy_u8completeflag);

/*comment:! to ADC_structReadGroup from copy_u8FirstADCToRead to  copy_u8LastADCToRead  the ADC */
ADC_StructADCAll ADC_structReadGroup(u8 copy_u8FirstADCToRead,u8 copy_u8LastADCToRead);

/*comment:! to  Enable  the ADC */
extern void ADC_voidEnable(void);
/*comment:! to  disable  the ADC */
extern void ADC_voidDisable(void);

#endif /* ADC_INTERFACE_H_ */
