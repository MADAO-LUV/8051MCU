#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
unsigned char Num=0;

void main()
{
	UartInit();
	while(1)
	{
		UART_SendByte(Num);
		Num++;
		Delay(500); //增加一个延时来减小波特率的误差
		//波特率越小，误差越小
	}
}



