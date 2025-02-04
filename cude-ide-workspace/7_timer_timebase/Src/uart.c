
#include "uart.h"


UART_HandleTypeDef huart1;


int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, 100);
	return ch;
}

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
	huart1.Instance = USART2;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart1);

}
