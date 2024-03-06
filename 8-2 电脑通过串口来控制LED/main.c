#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
unsigned char Num=0;

void main()
{
	UartInit();
	while(1)
	{
	
	}
}


//串口中断号为4 前面的函数可以随便命名，跟上中断号说明其是串口中断
void UART_Routine() interrupt 4
{
	//判断是发送中断
	if(RI==1)
	{
		P2=~SBUF; //读出来存入变量中
		UART_SendByte(SBUF); //写在中断中，不能即在主函数写，又在中断函数里面写 
		RI=0; //需要清零
	}

}