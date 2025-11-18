/*
 * button.h
 *
 *  Created on: Nov 17, 2025
 *      Author: dinhh
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

struct ButtonStruct
{
	int keyBuffer[4];
	int timeOutForPressed;
	int isPressed;
	int isLongPress;
	GPIO_TypeDef *PORT;
	uint16_t PIN;
};

extern struct ButtonStruct button0;
extern struct ButtonStruct button1;
extern struct ButtonStruct button2;

void getKeyInput(struct ButtonStruct *button);
int isButtonPressed(struct ButtonStruct *button);
int isButtonLongPressed(struct ButtonStruct *button);

#endif /* INC_BUTTON_H_ */
