#ifndef GPIO
#define GPIO
#include <stdint.h>
typedef struct {
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
} GPIO_t;

#define GPIOA ((volatile GPIO_t*) 0x40010800)
#define GPIOB ((volatile GPIO_t*) 0x40010C00)
#define GPIOC ((volatile GPIO_t*) 0x40011000)
#define GPIOD ((volatile GPIO_t*) 0x40011400)
#define GPIOE ((volatile GPIO_t*) 0x40011800)

void GPIO_init(volatile GPIO_t* port, uint8_t pin, uint8_t config);

#endif
