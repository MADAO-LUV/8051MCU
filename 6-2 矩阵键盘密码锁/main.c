#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum=0;
unsigned int password,Count;

void main()
{

	LCD_Init();//初始化LCD矩阵
	LCD_ShowString(1,1,"PassWord:");//第一行显示字符串
	while(1)
	{
		KeyNum=MatrixKeyNum();
		if(KeyNum)
		{
			if(KeyNum<=10)//如果s1-s10按键按下，输入密码
			{
				if(Count<4)
				{
					password*=10;//密码左移一位
					password+=KeyNum%10;//获取一位密码
					Count++;	
				}
				LCD_ShowNum(2,1,password,4);//更新显示
			}
		}
		if(KeyNum==11) // 设S11 为 确定按键
		{
			if(password==2345) //如果密码等于正确密码
			{
				LCD_ShowString(1,14,"OK ");
				password=0;   //密码清零
				Count=0;    //计次清零
				LCD_ShowNum(2,1,password,4);//更新显示
			}
			else  ///否则
			{
				LCD_ShowString(1,14,"ERR");//显示ERR
				password=0;   //密码清零
				Count=0;    //计次清零
				LCD_ShowNum(2,1,password,4);//更新显示
			}
		}
		if(KeyNum==12)
		{
			password=0;   //密码清零
			Count=0;    //计次清零
			LCD_ShowNum(2,1,password,4);//更新显示
		}
		
		
	}
	
	
}