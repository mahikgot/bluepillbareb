#include <stdint.h>
#include "gpio.h"

void GPIOx_pin_config(volatile GPIO_s* GPIOx, uint8_t pin, uint8_t config)
{
	if (pin < 8)
	{
		GPIOx->CRL &= ~(0xF<<(pin*4));
		GPIOx->CRL |= config<<(pin*4);
	}
	else
	{
		GPIOx->CRH &= ~(0xF<<((pin-8)*4));
		GPIOx->CRH |= config<<((pin-8)*4);
	}

}

