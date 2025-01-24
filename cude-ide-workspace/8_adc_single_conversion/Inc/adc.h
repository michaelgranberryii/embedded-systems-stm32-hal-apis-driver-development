/*
 * adc.h
 *
 *  Created on: Jan 7, 2025
 *      Author: mg
 */

#ifndef ADC_H_
#define ADC_H_


void adcContinuousConvInit();
void adcPa0SingleConvInit();
void adcInitStart();
uint32_t pa0AdcRead();

#endif /* ADC_H_ */
