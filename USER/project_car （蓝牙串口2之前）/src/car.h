#ifndef __CAR_H
#define __CAR_H
#define MOTOR GPIOC
#define A_1A GPIO_Pin_6
#define A_1B GPIO_Pin_7
#define B_1A GPIO_Pin_8
#define B_2A GPIO_Pin_9

void car_init(void);
void car_go(void); // 双轮前进
void car_back(void); // 双轮后退
void car_left(void); // 单轮左转
void car_right(void); // 单轮右转
void car_stop(void);
void car_right_spot(void); // 双轮原地左转
void car_left_spot(void); // 双轮原地右转

#endif
