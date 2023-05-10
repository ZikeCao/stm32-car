#include "sys.h"   
#include "motor.h"	    
//LED IO初始化
void Motor_Init(void)
{	
	RCC->APB2ENR |= 1<<2;
	RCC->APB2ENR |= 1<<5;
	GPIOA->CRH &= 0XFFFFFFF0;
  GPIOA->CRH |= 0X00000003;
	GPIOA->ODR |= 1<<8;
	
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	   	 
	GPIOB->CRL&=0XFFFFF00F; 
	GPIOB->CRL|=0X00000330;  	 
  GPIOB->ODR|=2<<1;      
}






