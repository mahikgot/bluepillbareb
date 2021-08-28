#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "gpio.h"

typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t AHBRSTR;
	uint32_t CFGR2;
} RCC_s;

#define RCC ((volatile RCC_s*) 0x40021000)

void RCC_GPIOx_enable(volatile GPIO_s* GPIOx);

#endif
