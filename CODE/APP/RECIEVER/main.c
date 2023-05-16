/*
 * GccApplication2.c
 *
 * Created: 3/7/2023 8:12:10 PM
 * Author : ahmed
 */ 
#define F_CPU     8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DC_Motor_Interface.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "DC_Motor_Interface.h"
#include "LCD_Interface.h"
#include "uart.h"
#include "UART_PRIVATE.h"
#include <util/delay.h>



int main(void)
{
//PIN INITIALIZATION FOR THE MOTORS

    DIO_voidSetPinDirection(PORTD, PIN4, OUTPUT);
    DIO_voidSetPinDirection(PORTD, PIN5, OUTPUT);

	DIO_voidSetPortDirection(PORTC,OUTPUT);

//PIN INITIALIZATION FOR THE LCD

	DIO_voidSetPortDirection(PORT_DATA,OUTPUT);
	DIO_voidSetPortDirection(PORT_CTRL,OUTPUT);
	
//MODULES INIT

	LCD_Init();	
	PWM_INIT();
	UART_Init ();
// RECIEVING VARIABLES	
	u8 ReceivedData = 0, CurrentState = 'S', SPEED = 100 /*, i, nSpeed*/;
	u8 name1[]= "CONTROLLING CAR", name2[]="WITH HAND MOTION";
	
	LCD_Cursor(CURSOR_ON);
	LCD_voidAnimateString(name1);
	LCD_GoTo(2,0);
	LCD_voidAnimateString(name2);
	_delay_ms(1200);
	LCD_Cursor(CURSOR_OFF);
	LCD_voidClrDisplay();

	
    while (1) 
    {
		ReceivedData = UART_Receive();
	
		if (ReceivedData != CurrentState && ReceivedData != SPEED)
		{
			if(ReceivedData == 'L')
			{
				CurrentState = 'L';
				M_Left();
				LCD_GoTo(1,0);
				LCD_voidWriteString("TURNING LEFT    ");
			}
			else if(ReceivedData == 'R')
			{
				CurrentState = 'R';
				M_Right();
				LCD_GoTo(1,0);
				LCD_voidWriteString("TURNING RIGHT   ");
			}
			else if(ReceivedData == 'F')
			{
				CurrentState = 'F';
				M_Forward();
				LCD_GoTo(1,0);
				LCD_voidWriteString("MOVING FORWARDS ");
			}
			else if(ReceivedData == 'B')
			{
				CurrentState = 'B';
				M_Backward();
				LCD_GoTo(1,0);
				LCD_voidWriteString("MOVING BACKWARDS");
			}
			else if(ReceivedData == 'S')
			{
				CurrentState = 'S';
				M_Stop();
				LCD_voidClrDisplay();
				LCD_voidWriteString("MOTORS STOPPED  ");
			}
			else if(ReceivedData >= 100 && ReceivedData <= 200)
			{
				SPEED = ReceivedData-100;
				PWM(SPEED);
				LCD_GoTo(2,0);
				LCD_voidWriteNumber(SPEED);
				LCD_voidWriteString("  ");
				/*
				nSpeed = (SPEED/100.0)*16;
				for (i=0; i<16; i++)
				{
					if (i < nSpeed)
					{
						LCD_voidWriteData(0xFF);
					} 
					else
					{
						LCD_voidWriteData(0);
					}
				*/
					
				}
			}

		}
	}
}
