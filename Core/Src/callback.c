//
// Created by lenovo on 24-10-2.
//
#include "main.h"
#include "tim.h"
#include "usart.h"
extern DMA_HandleTypeDef hdma_usart6_rx; //外部变量声明
extern uint8_t receiveData[50];
/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance == htim6.Instance){
        HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_14);
    }
}*/

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size){
    if(huart == &huart6){
        HAL_UART_Transmit_DMA(&huart6,receiveData,Size);
        HAL_UARTEx_ReceiveToIdle_DMA(&huart6, receiveData, sizeof(receiveData));
        __HAL_DMA_DISABLE_IT(&hdma_usart6_rx, DMA_IT_HT); //关闭DMA传输过半中断
    }
}