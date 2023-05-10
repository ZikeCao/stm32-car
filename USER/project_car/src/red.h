#ifndef __RED_H
#define __RED_H
#define Red1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) // 右边红外1号
#define Red2 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) // 左边红外4号

void red_init(void);

#endif

