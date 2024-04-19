#include <REGX52.H>
#include "OneWire.h"

//DS18C20指令集
#define DS18B20_SKIP_ROM					0xCC
#define DS18B20_CONVERT_T					0x44
#define DS18B20_READ_SCRATCHPAD		0xBE

/**
  * @brief  DS18B20开始温度变换  
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT(void)
{
		OneWire_Init();
		OneWire_SendByte(DS18B20_SKIP_ROM);
		OneWire_SendByte(DS18B20_CONVERT_T);
	
}

/**
  * @brief  DS18B20读取温度  
  * @param  无
  * @retval 温度数值
  */

float DS18B20_ReadT(void)
{
		unsigned char TLSB,TMSB;
		int Temp;
		float T;
		OneWire_Init();
		OneWire_SendByte(DS18B20_SKIP_ROM);
		OneWire_SendByte(DS18B20_READ_SCRATCHPAD);//总线控制权交给从机
		TLSB=OneWire_ReceiveByte();
		TMSB=OneWire_ReceiveByte();//拿出温度的两个字节
		Temp=(TMSB<<8)|TLSB;
		T=Temp/16.0;
		return T;
}