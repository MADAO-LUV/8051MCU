#include <REGX52.H>

/**
* @brief    串口初始化 晶振为11.0592hz 9600bps
  * @param  无
  * @retval 无
  */



//串口初始化
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x80;		//波特率不倍速
	SCON = 0x50;		//8位数据,接收数据
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;
	ES=1; //中断启动
}

/**
  * @brief  串口发送两个字节数据  
  * @param  Byte 要发送的一个数据之一
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);//判断TI是否等于1，等于1时跳出循环
	TI=0; //软件置位回0
}



/* 串口中断函数模板 需要用时，挪入主函数中
void UART_Routine() interrupt 4
{
	//判断是发送中断
	if(RI==1)
	{

		RI=0; //需要清零
	}

}
*/