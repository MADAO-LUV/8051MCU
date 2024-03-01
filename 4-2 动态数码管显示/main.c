
#include <REGX52.H>



unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
				while (--j);
		} while (--i);
		
	}
	
}
//延时函数


void Nixie(unsigned char Location,unsigned char Number)
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];
	Delay(1);
	P0=0x00;
}
//使用函数将细节封装起来
//使用全局变量数组，以功能快速索引到达最终目的。
//优化程序结构






void main()
{
	
	while(1)
	{
		Nixie(1,5);
//		Delay(20);
		Nixie(2,2);
//		Delay(20);
		Nixie(3,0);
//		Delay(20);
	}
	

}