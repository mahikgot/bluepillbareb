#include <stdint.h>

#define PIN 13

#define RCC 0x40021000
#define PORTC 0x40011000

#define RCC_APB2ENR 0x18
#define GPIOX_CRH 0x04
#define GPIOX_ODR 0x0C

void gpiox_clock_enable(uint32_t offset)
{
	uint32_t volatile * const rcc_port_address = (uint32_t *) (RCC + offset); 	
	*rcc_port_address |= 0x1<<4;
}


void led_on(void)
{
	uint32_t volatile * const gpioc_crh = (uint32_t *) (PORTC + GPIOX_CRH);
	uint32_t volatile * const gpioc_odr = (uint32_t *) (PORTC + GPIOX_ODR);
	*gpioc_crh ^= 0xA<<19;
	*gpioc_odr |= 0x0<<13;
}
int main()
{
	gpiox_clock_enable((uint32_t) RCC_APB2ENR);
	led_on();
}
