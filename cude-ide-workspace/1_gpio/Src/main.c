#include "stm32l4xx_hal.h"

// BTN = PC13, BUS = AHB2EN Bit 0
#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13
// LED = PA5,  BUS = AHB2EN Bit 2
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5

void pc13_btn_init(void);
void pa5_led_init(void);

uint8_t btnStatus;

int main() {

	HAL_Init();

	pc13_btn_init();
	pa5_led_init();

	while(1) {
		btnStatus = HAL_GPIO_ReadPin(BTN_PORT, BTN_PIN);
		HAL_GPIO_WritePin(LED_PORT, LED_PIN, btnStatus);
	}
}

void pc13_btn_init(void) {
	GPIO_InitTypeDef gpioInitStructure = {0};
	__HAL_RCC_GPIOC_CLK_ENABLE(); // Enable clock
	gpioInitStructure.Pin = BTN_PIN;
	gpioInitStructure.Mode = GPIO_MODE_INPUT;
	gpioInitStructure.Pull = GPIO_NOPULL;
	gpioInitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BTN_PORT, &gpioInitStructure);
}

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


void SysTick_Handler(void) {
	HAL_IncTick();
}
