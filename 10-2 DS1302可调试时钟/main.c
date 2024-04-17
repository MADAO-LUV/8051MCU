#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Key.h"
#include "Timer0.h"


unsigned char KeyNum,MODE,TimeSetSelect,TimeSetFlashFlag;

void TimeShow(void)
{
	DS1302_ReadTime();
	LCD_ShowNum(1,1,DS1302_Time[0],2);
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
	
}

void TimeSet(void)
{
	if(KeyNum==2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6;
	}
	if(KeyNum==3)
	{
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}
		//月
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8
				|| DS1302_Time[1]==10 || DS1302_Time[1]==12)
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
					if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
				if(DS1302_Time[0]%4==0)
				{ //闰年
					if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
				}
				else
				{ //平年
					if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
				}
		}
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}
	}
	if(KeyNum==4)
	{
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}
		//月
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8
				|| DS1302_Time[1]==10 || DS1302_Time[1]==12)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{			
					if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
					if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
				if(DS1302_Time[0]%4==0)
				{ //闰年
					if(DS1302_Time[2]<1){DS1302_Time[2]=29;}
					if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
				}
				else
				{ //平年
					if(DS1302_Time[2]<1){DS1302_Time[2]=28;}
					if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
				}
		}
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}
	}
	if(TimeSetSelect==0 && TimeSetFlashFlag==1){LCD_ShowString(1,1,"  ");}
	else{LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(TimeSetSelect==1 && TimeSetFlashFlag==1){LCD_ShowString(1,4,"  ");}
	else{LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(TimeSetSelect==2 && TimeSetFlashFlag==1){LCD_ShowString(1,7,"  ");}
	else{LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(TimeSetSelect==3 && TimeSetFlashFlag==1){LCD_ShowString(2,1,"  ");}
	else{LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(TimeSetSelect==4 && TimeSetFlashFlag==1){LCD_ShowString(2,4,"  ");}
	else{LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(TimeSetSelect==5 && TimeSetFlashFlag==1){LCD_ShowString(2,7,"  ");}
	else{LCD_ShowNum(2,7,DS1302_Time[5],2);}
}	



void main()
{
	LCD_Init();
	DS1302_Init();
	Timer0Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime();

	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{	
			if(MODE==0){MODE=1;}
			else if(MODE==1){MODE=0;DS1302_SetTime();} //加入改变实际显示值
		}
		switch(MODE)
		{	
			case 0:TimeShow();break;
			case 1:TimeSet();break;
		}
	}
}

void Timer0_Routine() interrupt 1 //中断小程序
{
	static unsigned int T0Count; //局部静态变量，防止函数结束后，该变量的数清零，导致无法累加
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=500){
			T0Count=0;
		//逻辑取反
			TimeSetFlashFlag=!TimeSetFlashFlag;
	}
}