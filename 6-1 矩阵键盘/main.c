#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;

void main()
{
	LCD_Init();//初始化LCD矩阵
	LCD_ShowString(1,1,"MatrixKey");//第一行显示字符串
	while(1)
	{
		KeyNum=MatrixKeyNum();
		if(KeyNum){
			LCD_ShowNum(2,1,KeyNum,2);
		}
		//这里加一个if判断---当下一个按键按下之前，keynum被赋予0，便不会执行十进制显示命令
		//便可以一直显示上一个keynum的值在LCD1602的屏幕上
	}
	
	
}