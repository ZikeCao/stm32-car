#include "exti.h"
#include "usart.h"
//配置中断
void EXTI_Init(void)
{
	Ex_NVIC_Config(GPIO_B,0,FTIR); 		//配置为下降沿触发
	MY_NVIC_Init(2,2,EXTI0_IRQn,2);    	//配置中断优先级为：抢占2，响应2，组2
}

void EXTI0_IRQHandler(void)
{
	printf("warning!warning!warning!\r\n");
	EXTI->PR=1<<0;  //清除LINE0上的中断标志位  
}










