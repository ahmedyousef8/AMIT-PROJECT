#include "uart.h"




void UART_Init(void)
{

	//baud rate 9600
	UBRRL=51;

	// enable transmitter,receiver

	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);

}


void UART_Send(u8 data)
{
	while(!GET_BIT(UCSRA,UDRE));
	UDR=data;

}

u8 UART_Receive(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}

void UART_SendString(u8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}

}
