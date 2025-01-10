/*
 * led.h
 *
 *  Created on: Jan 9, 2025
 *      Author: mg
 */

#ifndef LED_H_
#define LED_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"

// LED = PA5,  BUS = AHB2EN Bit 2
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5


void pa5_led_init(void);


#endif /* LED_H_ */
