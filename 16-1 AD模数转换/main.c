#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "ET2046.h"

unsigned int ADValue;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ NTC RG");
	//adj 热敏  ntc 滑动变阻 rg 光敏电阻
	while(1)
	{
		ADValue=ET2046_ReadAD(ET2046_XP_12); //读取AINO，可调电阻
		LCD_ShowNum(2,1,ADValue,3);						//显示AINO
		ADValue=ET2046_ReadAD(ET2046_YP_12);  //读取AIN1，热敏电阻
		LCD_ShowNum(2,5,ADValue,3);           //显示AIN1
		ADValue=ET2046_ReadAD(ET2046_VBAT_12); //读取AIN2，光敏电阻
		LCD_ShowNum(2,9,ADValue,3);							//显示AIN2
		Delay(10);
	}
}