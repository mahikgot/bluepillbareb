#include "rcc.h"
uint32_t panget = 0XDEEEDEEE;
void RCC_init_gpiox(volatile GPIO_t* port) {
	uint32_t dd;	
	switch ((uint32_t) port){
		case (uint32_t) &*GPIOA:
			RCC->APB2ENR |= 0x1<<2;
		case (uint32_t) &*GPIOB:
			RCC->APB2ENR |= 0x1<<3;
		case (uint32_t) &*GPIOC:
			RCC->APB2ENR |= 0x1<<4;
			dd = 0xDEADBEEF;
		case (uint32_t) &*GPIOD:
			RCC->APB2ENR |= 0x1<<5;
		case (uint32_t) &*GPIOE:
			RCC->APB2ENR |= 0x1<<6;
	}
}
