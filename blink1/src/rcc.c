#include <stdint.h>
#include "rcc.h"
#include "gpio.h"


void RCC_GPIOx_enable(volatile GPIO_s* GPIOx)
{
	switch((uint32_t) &(GPIOC->CRL))
	{
		case 0x40010800:
			RCC->APB2ENR |= 0x1<<2;
			break;
		case 0x40010C00:
			RCC->APB2ENR |= 0x1<<3;
			break;
		case 0x40011000:
			RCC->APB2ENR |= 0x1<<4;
			break;
		case 0x40011400:
			RCC->APB2ENR |= 0x1<<5;
			break;
		case 0x40011800:
			RCC->APB2ENR |= 0x1<<6;
			break;
	}
}
