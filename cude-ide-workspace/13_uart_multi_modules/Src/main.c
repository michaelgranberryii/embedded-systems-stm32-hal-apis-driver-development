#include "stm32l4xx_hal.h"
#include "stdio.h"

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

void uart1_init(void);
void uart2_init(void);
void uart3_init(void);

uint8_t tx_buffer1[10] ={100,20,30,40,50,60,70,80,90,10};
uint8_t rx_buffer1[10];
uint8_t tx_buffer3[10] ={1,2,3,40,50,60,70,80,90,10};
uint8_t rx_buffer3[10];


uint32_t rx_counter1, tx_counter1;
uint32_t rx_counter3, tx_counter3;

int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart2, (uint8_t*) &ch, 1, 100);
	return ch;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1) {
		tx_counter1++;
	} else if (huart->Instance == USART3){
		tx_counter3++;
	}

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1) {
		rx_counter1++;
	} else if (huart->Instance == USART3){
		rx_counter3++;
	}
}


int main()
{

  HAL_Init();
  uart1_init();
  uart2_init();
  uart3_init();

  HAL_UART_Receive_IT(&huart1,rx_buffer1,10); // Need to call  HAL_UART_Receive_IT() before HAL_UART_Transmit_IT().
  HAL_UART_Receive_IT(&huart3,rx_buffer3,10); // Need to call  HAL_UART_Receive_IT() before HAL_UART_Transmit_IT().
  HAL_UART_Transmit_IT(&huart1,tx_buffer1,10);
  HAL_Delay(100);
  HAL_UART_Transmit_IT(&huart3,tx_buffer3,10);

  while(1)
  {
	for(int i =0; i<10;i++) {
		printf("USART1: i: %d, tx_buffer : %d, rx_buffer : %d \n\r", i, tx_buffer1[i], rx_buffer1[i]);
		HAL_Delay(100);
	}
	for(int i =0; i<10;i++) {
		printf("USART3: i: %d, tx_buffer : %d, rx_buffer : %d \n\r", i, tx_buffer3[i], rx_buffer3[i]);
		HAL_Delay(100);
	}
  }
}



void  SysTick_Handler(void)
{
	HAL_IncTick();
}

// Pin PA9: TX
// Pin PA10: RX
void uart1_init(void)
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

// Pin PC4: TX
// Pin PC5: RX
void uart3_init(void)
{

	 GPIO_InitTypeDef GPIO_InitStruct = {0};

    //Enable UART pins clock access
	__HAL_RCC_GPIOC_CLK_ENABLE();

	//Enable UART module clock access
    __HAL_RCC_USART3_CLK_ENABLE();


	//Configure pins to act as alternate func pins(UART)

     GPIO_InitStruct.Pin  = GPIO_PIN_4|GPIO_PIN_5;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
     GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
     GPIO_InitStruct.Pull =  GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

     HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);

     //Configure UART module
     huart3.Instance = USART3;
     huart3.Init.BaudRate = 115200;
     huart3.Init.WordLength = UART_WORDLENGTH_8B;
     huart3.Init.StopBits = UART_STOPBITS_1;
     huart3.Init.Parity = UART_PARITY_NONE;
     huart3.Init.Mode = UART_MODE_TX_RX;
     huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
     huart3.Init.OverSampling = UART_OVERSAMPLING_16;

     HAL_UART_Init(&huart3);

     HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
     HAL_NVIC_EnableIRQ(USART3_IRQn);


}

// Pin PA2: TX
// Pin PA3: RX
void uart2_init() {

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

void USART3_IRQHandler(void){
	HAL_UART_IRQHandler(&huart3);
}
