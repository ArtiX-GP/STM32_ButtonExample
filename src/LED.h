/*
 * LED.h
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: nikit
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f10x_gpio.h"

class LED {
private:
	bool _Status;
	int _Pin;
	GPIO_TypeDef* _GPIOType;
public:
	LED();
	LED(int pin);
	LED(int pin, GPIO_TypeDef* type);
	virtual ~LED();

	void ledOn();

	void ledOff();

	void ledSwitch();

	void resetBits(GPIO_TypeDef* _GPIOx, int _GPIOs);
};

#endif /* LED_H_ */
