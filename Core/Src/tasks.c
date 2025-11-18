/*
 * tasks.c
 *
 *  Created on: Nov 17, 2025
 *      Author: dinhh
 */

#include "tasks.h"

void getButton()
{
	getKeyInput(&button0);
	getKeyInput(&button1);
	getKeyInput(&button2);
}

void trafficLight()
{
	fsm_traffic_light();
}

void blinkyLED()
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}
