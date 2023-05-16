
#include "DC_Motor_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

void M_Forward(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN3,HIGH);
	DIO_voidSetPinValue(PORTC,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN4,LOW);
	DIO_voidSetPinValue(PORTC,PIN6,LOW);
}

void M_Backward(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN3 ,LOW);
	DIO_voidSetPinValue(PORTC,PIN5,LOW);
	DIO_voidSetPinValue(PORTC,PIN4,HIGH);
	DIO_voidSetPinValue(PORTC,PIN6,HIGH);
}

void M_Stop(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,LOW);
	DIO_voidSetPinValue(PORTC,PIN3,LOW);
	DIO_voidSetPinValue(PORTC,PIN5,LOW);
	DIO_voidSetPinValue(PORTC,PIN4,LOW);
	DIO_voidSetPinValue(PORTC,PIN6,LOW);
}

void M_Left(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN3,LOW);
	DIO_voidSetPinValue(PORTC,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN4,HIGH);
	DIO_voidSetPinValue(PORTC,PIN6,LOW);

}

void M_Right(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN3,HIGH);
	DIO_voidSetPinValue(PORTC,PIN5,LOW);
	DIO_voidSetPinValue(PORTC,PIN4,LOW);
	DIO_voidSetPinValue(PORTC,PIN6,HIGH);
}




void M_Turn(void){
	DIO_voidSetPinValue(PORTD,PIN4,HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,HIGH);
	DIO_voidSetPinValue(PORTC,PIN3,HIGH);
	DIO_voidSetPinValue(PORTC,PIN5,LOW);
	DIO_voidSetPinValue(PORTC,PIN4,LOW);
	DIO_voidSetPinValue(PORTC,PIN6,HIGH);

	
}