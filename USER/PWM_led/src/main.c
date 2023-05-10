#include "stm32f4xx.h"  
void GPIOA_Init()  
 { 
	 
	 GPIO_InitTypeDef  GPIOAStruct; 
     RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);  //GPIOA??
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 ,ENABLE);    //???3????
//  ??????PB5????,????????
//   GPIO_PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	 GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);     //?????
	                   //GPIOB????
	 GPIOAStruct.GPIO_Mode=GPIO_Mode_AF_PP ;  //??????
	 GPIOAStruct.GPIO_Pin=GPIO_Pin_7;
	 GPIOAStruct.GPIO_Speed=GPIO_Speed_50MHz;
     GPIO_Init(GPIOA, &GPIOAStruct);		
 }
 void PWM_TIM3_CH2(u16 addr ,u16 duty)
 {  
	  TIM_OCInitTypeDef    TIM3_OCInitStruct;   //?????????
      TIM_TimeBaseInitTypeDef TIM3Struct;	    //??????,??????99+1
	  TIM_DeInit(TIM3);          //TIM3??
      TIM3Struct.TIM_ClockDivision=TIM_CKD_DIV1  ;
	  TIM3Struct.TIM_CounterMode=TIM_CounterMode_Up;
	  TIM3Struct.TIM_Period=addr-1;        //???
	  TIM3Struct.TIM_Prescaler=719;   //???
      TIM_TimeBaseInit(TIM3, &TIM3Struct);	
   
      TIM3_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM2 ;  //???????
      TIM3_OCInitStruct.TIM_Pulse=duty;      //?????????,????????
	  TIM3_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
	  TIM3_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	  TIM_OC2Init(TIM3, &TIM3_OCInitStruct);  //??2???
      TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
      TIM_Cmd(TIM3, ENABLE); //?????
 }
 int  main()
 {
   GPIOA_Init();
	 PWM_TIM3_CH2( 100,30);   
	 while(1)
	 {
	 }
 return 0;
 }


