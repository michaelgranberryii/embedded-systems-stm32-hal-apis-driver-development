/*
 * tim.c
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */


#include "tim.h"

TIM_HandleTypeDef timHandle;

// Configure timer to timeout every second
// 1 Hz
//
// System default freq = 4 MHz
// Default PCLK1 freq = 4 MHz
// Default PCLK2 freq = 4 MHz
// Timer prescaler : 400 => 4MHz/400 = 10kHz
// Timer period (auto reload value) = 10,000 = 10k
void timTimebaseInit() {

	_TIMx_CLK_ENABLE;


	timHandle.Instance = TIMx;
	timHandle.Init.Prescaler = 400-1; // 4MHz/400 = 10kHz
	timHandle.Init.Period = 10000-1;  // 10kHz / 10k = 1Hz
	timHandle.Init.ClockDivision = 0;
	timHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	timHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&timHandle);

	// Setup interrupt
	HAL_NVIC_SetPriority(TIMx_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIMx_IRQn);
	HAL_TIM_Base_Start_IT(&timHandle);

}


void TIMx_IRQHandler(void) {
	HAL_TIM_IRQHandler(&timHandle);
}
