/*
 * adc.h
 *
 *  Created on: Jan 7, 2025
 *      Author: mg
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32l4xx_hal.h"

void adcContinuousConvInit();
void adcInitStart();
uint32_t pa0AdcRead();

#endif /* ADC_H_ */
