
/*Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXT_INT_Interface.h"
#include "EXT_INT_Private.h"


void (*GenPtr0)(void)= NULLPTR;
void (*GenPtr1)(void)= NULLPTR;
void (*GenPtr2)(void)= NULLPTR;


void EXTI_voidSenseMode (u8 Copy_u8ExtI_Number, u8 Copy_u8SenseMode)
{
	switch (Copy_u8ExtI_Number)
	{
		
		case EXTI0:
		MCUCR &= !0b11;			// Clear the sense mode bits for EXT0 in the register
		
		if ((Copy_u8SenseMode >= 0) & (Copy_u8SenseMode <= 3))
		{
			MCUCR |= Copy_u8SenseMode;
		}
		break;
		
		case EXTI1:
		MCUCR &= !(0b11<<2);	// Clear the sense mode bits for EXT1 in the register
		
		if ((Copy_u8SenseMode >= 0) & (Copy_u8SenseMode <= 3))
		{
			MCUCR |= Copy_u8SenseMode << 2;
		}
		break;
		
		case EXTI2:
		MCUCSR &= !(1<<ISC2);	// Clear the sense mode bit for EXT2 in the register	
		
		if ((Copy_u8SenseMode = 0) | (Copy_u8SenseMode =1))
		{
			MCUCSR |= Copy_u8SenseMode << ISC2;
		}
		break;
		
		default: 
		//do nothing
		break;		
	}
}


void EXTI_voidEnable (u8 Copy_u8ExtI_Number)
{
	switch (Copy_u8ExtI_Number)
	{
		case EXTI0:	SET_BIT(GICR, INT0);	break;
		case EXTI1:	SET_BIT(GICR, INT1);	break;
		case EXTI2:	SET_BIT(GICR, INT2);	break;
		default:	/*do nothing*/			break;	
	}
	
}

void EXTI_voidDisable (u8 Copy_u8ExtI_Number)
{
	switch (Copy_u8ExtI_Number)
	{
		case EXTI0:	CLR_BIT(GICR, INT0);	break;
		case EXTI1:	CLR_BIT(GICR, INT1);	break;
		case EXTI2:	CLR_BIT(GICR, INT2);	break;
		default:	/*do nothing*/			break;	
	}
}


ISR(EXTI0_VECT)
{
	if (GenPtr0 != NULLPTR)
	{
		GenPtr0();
	}
	
}

ISR(EXTI1_VECT)
{
	if (GenPtr1 != NULLPTR)
	{
		GenPtr1();
	}
}

ISR(EXTI2_VECT)
{
	if (GenPtr2 != NULLPTR)
	{
		GenPtr2();
	}
}


 
void EXTI0SetCallBack (void(*Copy_ptrfn)(void))
{
	GenPtr0= Copy_ptrfn;
}

void EXTI1SetCallBack (void(*Copy_ptrfn)(void))
{
	GenPtr1= Copy_ptrfn;
}

void EXTI2SetCallBack (void(*Copy_ptrfn)(void))
{
	GenPtr2= Copy_ptrfn;
}


void EXTI_voidClrFlag (u8 Copy_u8ExtI_Number)
{
	switch (Copy_u8ExtI_Number)
	{
		case EXTI0:	SET_BIT(GIFR, INTF0);	break;
		case EXTI1:	SET_BIT(GIFR, INTF1);	break;
		case EXTI2:	SET_BIT(GIFR, INTF2);	break;
		default:	/*do nothing*/			break;	
	}
}