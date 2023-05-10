#include "sys.h"
#include "usart.h"		
#include "ir_sensor.h"
#include "exti.h"
int main(void)
{			
	Stm32_Clock_Init(9);//系统时钟设置
	uart_init(72,9600); //串口初始化 
	ir_sensor_init();
	EXTI_Init();		//外部中断初始化
	while(1)
	{	      
	}
}














