#include "ir_sensor.h"
#include "sys.h" 
void ir_sensor_init()
{
	RCC->APB2ENR |= 1<<3;    //使能PORTB时钟	   	   	 
	GPIOB->CRL   &= 0xFFFFFFF0; 
	GPIOB->CRL   |= 0x00000008;//PB0 输入模式   	 
}