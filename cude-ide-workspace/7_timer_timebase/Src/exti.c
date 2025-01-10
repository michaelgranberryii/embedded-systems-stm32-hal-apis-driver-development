/*
 * exti.c
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */


#include "exti.h"

void pc13_btn_init() {
	GPIO_InitTypeDef gpioInitStructure = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE(); // Enable clock
	__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable clock

	// COnfigure PC13
	gpioInitStructure.Pin = BTN_PIN;
	gpioInitStructure.Mode = GPIO_MODE_IT_RISING;
	gpioInitStructure.Pull = GPIO_NOPULL;
	gpioInitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BTN_PORT, &gpioInitStructure);

	// Configure PA0
	gpioInitStructure.Pin = GPIO_PIN_0;
	gpioInitStructure.Mode = GPIO_MODE_IT_RISING;
	gpioInitStructure.Pull = GPIO_NOPULL;
	gpioInitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpioInitStructure);

	// PC13 is in EXTI 10 - 15
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}



// IRQ function call name found in startup_stm32l476rgtx.s
void EXTI15_10_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(BTN_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN) {
	// do something ...
	if (GPIO_PIN == BTN_PIN) {
		printf("Button PC13 pressed\n\r");
		// do something ...


	}
}

