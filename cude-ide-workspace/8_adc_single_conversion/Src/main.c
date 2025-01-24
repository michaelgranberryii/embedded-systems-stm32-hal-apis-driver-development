#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"


uint32_t sensor_value;
ADC_HandleTypeDef hadc12;

int main() {

	HAL_Init();
	uart2Init();
	adcPa0SingleConvInit();


	while(1) {

		// 1. start adc
		HAL_ADC_Start(&hadc12);
		// 2. polll for conversion
		HAL_ADC_PollForConversion(&hadc12, HAL_MAX_DELAY);
		// 3. get conversion
		sensor_value = pa0AdcRead();

		printf("sensor_value : %lu\n\r", sensor_value);
		HAL_Delay(10);
	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}
