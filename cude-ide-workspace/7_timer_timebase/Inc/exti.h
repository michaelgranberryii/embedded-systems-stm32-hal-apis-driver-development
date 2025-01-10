/*
 * exti.h
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"

// BTN = PC13, BUS = AHB2EN Bit 0
#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13


void pc13_btn_init();



#endif /* EXTI_H_ */
