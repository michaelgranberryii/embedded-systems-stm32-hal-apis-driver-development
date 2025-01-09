/*
 * adc.c
 *
 *  Created on: Jan 7, 2025
 *      Author: mg
 */


#include "stm32l4xx_hal.h"
#include "adc.h"

ADC_HandleTypeDef hadc12;


uint32_t pa0AdcRead() {
	return HAL_ADC_GetValue(&hadc12);
}

void adcInitStart() {
	adcContinuousConvInit();
	HAL_ADC_Start(&hadc12);
}

void adcContinuousConvInit() {
	GPIO_InitTypeDef gpioStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};

	// ADC12_IN5 - PA0
	// configure pa0 as analog pin
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpioStruct.Pin = GPIO_PIN_0;
	gpioStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &gpioStruct);

	// configure adc module for contiuous conversion
	__HAL_RCC_ADC_CLK_ENABLE();
	hadc12.Instance = ADC1;
	hadc12.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc12.Init.Resolution = ADC_RESOLUTION_12B;
	hadc12.Init.ContinuousConvMode = ENABLE;
	hadc12.Init.DiscontinuousConvMode = DISABLE;
	hadc12.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc12.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc12.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc12.Init.NbrOfConversion = 1;
	hadc12.Init.DMAContinuousRequests = DISABLE;
	hadc12.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	HAL_ADC_IRQHandler(&hadc12);

	// ADC channel congif
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_640CYCLES_5;
	HAL_ADC_ConfigChannel(&hadc12, &sConfig);

}
