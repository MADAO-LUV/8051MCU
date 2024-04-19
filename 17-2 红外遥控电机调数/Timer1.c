#include <REGX52.H>

/**
  * @brief  定时器1的初始化  1毫秒@12.000MHz
  * @param  无
  * @retval 无
  */


void Timer1_Init(void)		//1微秒秒@12.000MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xAA;		//设置定时初值
	TH1 = 0xAA;		//设置定时初值
	TF1 = 0;		//清除TF0标志
	TR1 = 1;		//定时器0开始计时
	ET1=1;
	EA=1;
	PT1=0; //低优先级
}





/* 模板，每次使用时，可以复制到main.c中去
void Timer1_Routine() interrupt 3 //中断小程序
{
	static unsigned int T1Count; //局部静态变量，防止函数结束后，该变量的数清零，导致无法累加
	TL1 = 0x66;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	T1Count++;
	if(T1Count>=1000){
			T1Count=0;
	}
}
*/