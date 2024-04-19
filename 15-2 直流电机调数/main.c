#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^0;//电机端口
unsigned char Counter,Compare;//计数值和比较值，用于输出PWM
unsigned char KeyNum,Speed;

void main()
{
	Timer0_Init();//为了实现PWM
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4; //原理和定时器中断类似
		}
		if(Speed==0){Compare=0;} //设置比较值，改变PWM占空比
		if(Speed==1){Compare=50;}
		if(Speed==2){Compare=75;}
		if(Speed==3){Compare=100;}
		Nixie(1,Speed);
	}
}
//Tips:电机刚开始转动是因为，MCU端口开始默认为高电平；所以我们一打开时，它会转动


void Timer0_Routine() interrupt 1 //中断小程序
{
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	Counter++;
	Counter%=100; // 效果等效于 if(Counter>=100){Counter=0;}
	if(Counter<Compare)
	{
		Motor=1;//电机在电平为1的时候，启动。
	}
	else
	{
		Motor=0;
	}
}