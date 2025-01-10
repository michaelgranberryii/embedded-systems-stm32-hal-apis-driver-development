#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"
#include "exti.h"
#include "led.h"



int main() {

	HAL_Init();
	pc13_btn_init();
	pa5_led_init();
	uart2Init();
	while(1) {

	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}



