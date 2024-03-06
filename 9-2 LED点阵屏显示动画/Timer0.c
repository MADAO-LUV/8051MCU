#include <REGX52.H>

/**
  * @brief  定时器0的初始化  1毫秒@12.000MHz
  * @param  无
  * @retval 无
  */


void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0; //低优先级
}





/* 模板，每次使用时，可以复制到main.c中去
void Timer0_Routine() interrupt 1 //中断小程序
{
	static unsigned int T0Count; //局部静态变量，防止函数结束后，该变量的数清零，导致无法累加
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000){
			T0Count=0;
P2_0=~P2_0; 不太容易模块化，应该放在主函数中
	}
//函数内部可以引用
}
*/