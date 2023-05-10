/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.8.0
  * @date    04-November-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


#define DELAY_TIME   0x3FFFF

/** @addtogroup Template_Project
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;
RCC_ClocksTypeDef RCC_Clocks;

/* Private function prototypes -----------------------------------------------*/
static void Delay(__IO uint32_t nTime);



void led_init(void) {
	/* 定义GPIO初始化信息结构体*/
    GPIO_InitTypeDef GPIo_InitStruct;

    /* 1.使能GPIO组时钟*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    /* 2.初始化配置GPIOF、GPIOE通用推挽输出*/
	GPIo_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIo_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIo_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIo_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIo_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOF, &GPIo_InitStruct);
	GPIO_Init(GPIOE, &GPIo_InitStruct);


    /* 3.LED流水灯*/
	while(1){
		
		GPIO_ResetBits(GPIOF, GPIO_Pin_9);
	    Delay(100);
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		
	
	    GPIO_ResetBits(GPIOF, GPIO_Pin_10);
	    Delay(100);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		
	    GPIO_ResetBits(GPIOE, GPIO_Pin_13);
		Delay(100);
		GPIO_SetBits(GPIOE,GPIO_Pin_13);
		
	    GPIO_ResetBits(GPIOE, GPIO_Pin_14);
		Delay(100);
		GPIO_SetBits(GPIOE,GPIO_Pin_14);
	}
}

int main(void){

    /*设置一秒中断多少次，延时函数的延时单位
      SystemCoreClock/1000 --> Delay函数是ms级延时
      SystemCoreClock/1000000 --> Delay函数是us级延时

      两个地方需要修改：
      1) HES_VALUE --> 为外部高速时钟，改为 8000000（8M,取决于硬件晶振大小)
      2) SystemCoreClock = HSE_VALUE/PLL_M*PLL_N/PLL_P
      PLL_M --> 分频系数改为 8
    */
    SysTick_Config(SystemCoreClock/1000);
	
    led_init();
}


/* 自定义延时函数
void Delay(__IO uint32_t nCount)
{
   for(; nCount != 0; nCount--) ;
}
*/

void Delay(__IO uint32_t nTime)
{ 
  uwTimingDelay = nTime;

  while(uwTimingDelay != 0);
}


/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (uwTimingDelay != 0x00)
  { 
    uwTimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
