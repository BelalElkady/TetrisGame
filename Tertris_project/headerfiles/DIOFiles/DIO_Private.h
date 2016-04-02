/*
 * DIO_Private.h
 *
 *  Created on: Jan 27, 2016
 *      Author: nada
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define conc(x0,x1,x2,x3,x4,x5,x6,x7)    helper(x0,x1,x2,x3,x4,x5,x6,x7)
#define helper(y0,y1,y2,y3,y4,y5,y6,y7) 0b##y7##y6##y5##y4##y3##y2##y1##y0

#define DIO_u8PINSPERPORT 8

#define DIO_u8PORTADIR   conc(DIO_u8PIN0_INITDIR ,DIO_u8PIN1_INITDIR ,DIO_u8PIN2_INITDIR ,DIO_u8PIN3_INITDIR ,DIO_u8PIN4_INITDIR ,DIO_u8PIN5_INITDIR ,DIO_u8PIN6_INITDIR ,DIO_u8PIN7_INITDIR )
#define DIO_u8PORTBDIR   conc(DIO_u8PIN8_INITDIR ,DIO_u8PIN9_INITDIR ,DIO_u8PIN10_INITDIR ,DIO_u8PIN11_INITDIR ,DIO_u8PIN12_INITDIR ,DIO_u8PIN13_INITDIR ,DIO_u8PIN14_INITDIR ,DIO_u8PIN15_INITDIR )
#define DIO_u8PORTCDIR   conc(DIO_u8PIN16_INITDIR ,DIO_u8PIN17_INITDIR ,DIO_u8PIN18_INITDIR ,DIO_u8PIN19_INITDIR ,DIO_u8PIN20_INITDIR ,DIO_u8PIN21_INITDIR ,DIO_u8PIN22_INITDIR ,DIO_u8PIN23_INITDIR )
#define DIO_u8PORTDDIR   conc(DIO_u8PIN24_INITDIR ,DIO_u8PIN25_INITDIR ,DIO_u8PIN26_INITDIR ,DIO_u8PIN27_INITDIR ,DIO_u8PIN28_INITDIR ,DIO_u8PIN29_INITDIR ,DIO_u8PIN30_INITDIR ,DIO_u8PIN31_INITDIR )

#define DIO_u8ValuePortA conc(DIO_u8PIN0_INITVAL,DIO_u8PIN1_INITVAL,DIO_u8PIN2_INITVAL,DIO_u8PIN3_INITVAL,DIO_u8PIN4_INITVAL,DIO_u8PIN5_INITVAL,DIO_u8PIN6_INITVAL,DIO_u8PIN7_INITVAL)
#define DIO_u8ValuePortB conc(DIO_u8PIN8_INITVAL,DIO_u8PIN9_INITVAL,DIO_u8PIN10_INITVAL,DIO_u8PIN11_INITVAL,DIO_u8PIN12_INITVAL,DIO_u8PIN13_INITVAL,DIO_u8PIN14_INITVAL,DIO_u8PIN15_INITVAL)
#define DIO_u8ValuePortC conc(DIO_u8PIN16_INITVAL,DIO_u8PIN17_INITVAL,DIO_u8PIN18_INITVAL,DIO_u8PIN19_INITVAL,DIO_u8PIN20_INITVAL,DIO_u8PIN21_INITVAL,DIO_u8PIN22_INITVAL,DIO_u8PIN23_INITVAL)
#define DIO_u8ValuePortD conc(DIO_u8PIN24_INITVAL,DIO_u8PIN25_INITVAL,DIO_u8PIN26_INITVAL,DIO_u8PIN27_INITVAL,DIO_u8PIN28_INITVAL,DIO_u8PIN29_INITVAL,DIO_u8PIN30_INITVAL,DIO_u8PIN31_INITVAL)

#define PORTA                     *((volatile u8*)(0x3B))
#define DDRA                      *((volatile u8*)(0x3A))
#define PINA                      *((volatile u8*)(0x39))

#define PORTB                     *((volatile u8*)(0x38))
#define DDRB                      *((volatile u8*)(0x37))
#define PINB                      *((volatile u8*)(0x36))

#define PORTC                     *((volatile u8*)(0x35))
#define DDRC                      *((volatile u8*)(0x34))
#define PINC                      *((volatile u8*)(0x33))

#define PORTD                     *((volatile u8*)(0x32))
#define DDRD                      *((volatile u8*)(0x31))
#define PIND                      *((volatile u8*)(0x30))

#endif /* DIO_PRIVATE_H_ */
