#include "stm32l4xx_hal.h"
#include "uart.h"
#include "stdio.h"
#include "adc.h"


uint32_t sensor_value;
ADC_HandleTypeDef hadc12;

int main() {

	HAL_Init();
	uart2Init();
	adcPa0InterruptConvInit();
	HAL_ADC_Start_IT(&hadc12);

	while(1) {


	}
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	// do something

	// 3. get conversion
	sensor_value = pa0AdcRead();
	printf("sensor_value : %lu\n\r", sensor_value);
}

void SysTick_Handler(void) {
	HAL_IncTick();
}
