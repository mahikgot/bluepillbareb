#include "gpio.h"
#include "rcc.h"
#include "stk.h"
#include <stdint.h>

extern void GPIO_init(volatile GPIO_t* port, uint8_t pin, uint8_t config);

extern void RCC_init_gpiox(volatile GPIO_t* port);

extern void STK_init(uint8_t ctrl, uint32_t load);

static volatile uint8_t toggle = 0;

void SysTick_handler(void) {
	toggle = 1;
}
int main(void) {
	RCC_init_gpiox(GPIOC);
	GPIO_init(GPIOC, (uint8_t) 13, (uint8_t) 0x2);
	STK_init((uint8_t) 0x3, (uint32_t) 0xF423F);
	while (1) {
		if (toggle) {
			GPIOC->ODR ^= 1<<13;		
			toggle = 0;
		}
	}
}
