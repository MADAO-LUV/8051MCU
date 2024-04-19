#include <REGX52.H>

sbit LED=P2^0;

void Delay(unsigned int x)
{
		while(x--);
	
}

//通过主循环以及延时函数来实现PWM（脉冲宽度模式）
void main()
{
	while(1)
	{
		unsigned char Time,i;
		for(Time=0;Time<100;Time++)
		{
			//每个亮度周期循环20次
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		//由暗变亮	
		}
		for(Time=0;Time<100;Time++)
		{
			//每个亮度周期循环20次
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		//由亮变暗	
		}
	}
}