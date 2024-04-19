#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Motor.h"
#include "IR.h"
unsigned char Command,Speed; //命令，速度

void main()
{
	
	Motor_Init();
	IR_Init();
	while(1)
	{
		if(IR_GetDataFlag())
		{
			Command=IR_GetCommand();//读出命令
			//使用红外遥控控制pwm
			if(Command==IR_0){Speed=0;}
			if(Command==IR_1){Speed=1;}
			if(Command==IR_2){Speed=2;}
			if(Command==IR_3){Speed=3;}
		}
		if(Speed==0){Motor_SetSpeed(0);} //设置比较值，改变PWM占空比
		if(Speed==1){Motor_SetSpeed(50);}
		if(Speed==2){Motor_SetSpeed(75);}
		if(Speed==3){Motor_SetSpeed(100);}
		Nixie(1,Speed);
	}
}
//Tips:电机刚开始转动是因为，MCU端口开始默认为高电平；所以我们一打开时，它会转动

