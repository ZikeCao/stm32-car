#include "main.h"
#include "car.h"

void car_init(void)
{
  /* 定义GPIO初始化信息结构体*/
  GPIO_InitTypeDef GPIo_InitStruct;

  /* 1.使能GPIO组时钟*/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* 2.初始化配置GPIOF、GPIOE通用推挽输出*/
  GPIo_InitStruct.GPIO_Pin = A_1A | A_1B | B_1A | B_2A;
  GPIo_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIo_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIo_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIo_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(GPIOC, &GPIo_InitStruct);
}

void car_go(void) // 双轮前进
{
  GPIO_ResetBits(MOTOR, A_1A);
  GPIO_SetBits(MOTOR, A_1B);
  GPIO_SetBits(MOTOR, B_1A);
  GPIO_ResetBits(MOTOR, B_2A);
}
void car_back(void) // 双轮后退
{
  GPIO_SetBits(MOTOR, A_1A);
  GPIO_ResetBits(MOTOR, A_1B);
  GPIO_ResetBits(MOTOR, B_1A);
  GPIO_SetBits(MOTOR, B_2A);
}
void car_left(void) // 单轮左转
{
  GPIO_SetBits(MOTOR, A_1A);
  GPIO_SetBits(MOTOR, A_1B);
  GPIO_SetBits(MOTOR, B_1A);
  GPIO_ResetBits(MOTOR, B_2A);
}

void car_right(void) // 单轮右转
{
  GPIO_ResetBits(MOTOR, A_1A);
  GPIO_SetBits(MOTOR, A_1B);
  GPIO_ResetBits(MOTOR, B_1A);
  GPIO_ResetBits(MOTOR, B_2A);
}

void car_stop(void)
{
  GPIO_ResetBits(MOTOR, A_1A);
  GPIO_ResetBits(MOTOR, A_1B);
  GPIO_ResetBits(MOTOR, B_1A);
  GPIO_ResetBits(MOTOR, B_2A);
}

void car_right_spot(void) // 双轮原地左转
{
  GPIO_SetBits(MOTOR, A_1A);
  GPIO_ResetBits(MOTOR, A_1B);
  GPIO_SetBits(MOTOR, B_1A);
  GPIO_ResetBits(MOTOR, B_2A);
}

void car_left_spot(void) // 双轮原地右转
{
  GPIO_ResetBits(MOTOR, A_1A);
  GPIO_SetBits(MOTOR, A_1B);
  GPIO_ResetBits(MOTOR, B_1A);
  GPIO_SetBits(MOTOR, B_2A);
}
