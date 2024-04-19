#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "DS18B20.h"

float T;


void main()
{
	DS18B20_ConvertT(); //上电先转换一次温度，防止第一次读数错误
	Delay(1000); //等待转换完成
	LCD_Init();
	LCD_ShowString(1,1,"Temperature");
	while(1)
	{
		DS18B20_ConvertT();//刚开始还是默认值，所以一开始是默认值
		T=DS18C20_Readt(); //读取温度
		if(T<0) //如果温度小于0
		{
			LCD_ShowChar(2,1,'-');//显示符号
			T=-T; //将温度变为正数
		}
		else
		{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,T,3); //显示温度整数部分
		LCD_ShowChar(2,5,'.'); //显示小数部分
		//小数部分先乘10000，把小数部分化为整，然后强制类型转化后，再取余
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
	}
}