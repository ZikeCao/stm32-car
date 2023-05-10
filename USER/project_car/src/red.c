#include "main.h"
#include "red.h"

void red_init(void)
{
  /* 定义GPIO初始化信息结构体*/
  GPIO_InitTypeDef GPIo_InitStruct;

  /* 1.使能GPIO组时钟*/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  /* 2.初始化配置GPIOF、GPIOE通用推挽输出*/
  GPIo_InitStruct.GPIO_Pin = GPIO_Pin_6;
  GPIo_InitStruct.GPIO_Mode = GPIO_Mode_IN;
  GPIo_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOB, &GPIo_InitStruct);
  GPIo_InitStruct.GPIO_Pin = GPIO_Pin_5;
  GPIO_Init(GPIOE, &GPIo_InitStruct);
}
