#include "stm32l4xx_hal.h"
#include "stdio.h"

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;


void uart_init(void);
void uart2Init();

int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart2, (uint8_t*) &ch, 1, 100);
	return ch;
}

uint8_t tx_buffer[10] ={100,20,30,40,50,60,70,80,90,10};
uint8_t rx_buffer[10];


uint32_t rx_counter, tx_counter;


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	tx_counter++;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rx_counter++;
}


int main()
{

  HAL_Init();
  uart2Init();
  uart_init();


  HAL_UART_Receive_IT(&huart1,rx_buffer,10); // Need to call  HAL_UART_Receive_IT() before HAL_UART_Transmit_IT().
  HAL_UART_Transmit_IT(&huart1,tx_buffer,10);

  while(1)
  {
	for(int i =0; i<10;i++) {
		printf("i: %d, tx_buffer : %d, rx_buffer : %d \n\r", i, tx_buffer[i], rx_buffer[i]);
		HAL_Delay(100);
	}
  }
}



void  SysTick_Handler(void)
{
	HAL_IncTick();
}


void uart_init(void)
{

	 GPIO_InitTypeDef GPIO_InitStruct = {0};

    //Enable UART pins clock access
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Enable UART module clock access
    __HAL_RCC_USART1_CLK_ENABLE();


	//Configure pins to act as alternate func pins(UART)

     GPIO_InitStruct.Pin  = GPIO_PIN_9|GPIO_PIN_10;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
     GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
     GPIO_InitStruct.Pull =  GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

     HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

     //Configure UART module
     huart1.Instance = USART1;
     huart1.Init.BaudRate = 115200;
     huart1.Init.WordLength = UART_WORDLENGTH_8B;
     huart1.Init.StopBits = UART_STOPBITS_1;
     huart1.Init.Parity = UART_PARITY_NONE;
     huart1.Init.Mode = UART_MODE_TX_RX;
     huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
     huart1.Init.OverSampling = UART_OVERSAMPLING_16;

     HAL_UART_Init(&huart1);

     HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
     HAL_NVIC_EnableIRQ(USART1_IRQn);


}

void uart2Init() {

	GPIO_InitTypeDef gpioInitStruct = {0};


	// USART is connected to Port A
	__HAL_RCC_GPIOA_CLK_ENABLE();

	// Enable USART module ckock access
	__HAL_RCC_USART2_CLK_ENABLE();

	// Configure pins
	gpioInitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Alternate = GPIO_AF7_USART2;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);

	// Configure USART to use UART module
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart2);

}

void USART1_IRQHandler(void){
	HAL_UART_IRQHandler(&huart1);
}

