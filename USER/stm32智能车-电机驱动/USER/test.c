#include "sys.h"	
#include "motor.h"   
#include "timer.h" 
int main(void)
{			   
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	Motor_Init();		  	 //初始化与LED连接的硬件接口
	TIM1_PWM_Init(899,0);//不分频。PWM频率=72000/(899+1)=80Khz 
	MOTORA_PWM_VAL = 0;	
  while(1)
	{
	} 
}














