/* Includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"




/* GUARD */

#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H


#define ADC_PS		ADC_PS64



/* NEEDED REG ADDRESSES */

#define ACSR		*((volatile u8*)(0x28))

/* MEMORY PLACES FOR MULTIPLEXER CHOICE */
#define ADMUX		*((volatile u8*)(0x27))

/*ADC ENABLE AND CTRL REG */
#define ADCSRA		*((volatile u8*)(0x26))

/* REGS THAT SAVE THE CONVERSION RESULT */
#define ADCH		*((volatile u8*)(0x25))
#define ADCL		*((volatile u8*)(0x24))


#define REFS0			6
#define REFS1			7


#define ADLAR			5

#define MUX0			0
#define MUX1			1
#define MUX2			2

#define ADEN			7
#define ADSC			6
#define ADIF			4


#define ADC_PS2				1
#define ADC_PS4				2
#define ADC_PS8				3
#define ADC_PS16			4
#define ADC_PS32			5
#define ADC_PS64			6
#define ADC_PS128			7





#endif