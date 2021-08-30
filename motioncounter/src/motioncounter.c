#include <stdint.h>
#include "gpio.h"
#include "rcc.h"

// connect to port A pins from A to F with A as MSB
#define num0 0x3E
#define num1 0x30
#define num2 0x6D
#define num3 0x79
#define num4 0x33
#define num5 0x5B
#define num6 0x5F
#define num7 0x72
#define num8 0x7F
#define num9 0x73

void light(uint32_t num)
{
	GPIOA->ODR = num;
}
int main(void)
{
	RCC_GPIOx_enable(GPIOA);
	GPIOA->CRL = 0x22222222;
	light(num7);
	
}
