#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

// if you want to make the start state of the ADC ENABLED 1 Disabled 0;
#define ADC_u8startState 0
// for further use initially  0
#define ADC_u8AutoTriger 0

//to enable the interupt of the adc
// initialy 0
#define ADC_u8InteruptEnable 0

//the pre scaler
/*
 *
 ADPS2 ADPS1 ADPS0 Division Fact
 0-->0 0 0 -->2
 1-->0 0 1 -->2
 2-->0 1 0 -->4
 3-->0 1 1 -->8
 4-->1 0 0 -->16
 5-->1 0 1 -->32
 6-->1 1 0 -->64
 7-->1 1 1 -->128
 */
//normally  the slowest precaler
#define ADC_u8Prescaler0 1
#define ADC_u8Prescaler1 1
#define ADC_u8Prescaler2 1


//voltage ref selection for the ADC
/*REFS1 REFS0 Voltage Reference Selection
 * 0  --> 0 0 AREF, Internal Vref turned off
 * 1  --> 0 1 AVCC with external capacitor at AREF pin
 * 2  --> 1 0 Reserved
 * 3  --> 1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
 *
 * */
//by default 1
#define ADC_u8voltageRefSelection0 1
#define ADC_u8voltageRefSelection1 0


// if you want to read from ADCH ADCL 0 RIGHT ADJUCT 1 LEFT ADJUST
#define ADC_u8TheReadingDirection 1

#endif /* ADC_INTERFACE_H_ */
