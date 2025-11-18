/*
 * tasks.c
 *
 *  Created on: Nov 17, 2025
 *      Author: dinhh
 */

#include "tasks.h"

void blinkyLEDBlue()
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}

void blinkyLEDPurple()
{
	HAL_GPIO_TogglePin(LED_PURPLE_GPIO_Port, LED_PURPLE_Pin);
}

void trafficLight()
{
	if (isFlag(TIMER_STATUS))
	{
	  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  setTimer(TIMER_STATUS, TIME_STATUS);
	}

	if (isFlag(TIMER_READ_BTN))
	{
		getKeyInput(&button0);
		getKeyInput(&button1);
		getKeyInput(&button2);
		setTimer(TIMER_READ_BTN, TIME_READ_BTN);
	}

	fsm_traffic_light();
}

