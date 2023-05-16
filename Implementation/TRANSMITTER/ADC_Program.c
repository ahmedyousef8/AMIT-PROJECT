/* Includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Private.h"
#include "ADC_Interface.h"

#include <util/delay.h>



void ADC_INIT (void)
{
	/*
					REFERENCE SELECTION BITS
					
	AREF, Internal Vref turned off:											0 0
	AVCC with external capacitor at AREF pin:								0 1
	Reserved:																1 0
	Internal 2.56V Voltage Reference with external capacitor at AREF pin:	1 1
	
	*/
	
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
	
	/* ADC LEFT ADJUST RESULT */
	
	CLR_BIT(ADMUX, ADLAR); // Right adjust: 0		Left adjust: 1
	
	/* ADC ENABLE */
	
	SET_BIT(ADCSRA, ADEN);
	
	/* ADC PRESCALER SELECTION */
	
	ADCSRA |= ADC_PS;
	
}



u16 ADC_Read (u8 Copy_u8Channel)
{
		if (Copy_u8Channel >= 0 && Copy_u8Channel < 8)
	{
		/* SET_BIT(ADC_REG_ADMUX, ADC_MUX0);
		CLR_BIT(ADC_REG_ADMUX, ADC_MUX1);
		CLR_BIT(ADC_REG_ADMUX, ADC_MUX2); */
		ADMUX &= 0xE0;
		ADMUX |= Copy_u8Channel;
	}
	else
	{
		//do nothing
	}
	
	SET_BIT(ADCSRA,ADSC);
	
	while (!GET_BIT(ADCSRA,ADIF)); // Wait for the ADC Interrupt Flag to be set

	_delay_us(10);
	
	return (u16) (ADCL + (ADCH << 8));
}