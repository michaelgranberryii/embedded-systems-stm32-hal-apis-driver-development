/*
 * led.c
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */



#include "led.h"


void pa5_led_init(void) {
	GPIO_InitTypeDef gpioInitStructure = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable clock
	HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
	gpioInitStructure.Pin = LED_PIN;
	gpioInitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInitStructure.Pull = GPIO_NOPULL;
	gpioInitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_PORT, &gpioInitStructure);
}

