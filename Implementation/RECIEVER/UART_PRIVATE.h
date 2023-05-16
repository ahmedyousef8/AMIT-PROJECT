


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

//UART
#define UCSRA  (*(volatile char*)(0x2B))
#define UCSRB  (*(volatile char*)(0x2A))
#define UCSRC  (*(volatile char*)(0x40))
#define UBRRH  (*(volatile char*)(0x40))
#define UBRRL  (*(volatile char*)(0x29))
#define UDR    (*(volatile char*)(0x2C))
#define TXEN    3
#define RXEN    4
#define UDRE    5
#define RXC     7
/*Parity Mode Selection*/
#define PARITY_MODE         EVEN_PARITY

/*Stop Bit Selection*/
#define STOP_BIT            _1_BIT

/*Data Size Selection*/
#define DATA_SIZE           _8_BIT

/*Baud Rate Selection*/
#define BAUD_RATE           B_38400



#endif /* UART_PRIVATE_H_ */
