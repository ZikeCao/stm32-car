/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "car.h"
#include "red.h"
#include "bluetooth.h"
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

/* Private functions ---------------------------------------------------------*/

char ch = 0;
void USART2_IRQHandler(void)
{
  //判断是由 RXNE接收数据寄存器非空 产生的中断
  if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
  {
    ch = USART_ReceiveData(USART2);
    //接收1个字节的数据
    USART_ClearITPendingBit(USART2, USART_IT_RXNE); //清除中断标志
    if (ch == '1')
    {
      while (1)
      {

        if (Red1 == 0 && Red2 == 0)
        {
          car_go();
        }
        else if (Red1 == 0 && Red2 == 1)
        {
          car_right_spot();
        }

        else if (Red2 == 0 && Red1 == 1)
        {
          car_left_spot();
        }

        else if (Red1 == 1 && Red2 == 1)
        {
          car_stop();
          break;
        }
      }
    }
    else if (ch == '0') //停止
    {
      car_stop();
    }
    else if (ch == '2') //前进
    {
      car_go();
    }
    else if (ch == '4') //左转
    {
      car_left_spot();
    }
    else if (ch == '6') //右转
    {
      car_right_spot();
    }
    else if (ch == '8') //后退
    {
      car_back();
    }
  }
}

int main(void)
{
  SysTick_Config(SystemCoreClock / 1000);
  car_init();
  red_init();

  char str[] = "oyhldsg";
  int i = 0;

  usart_init();
  /* Infinite loop */
  while (1)
  {
    GPIO_ResetBits(GPIOF, GPIO_Pin_9);
    Delay(1000);
    GPIO_SetBits(GPIOF, GPIO_Pin_9);
    Delay(1000);
    for (i = 0; i < 7; i++)
    {
      usart2_send_byte(str[i]);
    }
  }

  //   while (1)
  //   {
  //     if (Red1 == 0 && Red2 == 0)
  //     {
  //       car_go();

  //     }
  //     else if (Red1 == 0 && Red2 == 1)
  //     {
  //       car_right_spot();
  //     }

  //     else if (Red1 == 1 && Red2 == 0)
  //     {
  //       car_left_spot();
  //     }

  //     else
  //     {
  //       car_stop();
  //     }
  //   }
}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
void Delay(__IO uint32_t nTime)
{
  uwTimingDelay = nTime;

  while (uwTimingDelay != 0)
    ;
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

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
