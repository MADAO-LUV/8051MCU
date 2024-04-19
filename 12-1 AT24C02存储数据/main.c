#include <REGX52.H>
#include "LCD1602.h"
#include "Key.h"
#include "AT24C02.h"
#include "Delay.h"

unsigned char KeyNum;
unsigned int Num;//申请一个4个字节变量

void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,Num,5);
	while(1)
	{
		KeyNum=key();
		if(KeyNum==1)
		{
			Num++;
			LCD_ShowNum(1,1,Num,5);
		}
		if(KeyNum==2)
		{	
			Num--;
			LCD_ShowNum(1,1,Num,5);
		}
		//写入地址
		if(KeyNum==3)
		{
			//分别写入高,低八位
			AT24C02_WriteByte(0,Num%256);
			Delay(5);
			AT24C02_WriteByte(1,Num/256);
			Delay(5);
			LCD_ShowString(2,1,"Write OK");
			Delay(1000);
			LCD_ShowString(2,1,"        ");
		}
		
		//读出数据
		if(KeyNum==4)
		{
			Num=AT24C02_ReadByte(0);
			Num=AT24C02_ReadByte(1)<<8;
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Read OK");
			Delay(1000);
			LCD_ShowString(2,1,"         ");
		}
	}
}