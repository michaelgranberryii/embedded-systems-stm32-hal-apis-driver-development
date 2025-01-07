#include "stm32l4xx_hal.h"
#include "stdio.h"

UART_HandleTypeDef huart2;

void uart2Init();
char msg[20] = "HELLO WORLD\r\n";

int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart2, (uint8_t*) &ch, 1, 100);
	return ch;
}

int main() {

	HAL_Init();
	uart2Init();


	while(1) {
		printf("printf is being used\n\r");
		HAL_Delay(10);
	}
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


void SysTick_Handler(void) {
	HAL_IncTick();
}
