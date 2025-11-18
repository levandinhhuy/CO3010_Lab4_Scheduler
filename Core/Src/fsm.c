/*
 * fsm.c
 *
 *  Created on: Nov 17, 2025
 *      Author: dinhh
 */

#include "fsm.h"

enum TrafficLightState TRAFFIC_LIGHT_STATE = INIT;

void fsm_traffic_light()
{
	switch (TRAFFIC_LIGHT_STATE)
	{
	case INIT:
		init_auto_red_grn();
		TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
		break;
	case AUTO_RED_GRN:
		auto_red_grn();
		if (isFlag(TIMER_TRAFFIC_LIGHT))
		{
			init_auto_red_yel();
			TRAFFIC_LIGHT_STATE = AUTO_RED_YEL;
		}
		else if (isButtonPressed(&button0))
		{
			init_red_time_config();
			TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
		}
		break;
	case AUTO_RED_YEL:
		auto_red_yel();
		if (isFlag(TIMER_TRAFFIC_LIGHT))
		{
			init_auto_grn_red();
			TRAFFIC_LIGHT_STATE = AUTO_GRN_RED;
		}
		else if (isButtonPressed(&button0))
		{
			init_red_time_config();
			TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
		}
		break;
	case AUTO_GRN_RED:
		auto_grn_red();
		if (isFlag(TIMER_TRAFFIC_LIGHT))
		{
			init_auto_yel_red();
			TRAFFIC_LIGHT_STATE = AUTO_YEL_RED;
		}
		else if (isButtonPressed(&button0))
		{
			init_red_time_config();
			TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
		}
		break;
	case AUTO_YEL_RED:
		auto_yel_red();
		if (isFlag(TIMER_TRAFFIC_LIGHT))
		{
			init_auto_red_grn();
			TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
		}
		else if (isButtonPressed(&button0))
		{
			init_red_time_config();
			TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
		}
		break;
	case RED_TIME_CONFIG:
		red_time_config();
		if (isButtonPressed(&button0))
		{
			init_yel_time_config();
			TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
		}
		break;
	case YEL_TIME_CONFIG:
		yel_time_config();
		if (isButtonPressed(&button0))
		{
			init_grn_time_config();
			TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
		}
		break;
	case GRN_TIME_CONFIG:
		grn_time_config();
		if (isButtonPressed(&button0))
		{
			init_auto_red_grn();
			TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
		}
		break;
	default:
		break;
	}
}

void turn_red_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_yel_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_grn_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_ON);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void turn_on_red_grn()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void turn_on_red_yel()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_grn_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_ON);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_yel_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void init_auto_red_grn()
{
	setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = red_time;
	counter_way1 = grn_time;
	update_led_7seg_buffer();
}

void auto_red_grn()
{
	turn_on_red_grn();

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_red_yel()
{
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = yel_time;
	counter_way1 = yel_time;
	update_led_7seg_buffer();
}

void auto_red_yel()
{

	turn_on_red_yel();

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_grn_red()
{
	setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = grn_time;
	counter_way1 = red_time;
	update_led_7seg_buffer();
}

void auto_grn_red()
{
	turn_on_grn_red();

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_yel_red()
{
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = yel_time;
	counter_way1 = yel_time;
	update_led_7seg_buffer();
}

void auto_yel_red()
{
	turn_on_yel_red();

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_red_time_config()
{
	red_temp_time = red_time;

	turn_red_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = red_temp_time;
	counter_way1 = 2;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}

void red_time_config()
{
	if (isButtonPressed(&button1))
	{
		++red_temp_time;
	}
	if (isButtonLongPressed(&button1))
	{
		red_temp_time += 5;
	}
	if (red_temp_time > MAX_COUNTER)
	{
		red_temp_time = MIN_COUNTER;
	}
	if (isButtonPressed(&button2))
	{
		if (red_temp_time > yel_time)
		{
			red_time = red_temp_time;
			grn_time = red_time - yel_time;
		}
	}

	counter_way0 = red_temp_time;
	update_led_7seg_buffer();

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);

		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_7SEG_STATUS))
	{
		if (red_temp_time != red_time) {
			if (status_4digits[0] == LED_ON)
			{
				status_4digits[0] = LED_OFF;
				status_4digits[1] = LED_OFF;
			}
			else
			{
				status_4digits[0] = LED_ON;
				status_4digits[1] = LED_ON;
			}
		} else {
			status_4digits[0] = LED_ON;
			status_4digits[1] = LED_ON;
		}
		setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
	}
}

void init_yel_time_config()
{
	yel_temp_time = yel_time;

	turn_yel_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = yel_temp_time;
	counter_way1 = 3;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}

void yel_time_config()
{
	if (isButtonPressed(&button1))
	{
		++yel_temp_time;
	}
	if (isButtonLongPressed(&button1))
	{
		yel_temp_time += 5;
	}
	if (yel_temp_time > MAX_COUNTER)
	{
		yel_temp_time = MIN_COUNTER;
	}

	if (isButtonPressed(&button2))
	{
		if (red_time > yel_temp_time)
		{
			yel_time = yel_temp_time;
			grn_time = red_time - yel_time;
		}
	}

	counter_way0 = yel_temp_time;
	update_led_7seg_buffer();

    if (isFlag(TIMER_250MS))
    {
        HAL_GPIO_TogglePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin);
        HAL_GPIO_TogglePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin);
        setTimer(TIMER_250MS, TIME_250MS);
    }

    if (isFlag(TIMER_7SEG))
    {
        display_4digits();
        setTimer(TIMER_7SEG, TIME_7SEG);
    }

    if (isFlag(TIMER_7SEG_STATUS))
    {
        if (yel_temp_time != yel_time) {
            if (status_4digits[0] == LED_ON)
            {
                status_4digits[0] = LED_OFF;
                status_4digits[1] = LED_OFF;
            }
            else
            {
                status_4digits[0] = LED_ON;
                status_4digits[1] = LED_ON;
            }
        } else {
            status_4digits[0] = LED_ON;
            status_4digits[1] = LED_ON;
        }
        setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
    }
}

void init_grn_time_config()
{
	grn_temp_time = grn_time;

	turn_grn_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = grn_temp_time;
	counter_way1 = 4;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}

void grn_time_config()
{
	if (isButtonPressed(&button1))
	{
		++grn_temp_time;
	}
	if (isButtonLongPressed(&button1))
	{
		grn_temp_time += 5;
	}
	if (grn_temp_time > MAX_COUNTER)
	{
		grn_temp_time = MIN_COUNTER;
	}

	if (isButtonPressed(&button2))
	{
		grn_time = grn_temp_time;
		red_time = grn_time + yel_time;
	}

	counter_way0 = grn_temp_time;
	update_led_7seg_buffer();

    if (isFlag(TIMER_250MS))
    {
        HAL_GPIO_TogglePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin);
        HAL_GPIO_TogglePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin);
        setTimer(TIMER_250MS, TIME_250MS);
    }

    if (isFlag(TIMER_7SEG))
    {
        display_4digits();
        setTimer(TIMER_7SEG, TIME_7SEG);
    }

    if (isFlag(TIMER_7SEG_STATUS))
    {
        if (grn_temp_time != grn_time) {
            if (status_4digits[0] == LED_ON)
            {
                status_4digits[0] = LED_OFF;
                status_4digits[1] = LED_OFF;
            }
            else
            {
                status_4digits[0] = LED_ON;
                status_4digits[1] = LED_ON;
            }
        } else {
            status_4digits[0] = LED_ON;
            status_4digits[1] = LED_ON;
        }
        setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
    }
}

