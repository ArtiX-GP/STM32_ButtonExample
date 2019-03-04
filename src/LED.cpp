/*
 * LED.cpp
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: nikit
 */

#include "LED.h"

LED::LED() {
	// TODO Auto-generated constructor stub

}

LED::LED(int pin) {
	this->_Pin = pin;
	this->_GPIOType = GPIOB;

	GPIO_InitTypeDef _InitStruct;

	_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	_InitStruct.GPIO_Pin = this->_Pin;
	_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(this->_GPIOType, &_InitStruct);
}

LED::LED(int pin, GPIO_TypeDef* type) {
	this->_Pin = pin;
	this->_GPIOType = type;

	GPIO_InitTypeDef _InitStruct;

	_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	_InitStruct.GPIO_Pin = this->_Pin;
	_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(this->_GPIOType, &_InitStruct);
}

void LED::ledOn() {
	this->_Status = true;
	GPIO_WriteBit(this->_GPIOType, this->_Pin, Bit_SET);
}

void LED::ledOff() {
	this->_Status = false;
	GPIO_WriteBit(this->_GPIOType, this->_Pin, Bit_RESET);
}

void LED::ledSwitch() {
	this->_Status = !this->_Status;
	if (this->_Status) {
		this->ledOn();
	} else {
		this->ledOff();
	}
}

void LED::resetBits(GPIO_TypeDef* _GPIOx, int _GPIOs) {
	GPIO_ResetBits(_GPIOx, _GPIOs);
}


LED::~LED() {
	// TODO Auto-generated destructor stub
}

