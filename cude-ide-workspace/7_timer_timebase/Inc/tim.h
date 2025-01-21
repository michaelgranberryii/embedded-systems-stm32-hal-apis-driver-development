/*
 * tim.h
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */

#ifndef TIM_H_
#define TIM_H_

#include "stm32l4xx_hal.h"

#define TIMx TIM3
#define _TIMx_CLK_ENABLE __HAL_RCC_TIM3_CLK_ENABLE()
#define TIMx_IRQn TIM3_IRQn
#define TIMx_IRQHandler TIM3_IRQHandler

void timTimebaseInit();
#endif /* TIM_H_ */
