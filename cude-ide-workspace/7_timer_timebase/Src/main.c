#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"
#include "exti.h"
#include "led.h"
#include "tim.h"


int main() {

	HAL_Init();
	pc13_btn_init();
	pa5_led_init();
	uart2Init();
	timTimebaseInit();

	while(1) {

	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	// do something
	printf("TIMx : 1 second elapsed \r\n");
}


