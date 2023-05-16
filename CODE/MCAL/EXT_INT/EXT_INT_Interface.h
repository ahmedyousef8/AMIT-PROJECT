/*Includes*/
#include "STD_TYPES.h"

/*Guard*/

#ifndef _EXT_INT_INTERFACE_H
#define _EXT_INT_INTERFACE_H

/* to make the interrupt happen */

void EXTI_voidSenseMode (u8 Copy_u8ExtI_Number, u8 Copy_u8SenseMode);
void EXTI_voidEnable (u8 Copy_u8ExtI_Number);
void EXTI_voidDisable (u8 Copy_u8ExtI_Number);

/* the call back function to pass the function address from the app layer */
void EXTI0SetCallBack (void(*Copy_ptrfn)(void));
void EXTI1SetCallBack (void(*Copy_ptrfn)(void));
void EXTI2SetCallBack (void(*Copy_ptrfn)(void));

void EXTI_voidClrFlag (u8 Copy_u8ExtI_Number);

#endif