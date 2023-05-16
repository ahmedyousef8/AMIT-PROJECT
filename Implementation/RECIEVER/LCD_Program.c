/* Include libs */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */

#include "DIO_Interface.h"
#include "DIO_Private.h"

#include <util/delay.h>
#include "LCD_Interface.h"

/* Implementation file */

#if (LCD_MODE == LCD_8BIT)

void LCD_Init(void)
{
	/* init sequence for 8 bit mode LCD : Page 13 in data sheet*/
	
	/* delay for more than 30 ms*/
	
	_delay_ms(70);
	
	/* Function Set: Sets interface data length */
	
    LCD_voidSendCMD(FN_SET_8bit); 
	
	_delay_ms(3);
	
	/* Display ON/OFF Control */
	
	LCD_voidSendCMD(DIS_MODE);
	
	_delay_ms(3);
	
	/* Display Clear: Clears entire display and sets DDRAM address to 00H. */
	
	LCD_voidSendCMD(DIS_CLR);
	
	_delay_ms(6);
	
	/* Entry Mode Set: Sets cursor move direction and enable the shift of entire display */
	
	LCD_voidSendCMD(ENTR_MODE);
	_delay_ms(3);
	
	LCD_voidSendCMD(0x80);
}




void LCD_voidWriteData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue (PORT_CTRL ,RS ,HIGH );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );
	
	/* SEND THE DATA */
	DIO_voidSetPortValue (PORT_DATA, Copy_u8Data);

	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);

}




void LCD_voidSendCMD (u8 Copy_u8CMD)
{
	/* CHANGE RS TO LOW TO SEND COMMAND */
	
	DIO_voidSetPinValue (PORT_CTRL ,RS ,LOW );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );	
	
	/* SEND THE COMMAND */
	DIO_voidSetPortValue (PORT_DATA, Copy_u8CMD);

	/* LATCH ENABLE */
		
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);
	
}


#elif (LCD_MODE == LCD_4BIT)

void LCD_Init(void)
{
	/* init sequence for 4 bit mode LCD : Page 14 in data sheet*/
	
	/* delay for more than 30 ms*/
	
	_delay_ms(70);
	
	/* Function Set: Sets interface data length */
	
    LCD_voidSendCMD(0x02); 
	LCD_voidSendCMD(FNSET_4bit);
	
	_delay_ms(3);
	
	/* Display ON/OFF Control */
	
	LCD_voidSendCMD(DIS_MODE);
	
	_delay_ms(3);
	
	/* Display Clear: Clears entire display and sets DDRAM address to 00H. */
	
	LCD_voidSendCMD(DIS_CLR);
	
	_delay_ms(6);
	
	/* Entry Mode Set: Sets cursor move direction and enable the shift of entire display */
	
	LCD_voidSendCMD(ENTR_MODE);
	_delay_ms(3);

	LCD_voidSendCMD(0x80);
}

void LCD_voidWriteData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue (PORT_CTRL ,RS ,HIGH );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );
	
	/* SEND THE 4 HIGHEST BITS OF DATA */
	DIO_voidSetPinValue (PORT_DATA, D4, GET_BIT(Copy_u8Data, 4));
	DIO_voidSetPinValue (PORT_DATA, D5, GET_BIT(Copy_u8Data, 5));
	DIO_voidSetPinValue (PORT_DATA, D6, GET_BIT(Copy_u8Data, 6));
	DIO_voidSetPinValue (PORT_DATA, D7, GET_BIT(Copy_u8Data, 7));

	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);
	
	/* SEND THE 4 LOWEST BITS OF DATA */

	DIO_voidSetPinValue (PORT_DATA, D4, GET_BIT(Copy_u8Data, 0));
	DIO_voidSetPinValue (PORT_DATA, D5, GET_BIT(Copy_u8Data, 1));
	DIO_voidSetPinValue (PORT_DATA, D6, GET_BIT(Copy_u8Data, 2));
	DIO_voidSetPinValue (PORT_DATA, D7, GET_BIT(Copy_u8Data, 3));
	
	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);

}

void LCD_voidSendCMD (u8 Copy_u8CMD)
{
	/* CHANGE RS TO LOW TO SEND COMMAND */
	
	DIO_voidSetPinValue (PORT_CTRL ,RS ,LOW );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );	
	
	/* SEND THE 4 HIGHEST BITS OF COMMAND */
	DIO_voidSetPinValue (PORT_DATA, D4, GET_BIT(Copy_u8CMD, 4));
	DIO_voidSetPinValue (PORT_DATA, D5, GET_BIT(Copy_u8CMD, 5));
	DIO_voidSetPinValue (PORT_DATA, D6, GET_BIT(Copy_u8CMD, 6));
	DIO_voidSetPinValue (PORT_DATA, D7, GET_BIT(Copy_u8CMD, 7));

	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);
	
	/* SEND THE 4 LOWEST BITS OF COMMAND */

	DIO_voidSetPinValue (PORT_DATA, D4, GET_BIT(Copy_u8CMD, 0));
	DIO_voidSetPinValue (PORT_DATA, D5, GET_BIT(Copy_u8CMD, 1));
	DIO_voidSetPinValue (PORT_DATA, D6, GET_BIT(Copy_u8CMD, 2));
	DIO_voidSetPinValue (PORT_DATA, D7, GET_BIT(Copy_u8CMD, 3));
	
	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(3);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(3);
}

#endif

/* implement a function to write string */

void LCD_voidWriteString (u8* Copy_pu8String)
{
	
	/* what could go wrong? */
	
	while (*Copy_pu8String != '\0')
	{
		/* write char, inc to the next char */
		
		LCD_voidWriteData(*Copy_pu8String);
		Copy_pu8String++;
	}
	
}


void LCD_voidWriteNumber (s32 Copy_s32Number)
{
	u8 i=0, j, arr[16];
	
	if (Copy_s32Number == 0)
	{
		LCD_voidWriteData('0');
	}
	else
	{
		if (Copy_s32Number < 0)
		{
			Copy_s32Number *= -1;
			LCD_voidWriteData ('-');
		}
		while (Copy_s32Number > 0)
		{
			arr[i] = (Copy_s32Number % 10)+'0';
			Copy_s32Number /= 10;
			i++;
		}
		
		for(j=i; j>0; j--)
		{
			 LCD_voidWriteData(arr[j-1]);
		}
		
	}

}


void LCD_voidClrDisplay (void)
{
	
	LCD_voidSendCMD(DIS_CLR);
	_delay_ms(6);
	
}



void LCD_GoTo (u8 Copy_u8Line, u8 Copy_u8Position)
{
	if (Copy_u8Line == 1)
	{
		LCD_voidSendCMD(0x80+Copy_u8Position);	//	0	0	1	AC6	AC5	AC4	AC3	AC2	AC1	AC0
	}
	else if (Copy_u8Line == 2)
	{
		LCD_voidSendCMD(0x80+0x40+Copy_u8Position);	//SECOND LINE STARTS FROM 0x40
	}
}

void LCD_CreateCharacter(u8* Copy_pu8Pattern, u8 Copy_u8Address)
{
	u8 i;
	LCD_voidSendCMD (0x40+Copy_u8Address*8);	//Set CGRAM address in address counter (every block in CGRAM has 8 bytes)
	for (i=0; i<8; i++)
	{
	LCD_voidWriteData (Copy_pu8Pattern[i]); //Write data into internal RAM (DDRAM/CGRAM)
	}	
	
}

void LCD_Cursor (u8 Copy_u8Status)
{
	if (Copy_u8Status == CURSOR_ON)
	{
		LCD_voidSendCMD(0x0F);
	} 
	else
	{
		LCD_voidSendCMD(0x0C);
	}
	
}

void LCD_voidAnimateString (u8* Copy_pu8String)
{
	
	/* what could go wrong? */
	
	while (*Copy_pu8String != '\0')
	{
		/* write char, inc to the next char */
		
		LCD_voidWriteData(*Copy_pu8String);
		Copy_pu8String++;
		_delay_ms(200);
	}
	
}