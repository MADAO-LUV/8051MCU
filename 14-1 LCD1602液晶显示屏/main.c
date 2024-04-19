#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"There we two, content, happy in being together,speaking little, perhaps not a word.");
	LCD_ShowString(2,1,"              ---TO my bebe");
	while(1)
	{
		LCD_WriteCommand(0x18);//流动字幕
		Delay(500);
	}
}