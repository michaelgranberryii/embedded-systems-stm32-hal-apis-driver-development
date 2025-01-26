#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"

// BTN = PC13, BUS = AHB2EN Bit 0
#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13
// LED = PA5,  BUS = AHB2EN Bit 2
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5

void pc13_btn_init();
void pa5_led_init(void);

int main() {

	HAL_Init();
	pc13_btn_init();
	pa5_led_init();
	uart2_init();
	while(1) {

	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}


void pc13_btn_init() {
	GPIO_InitTypeDef gpioInitStructure = {0};
	__HAL_RCC_GPIOC_CLK_ENABLE(); // Enable clock
	gpioInitStructure.Pin = BTN_PIN;
	gpioInitStructure.Mode = GPIO_MODE_IT_RISING;
	gpioInitStructure.Pull = GPIO_NOPULL;
	gpioInitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BTN_PORT, &gpioInitStructure);

	// PC13 is in EXTI 10 - 15
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
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


// IRQ function call name found in startup_stm32l476rgtx.s
void EXTI15_10_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(BTN_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN) {
	// do something ...
	HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
	printf("Button pressed\n\r");
}
