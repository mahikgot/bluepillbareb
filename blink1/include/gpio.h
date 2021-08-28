#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
} GPIO_s;

#define GPIOA ((volatile GPIO_s*) 0x40010800)
#define GPIOB ((volatile GPIO_s*) 0x40010C00)
#define GPIOC ((volatile GPIO_s*) 0x40011000)
#define GPIOD ((volatile GPIO_s*) 0x40011400)
#define GPIOE ((volatile GPIO_s*) 0x40011800)

void GPIOx_pin_config(volatile GPIO_s* GPIOx, uint8_t pin, uint8_t config);

#endif
