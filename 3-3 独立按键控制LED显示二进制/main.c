#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
			i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void main()
{
	//八位二进制 表示一个寄存器
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)
		{	
			Delay(20);//软件消抖
			while(P3_1==0);//检测松手
			Delay(20);//消抖
			//1111 1111
			LEDNum++;
			P2=~LEDNum;//按位取反，并不改变LEDNum的值
		}
	}
	
}