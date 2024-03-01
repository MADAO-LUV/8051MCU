#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


int result=0;
void main()
{
	LCD_Init();
	while(1)
	{
		LCD_ShowString(1,1,"bebe");
		Delay(1000);
		LCD_ShowString(1,1,"i_miss");
		Delay(1000);
		LCD_ShowString(1,1,"my_bebe");
		
	}
	
}