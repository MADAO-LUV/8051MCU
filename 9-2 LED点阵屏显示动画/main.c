#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"
#include "Timer0.h"

unsigned char code Admation[] = {
	0x18,0xA3,0xFC,0xF8,0xAC,0x23,0x1E,0x0E,
	0x19,0x26,0xBF,0xFB,0xEB,0xB4,0x17,0x11,
	0x18,0xA3,0xFC,0xF8,0xAC,0x23,0x1E,0x0E,
	0x19,0x26,0xBF,0xFB,0xEB,0xB4,0x17,0x11,
	0x01,0x17,0xA8,0xFA,0xF7,0x92,0x0D,0x01,
	0x3C,0x18,0x08,0x08,0x91,0xEF,0xC1,0x90,
	0x00,0x30,0x20,0xFF,0xFE,0xA0,0x00,0x00,
	0x00,0x00,0x70,0xFF,0xBA,0x34,0x40,0x80,
	0x00,0x00,0x70,0xFF,0xBA,0x34,0x00,0x00,
	0x00,0x00,0x00,0x37,0x78,0xF8,0xB6,0x01,
	0x00,0x00,0x00,0x37,0x78,0xF8,0xB6,0x01,
	0x00,0x00,0x1B,0x3C,0x7C,0x56,0x01,0x00,
	0x00,0x00,0x01,0x02,0x1C,0x3C,0x7B,0x58,
	0x00,0x00,0x1B,0x3C,0x7C,0x56,0x01,0x00,
	0x00,0x00,0x00,0x37,0x78,0xF8,0xB6,0x01,
	0x00,0x00,0x70,0xFF,0xBA,0x34,0x00,0x00,
	0x00,0x00,0x70,0xFF,0xBA,0x34,0x40,0x80,
	0x00,0x00,0x1B,0x3C,0x7C,0x56,0x01,0x00,
	0x00,0x00,0x00,0x37,0x78,0xF8,0xB6,0x01,
};

unsigned char offset=0;
void main()
{
	
	unsigned char i;
	Timer0Init();
	MatrixLED_Init();
	
	while(1)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,Admation[i+offset]);
		}
		

	}
}


void Timer0_Routine() interrupt 1 //中断小程序
{
	static unsigned int T0Count; //局部静态变量，防止函数结束后，该变量的数清零，导致无法累加
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000){
			T0Count=0;
			offset+=8;
			if(offset>144)
			{
				offset=0;
			}
	}
}