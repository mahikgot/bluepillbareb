#include "gpio.h"
#include "rcc.h"
#include <stdint.h>

extern void GPIO_init(volatile GPIO_t* port, uint8_t pin, uint8_t config);

extern void RCC_init_gpiox(volatile GPIO_t* port);

static uint32_t time;

void delay(void) {
	time = 0;
	while (time < 20000) {
		time += 1;
	}
}
int main(void) {
	RCC_init_gpiox(GPIOC);
	GPIO_init(GPIOC, (uint8_t) 13, (uint8_t) 0x2);
	while (1) {
		GPIOC->ODR ^= 1<<13;		
		delay();
	}
}
