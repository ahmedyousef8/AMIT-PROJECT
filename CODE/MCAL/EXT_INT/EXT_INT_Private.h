/*Includes*/
#include "STD_TYPES.h"


/*Guard*/
#ifndef _EXT_INT_PRIVATE_H
#define _EXT_INT_PRIVATE_H


/* MEMORY ADDRESSES */

#define GICR    	 *((volatile u8*)(0x5B))
#define GIFR		 *((volatile u8*)(0x5A))
#define MCUCR    	 *((volatile u8*)(0x55))
#define MCUCSR    	 *((volatile u8*)(0x54))



/* Sense Modes */

#define EXTI0_LOW       0
#define EXTI0_ANY_LC	1
#define EXTI0_FALLING	2
#define EXTI0_RISING	3

#define EXTI1_LOW       0
#define EXTI1_ANY_LC	1
#define EXTI1_FALLING	2
#define EXTI1_RISING	3

#define EXTI2_FALLING	0
#define EXTI2_RISING	1

#define EXTI0	0
#define EXTI1	1
#define EXTI2	2


/* Sense Mode Bit for  EXTI2 in MCUCR */

#define ISC2	6

/* Enable Pin Bit for EXTI0,1,2 in GICR */

#define INT0	6
#define INT1	7
#define INT2	5

/* Interrupt Flag Bit for EXTI0,1,2 in GIFR */

#define INTF0	6
#define INTF1	7
#define INTF2	5


/*** VECTOR TABLE ***/

#define	EXTI0_VECT			__vector_1
#define	EXTI1_VECT			__vector_2
#define	EXTI2_VECT			__vector_3
#define	TIMER2_COMP_VECT	__vector_4
#define	TIMER2_OVF_VECT		__vector_5
#define	TIMER1_CAPT_VECT	__vector_6
#define	TIMER1_COMPA_VECT	__vector_7
#define	TIMER1_COMPB_VECT	__vector_8
#define	TIMER1_OVF_VECT		__vector_9
#define	TIMER0_COMP_VECT	__vector_10
#define	TIMER0_OVF_VECT		__vector_11
#define	SPI_STC_VECT		__vector_12
#define	UART_RXC_VECT		__vector_13
#define	UART_UDRE_VECT		__vector_14
#define	UART_TXC_VECT		__vector_15
#define	ADC_VECT			__vector_16
#define	EE_RDY_VECT			__vector_17
#define	ANA_COMP_VECT		__vector_18
#define	TWI_VECT			__vector_19
#define	SPM_RDY_VECT		__vector_20


/* Interrupt Assembly Functions */

#define	ISR(vector)	void vector(void) __attribute__((signal)); \
					void vector(void)

#define sei()	__asm__ __volatile__ ("sei" ::)	// Opens Global Interrupt
#define cli()	__asm__ __volatile__ ("cli" ::)	// Closes Global Interrupt
#define reti()	__asm__ __volatile__ ("reti" ::)
#define ret()	__asm__ __volatile__ ("ret" ::)

#define	ISR_NOBLOCK		__attribute__((interrupt))
#define	ISR_NAKED		__attribute__((naked))


#endif
