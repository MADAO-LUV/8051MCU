#include <REGX52.H>
#include <INTRINS.H>
//蜂鸣器端口
sbit Buzzer=P2^5; //新版普中的BZ引脚是P2_5
unsigned int i;

//延时500us
/**
  * @brief    蜂鸣器私有延时函数，延时500us
  * @param  无
  * @retval 无
  */
void Buzzer_Delay500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 247;
	while (--i);
}


/**
  * @brief   蜂鸣器发声 
  * @param  	ms 发声的时间
  * @retval 	无
  */
void Buzzer_Time(unsigned int ms)
{
		for(i=0;i<ms*2;i++)
			{
					Buzzer=!Buzzer;
					Buzzer_Delay500us();
				//之前是延时1ms，现在是0.5ms，所有ms需要*2
			}
	
}