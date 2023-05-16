/* Include libs */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */

#include "DIO_Interface.h"
#include "DIO_Private.h"

/* GUARD */

#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/* details about the LCD to ease readability */

#define	LCD_4BIT	4
#define	LCD_8BIT	8

#define	LCD_MODE	LCD_4BIT


#define PORT_DATA PORTA
#define PORT_CTRL PORTB

#define RS PIN1
#define RW PIN2
#define EN PIN3
#define D4 PIN4
#define D5 PIN5
#define D6 PIN6
#define D7 PIN7

#define CURSOR_OFF		0
#define CURSOR_ON		1

#define FNSET_4bit 		0x28	/*	0	0	1	DL	N	F	X	X	
									DL: Data Length (0 --> 4bit OR 1 --> 8bit)
									N: Number Of Lines (0 --> 1 line OR 1 --> 2 lines)
									F: Character Font (0 --> 5*7 OR 1 --> 5*10)
								*/



#define FN_SET_8bit		0x38	/*	0	0	1	DL	N	F	X	X	
									DL: Data Length (0 --> 4bit OR 1 --> 8bit)
									N: Number Of Lines (0 --> 1 line OR 1 --> 2 lines)
									F: Character Font (0 --> 5*7 OR 1 --> 5*10)
								*/
											
											
#define DIS_MODE 		0x0C	/*	0	0	0	0	1	D	C	B
									D: Set ON/OFF of entire display
									C: cursor ON/OFF
									B: blinking of cursor position character
								*/

#define DIS_CLR 		0x01

#define ENTR_MODE 		0x06	/*	0	0	0	0	0	1	I/D	S
									I/D: Sets the move direction of cursor and display; Increases (I/D = 1) or decreases (ID = 0)
									S: Shifts the entire display when S = 1; shifts to the left when I/D = 1 and to the right when I/D = 0;
									When S = 0, the display does not shift.
								*/								

/* function for the LCD driver

0- Init finction
1- function to write command
2- function to write data

*/

void LCD_Init(void);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidSendCMD (u8 Copy_u8CMD);
void LCD_voidWriteString (u8* Copy_pu8String);
void LCD_voidWriteNumber (s32 Copy_s32Number);
void LCD_voidClrDisplay (void);
void LCD_GoTo (u8 Copy_u8Line, u8 Copy_u8Position);
void LCD_CreateCharacter(u8* Copy_pu8Pattern, u8 Copy_u8Address);
void LCD_Cursor (u8 Copy_u8Status);
void LCD_voidAnimateString (u8* Copy_pu8String);

#endif