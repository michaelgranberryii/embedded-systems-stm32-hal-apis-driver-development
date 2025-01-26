#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"


uint32_t sensor_value;

int main() {

	HAL_Init();
	uart2_init();
	adcInitStart();


	while(1) {
		sensor_value = pa0AdcRead();
		printf("sensor_value : %lu\n\r", sensor_value);
		HAL_Delay(10);
	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}
