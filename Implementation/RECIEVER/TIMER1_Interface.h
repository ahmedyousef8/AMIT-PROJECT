#ifndef _TIMER1_INTERFACE_H
#define _TIMER1_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1A_F0C1B 2
#define TCCR1A_F0C1A 3
#define TCCR1A_COM1B0 4
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7
#define TCCR1B_CS10 0
#define TCCR1B_CS11 1
#define TCCR1B_CS12 2
#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4
#define TCCR1B_ICES1 6
#define TCCR1B_ICNC1 7
#define TIMSK_TICIE1 5 
#define TIMSK_OCIE1A 4
#define TIMSK_OCIE1B 3 
#define TIMSK_TOIE1 2


//timer_functions
void PWM_INIT(void);
void PWM(u8 dutyCycle);
void TIMR1_Stop(void);






#endif