#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//motor functions

void M_Forward();
void M_Backward();
void M_Stop();
void M_Right();
void M_Left();
void M_Turn();

#endif 