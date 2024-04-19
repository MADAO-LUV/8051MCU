#include <REGX52.H>
#include <INTRINS.H>

//引脚定义
sbit ET2046_CS=P3^5;
sbit ET2046_DCLK=P3^6;
sbit ET2046_DIN=P3^4;
sbit ET2046_DOUT=P3^7;

/**
  * @brief  ET2046读取AD值  
  * @param  Command命令字，范围：头文件内定义的宏，结尾的数字表示转换的位数
  * @retval AD转换后的数字量，范围：8位为0~255,12位为0~4095
  */
unsigned int ET2046_ReadAD(unsigned char Command)
{
	unsigned int ADVALue=0;
	unsigned char i;
	ET2046_DCLK=0;
	ET2046_CS=0;
	
	for(i=0;i<8;i++)
	{
			ET2046_DIN=Command&(0x80>>i);
			ET2046_DCLK=1;
			ET2046_DCLK=0;
	}
	//执行下来已经大于1.5us了
	
	for(i=0;i<16;i++)
	{
			ET2046_DCLK=1;
			ET2046_DCLK=0;
			if(ET2046_DOUT){ADVALue|=(0x8000>>i);}
	}
	ET2046_CS=1;
	if(Command&0x08)
	{
		return ADVALue>>8;
	}
	else
	{
		return ADVALue>>4;
	}
}