#include <REGX52.H>
#include "Delay.h"
/**
  * @brief  矩阵键盘控制LCD屏显示相应的按键键值  
  * @param  无
  * @retval 按键键值 当相应按键被按下时，若一直没松手，便会停留在循环中，直到手松开，并返回相应的键值。
  */
unsigned char KeyNumber;

unsigned char MatrixKeyNum()
{
	P1=0xFF;//全部至为高位
	P1_3=0; //第一列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=13;}
	
	P1=0xFF;//全部至为高位
	P1_2=0; //第二列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=14;}
	
	P1=0xFF;//全部至为高位
	P1_1=0; //第三列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=15;}
	
	P1=0xFF;//全部至为高位
	P1_0=0; //第四列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=16;}
	
	
	return KeyNumber;
}