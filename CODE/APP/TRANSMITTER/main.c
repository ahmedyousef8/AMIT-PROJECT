/*
 * proj_trans.c
 *
 * Created: 14/03/2023 2:04:20 AM
 * Author : Softlaptop
 */ 
#define F_CPU 8000000UL

#define ForwardCondition	(x[1] > 500 && x[2] < 500 && x[3] < 500 && x[4] < 500)
#define BackwardCondition	(x[2] > 500 && x[1] < 500 && x[3] < 500 && x[4] < 500)
#define RightCondition		(x[3] > 500 && x[2] < 500 && x[1] < 500 && x[4] < 500)
#define LeftCondition		(x[4] > 500 && x[2] < 500 && x[3] < 500 && x[1] < 500)


/* Include libs */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include <util/delay.h>
#include "UART_Private.h"
#include "ADC_Private.h"
#include "uart.h"



int main(void)
{
	
	u16 x[5] = {0};
	u8 i, flag;
	
	DIO_voidSetPortDirection(PORTA,INPUT);
    UART_Init();
	ADC_INIT();
	

    while (1) 
    {
		flag = 0;
		x[0] = ADC_Read(0);
		
		for (i=1; i<5; i++)
		{
			x[i] = ADC_Read(i+3);
			
		}
		
		if (ForwardCondition)
		{
			UART_Send('F');
		}
		else if (BackwardCondition)
		{
			UART_Send('B');
		}
		else if (RightCondition)
		{
			UART_Send('R');
		}
		else if (LeftCondition)
		{
			UART_Send('L');
		}
		else
		{
			UART_Send('S');
			flag = 1;
		}
		
		if (!flag)
		{
			u8 speed=((x[0]/1023.0)*100)+100;
			UART_Send(speed);
		}
		
    }
}
