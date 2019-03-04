#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#include "LED.h"

int main(int argc, char* argv[])
{
	unsigned int i = 0;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef _InitStruct;

	_InitStruct.GPIO_Pin = GPIO_Pin_3;
	_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOA, &_InitStruct);

	LED _LED3(GPIO_Pin_5, GPIOB);
	LED _LED2(GPIO_Pin_8, GPIOB);
	LED _LED1(GPIO_Pin_9, GPIOB);

	unsigned int freq = 0x5000;

	while (1) {
		if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)) {
//			Нажали на BTN_3 - уменьшаем предел, увеличиваем частоту.

			if (freq > 0) {
				freq--;
				_LED2.ledOff();
			} else {
				_LED2.ledOn();
			}

			_LED3.ledOn();
			i = 0;
		} else if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)) {
//			Нажали на BTN_2 - увеличиваем предел, уменьшаем частоту.

			if (freq < 0x100000) {
				freq++;
				_LED3.ledOff();
			} else {
				_LED3.ledOn();
			}

			_LED2.ledOn();
			i = 0;
		} else {
//			Ни одна кнопка не нажата, можно переключать светодиод.

			if (i >= freq) {
				_LED1.ledSwitch();
				i = 0;
			}

			_LED2.ledOff();
			_LED3.ledOff();

			i++;
		}
	}
}
