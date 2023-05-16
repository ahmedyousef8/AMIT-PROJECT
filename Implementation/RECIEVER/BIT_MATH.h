/********GUARD********/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

/*BITEWISE OPERATION*/

#define SET_BIT(PORT_REG, PIN_NO) PORT_REG |= (1<<PIN_NO)
#define CLR_BIT(PORT_REG, PIN_NO) PORT_REG &= ~(1<<PIN_NO)
#define TGL_BIT(PORT_REG, PIN_NO) PORT_REG ^= (1<<PIN_NO)


#define GET_BIT(PORT_REG,PIN_NO) ((PORT_REG >> PIN_NO) & 1)	//not	{PORT_REG=(PORT_REG>>PIN_NO) & 1} because this will change the value of the PORT_REG


#endif