/*
 * tasks.c
 *
 *  Created on: Nov 17, 2025
 *      Author: dinhh
 */

#include "tasks.h"

void blinkyLEDRed()
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void blinkyLEDBlue()
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}

void blinkyLEDPurple()
{
	HAL_GPIO_TogglePin(LED_PURPLE_GPIO_Port, LED_PURPLE_Pin);
}

void get3Buttons()
{
	getKeyInput(&button0);
	getKeyInput(&button1);
	getKeyInput(&button2);
}

void trafficLight()
{
	fsm_traffic_light();
}

