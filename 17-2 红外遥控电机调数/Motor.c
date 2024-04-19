#include <REGX52.H>
#include "Timer1.h"

sbit Motor=P1^0;//电机端口
unsigned char Counter,Compare;//计数值和比较值，用于输出PWM

void Motor_Init(void)
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}



void Timer1_Routine() interrupt 3 //中断小程序
{
	TL1 = 0x66;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
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