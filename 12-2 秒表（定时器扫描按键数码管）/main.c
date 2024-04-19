#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"
#include "Delay.h"
#include "AT24C02.h"


unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag;

void main()
{
	Timer0_Init();
	
	while(1)
	{
		KeyNum=key();	
		if(KeyNum==1)
		{
			RunFlag=!RunFlag;
		}
		if(KeyNum==2)
		{
			Min=0;
			Sec=0;
			MiniSec=0;
		}
		//写入数据
		if(KeyNum==3)
		{
			AT24C02_WriteByte(0,Min);
			Delay(5);
			AT24C02_WriteByte(1,Sec);
			Delay(5);
			AT24C02_WriteByte(2,MiniSec);
			Delay(5);
		}
		//读出数据
		if(KeyNum==4)
		{
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			MiniSec=AT24C02_ReadByte(2);
		}
			Nixie_SetBuf(1,Min/10);
			Nixie_SetBuf(2,Min%10);
			Nixie_SetBuf(3,11);
			Nixie_SetBuf(4,Sec/10);
			Nixie_SetBuf(5,Sec%10);
			Nixie_SetBuf(6,11);
			Nixie_SetBuf(7,MiniSec/10);
			Nixie_SetBuf(8,MiniSec%10);
			
	}
}

void Sec_Loop(void)
{
	if(RunFlag)
	{
		MiniSec++;
		if(MiniSec>=100)
		{
			MiniSec=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>60)
				{
					Min=0;
				}
			}
		}
	}
}


void Timer0_Routine() interrupt 1 //中断小程序
{
	static unsigned int T0Count1,T0Count2,T0Count3; //局部静态变量，防止函数结束后，该变量的数清零，导致无法累加
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	//每隔20ms检测一次
	if(T0Count1>=20){
			T0Count1=0;
			Key_Loop();
	}
	//每隔2ms调用一次
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();
	}
	T0Count3++;
	if(T0Count3>=10)
	{
		T0Count3=0;
		Sec_Loop();
	}
}