#include "main.h"
#include "bluetooth.h"

void debug_usart()
{
    GPIO_InitTypeDef GPIOInitStruct;

    /* 配置GPIO引脚复用为TX、RX*/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //使能GPIO组的时钟

    GPIOInitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIOInitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOInitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIOInitStruct.GPIO_OType = GPIO_OType_PP;
    GPIOInitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIOInitStruct);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // PA9 -> USART1_Tx
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // PA10-> USART1_Rx

    /* 配置USART1 */
    USART_InitTypeDef USART_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);                       // 使能USART1的时钟（USART1在APB2总线上）
    USART_InitStruct.USART_BaudRate = 9600;                                      //指定波特率
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;                     //指定数据位长度(通常是8bits)
    USART_InitStruct.USART_Parity = USART_Parity_No;                             //指定校验方式(通常不校验)
    USART_InitStruct.USART_StopBits = USART_StopBits_1;                          //指定停止位(通常是1个停止)
    USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;                 //指定收发模式
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //指定硬件控制流（通常不要）
    USART_Init(USART1, &USART_InitStruct);

    /* 配置串口1的接收中断 */
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // USART_IT_RXNE接收数据寄存器不为空时产生中断

    /* 配置NVIC中断控制器 */
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;         //指定中断通道 xxx_IRQn
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2; //抢占优先级
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;        //子优先级
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    /* 开启串口，就可以开始通信 */
    USART_Cmd(USART1, ENABLE);
}

void usart1_send_byte(char data)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
    USART_SendData(USART1, data);
}

/*
char ch = 0;
void USART1_IRQHandler(void)
{
    //判断是由 RXNE接收数据寄存器非空 产生的中断
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
    {
        ch = USART_ReceiveData(USART1);
        //接收1个字节的数据
        USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清除中断标志
    }
}

char usart1_recv_byte(void)
{
    char ch = 0;
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != SET)
        ;
    ch = USART_ReceiveData(USART1);
    return ch;
}
*/