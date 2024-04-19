#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit DA=P2^1;//电机端口
unsigned char Counter,Compare;//计数值和比较值，用于输出PWM
unsigned char i;

void main()
{
	Timer0_Init();//为了实现PWM
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			Delay(50);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;
			Delay(50);
		}
	}
}
//Tips:电机刚开始转动是因为，MCU端口开始默认为高电平；所以我们一打开时，它会转动


void Timer0_Routine() interrupt 1 //中断小程序
{
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	Counter++;
	Counter%=100; // 效果等效于 if(Counter>=100){Counter=0;}
	if(Counter<Compare) //计算值小于比较值时
	{
		DA=1;//电机在电平为1的时候，启动。
	}
	else
	{
		DA=0;
	}
}