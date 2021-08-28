#include <stdint.h> 
#include "gpio.h"
#include "rcc.h"

void blink(void)
{
	uint32_t time = 0;
	while (1)	
	{
		while (time < 20000)
		{
			time++;
		}
		time = 0;
		GPIOC->ODR ^= 0x1<<13;
	}
}

int main(void)
{
	RCC_GPIOx_enable(GPIOC);
	GPIOx_pin_config(GPIOC, 13, 0x2);
	blink();

}
