#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5; //上升沿锁存
sbit SCK=P3^6; //上升沿位移
sbit SER=P3^4;  //SER
#define MATRIX_LED_PORT  P0 //宏定义 不同的型号其LED点阵端口不同

/**
  * @brief  74HC595写入一个字节
  * @param  无
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	//高位在先
	unsigned char i;
	for (i=0;i<8;i++)
	{
		SER=(Byte&(0x80>>i));
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

/**
  * @brief  点阵屏初始化  
  * @param  无
  * @retval 无
  */
//初始化
void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}


/**
  * @brief  LED点阵屏显示一列数据  
  * @param  Column 要选择的列 ，范围：0-7 ，0在最左边
* @param Data 选择行显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */
//Data 七行称为data
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	unsigned char i;
	_74HC595_WriteByte(Data); //段选
	MATRIX_LED_PORT=~(0x80>>Column); //位选
	Delay(1); //延迟
	MATRIX_LED_PORT=0xFF; //位清零
}