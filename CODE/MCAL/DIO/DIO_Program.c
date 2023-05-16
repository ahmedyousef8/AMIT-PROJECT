/*INCLUDES from lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*includes from DIO driver*/
#include "DIO_Private.h"
#include "DIO_Interface.h"


/* implementation of functions*/

void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir)
{
	if((Copy_u8Port >= 0) && (Copy_u8Port <4))
	{
		/*execute*/
		if ((Copy_u8Pin >= 0) && (Copy_u8Pin < 8))
		{
			/*execute*/
			if (Copy_u8Dir == OUTPUT )
			{
				switch(Copy_u8Port)
				{
				case PORTA : SET_BIT(REG_DDRA, Copy_u8Pin); break;
				case PORTB : SET_BIT(REG_DDRB, Copy_u8Pin); break;
				case PORTC : SET_BIT(REG_DDRC, Copy_u8Pin); break;
				case PORTD : SET_BIT(REG_DDRD, Copy_u8Pin); break;
				}

			}
			else if (Copy_u8Dir == INPUT )
			{
				switch(Copy_u8Port)
				{
				case PORTA : CLR_BIT(REG_DDRA, Copy_u8Pin); break;
				case PORTB : CLR_BIT(REG_DDRB, Copy_u8Pin); break;
				case PORTC : CLR_BIT(REG_DDRC, Copy_u8Pin); break;
				case PORTD : CLR_BIT(REG_DDRD, Copy_u8Pin); break;
				}
			}

		}
		else
		{
			//do nothing
		}

	}
	else
	{
		// do nothing
	}
}




void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Dir)
{
	if ((Copy_u8Port >= 0) && (Copy_u8Port < 4))
	{
		/*execute*/
		if (Copy_u8Dir == OUTPUT )
		{
			switch(Copy_u8Port)
			{
			case PORTA : REG_DDRA = 0xFF; break;
			case PORTB : REG_DDRB = 0xFF; break;
			case PORTC : REG_DDRC = 0xFF; break;
			case PORTD : REG_DDRD = 0xFF; break;
            }

        }
		else if (Copy_u8Dir == INPUT )
		{
			switch(Copy_u8Port)
			{
				case PORTA : REG_DDRA = 0; break;
				case PORTB : REG_DDRB = 0; break;
				case PORTC : REG_DDRC = 0; break;
				case PORTD : REG_DDRD = 0; break;
			}
		}


		else
		{
		//do nothing
		}
	}
    else
    {
	// do nothing
	}
}




void DIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val){
	if((Copy_u8Port >= 0) && (Copy_u8Port <4))
	{
		/*execute*/
		if ((Copy_u8Pin >= 0) && (Copy_u8Pin < 8))
		{
			/*execute*/
			if (Copy_u8Val == HIGH )
			{
				switch(Copy_u8Port)
				{
					case PORTA : SET_BIT(REG_PORTA, Copy_u8Pin); break;
					case PORTB : SET_BIT(REG_PORTB, Copy_u8Pin); break;
					case PORTC : SET_BIT(REG_PORTC, Copy_u8Pin); break;
					case PORTD : SET_BIT(REG_PORTD, Copy_u8Pin); break;
				}
			}
			else if (Copy_u8Val == LOW )
			{
				switch(Copy_u8Port)
				{
					case PORTA : CLR_BIT(REG_PORTA, Copy_u8Pin); break;
					case PORTB : CLR_BIT(REG_PORTB, Copy_u8Pin); break;
					case PORTC : CLR_BIT(REG_PORTC, Copy_u8Pin); break;
					case PORTD : CLR_BIT(REG_PORTD, Copy_u8Pin); break;
				}
			}

		}
		else
		{
			//do nothing
		}

	}
	else
	{
		// do nothing
	}
}


/* FUNCTION THAT ASSIGNS A CERTAIN VALUE TO A SELECTED PORT */

void DIO_voidSetPortValue (u8 Copy_u8Port, u8 Copy_u8Val){
	if ((Copy_u8Port >= 0) && (Copy_u8Port < 4))
	{
		/*execute*/
			switch(Copy_u8Port)
			{
				case PORTA : REG_PORTA = Copy_u8Val; break;
				case PORTB : REG_PORTB = Copy_u8Val; break;
				case PORTC : REG_PORTC = Copy_u8Val; break;
				case PORTD : REG_PORTD = Copy_u8Val; break;
			}
		
	}
	else
	{
	// do nothing
	}
}




/* gets the value in the desired pin */
u8 DIO_u8GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin){
	u8 Copy_u8Val;
	if((Copy_u8Port >= 0) && (Copy_u8Port <4))
	{
		/*excute*/
		if ((Copy_u8Pin >= 0) && (Copy_u8Pin < 8))
		{
			/*excute*/

			switch(Copy_u8Port)
			{
				case PORTA : Copy_u8Val = GET_BIT(REG_PINA, Copy_u8Pin); break;
				case PORTB : Copy_u8Val = GET_BIT(REG_PINB, Copy_u8Pin); break;
				case PORTC : Copy_u8Val = GET_BIT(REG_PINC, Copy_u8Pin); break;
				case PORTD : Copy_u8Val = GET_BIT(REG_PIND, Copy_u8Pin); break;
			}
		}


		else
		{
			//do nothing
		}
	}
	else
	{
		// do nothing
	}
	return	Copy_u8Val;
}




u8 DIO_u8GetPortValue (u8 Copy_u8Port){
	u8 Copy_u8Val;
	if((Copy_u8Port >= 0) && (Copy_u8Port <4))
	{
	/*excute*/
		switch(Copy_u8Port)
		{
			case PORTA : Copy_u8Val = REG_PINA; break;
			case PORTB : Copy_u8Val = REG_PINB; break;
			case PORTC : Copy_u8Val = REG_PINC; break;
			case PORTD : Copy_u8Val = REG_PIND; break;
		}

	}
	else
	{
		// do nothing
	}
	return Copy_u8Val;
}
