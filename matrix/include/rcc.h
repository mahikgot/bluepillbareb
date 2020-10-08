#ifndef RCC_h
#define RCC_h

#include "gpio.h"

typedef struct {
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
} RCC_t;

#define RCC ((volatile RCC_t*) 0x40021000)

void RCC_init_gpiox(volatile GPIO_t* port);
#endif
