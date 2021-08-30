#include <stdint.h>
#include "gpio.h"
#include "rcc.h"

// connect to port A pins from A to F with A as MSB
#define num0 0x7E
#define num1 0x30
#define num2 0x6D
#define num3 0x79
#define num4 0x33
#define num5 0x5B
#define num6 0x5F
#define num7 0x72
#define num8 0x7F
#define num9 0x73

void delay(void)
{
	uint32_t time = 0;
	while (time < 500000)
	{
		time++;
	}
	time = 0;
}
void light(uint8_t num)
{
	switch(num)
	{
		case 0:
			GPIOA->ODR = num0;
			break;
		case 1:
			GPIOA->ODR = num1;
			break;
		case 2:
			GPIOA->ODR = num2;
			break;
		case 3:
			GPIOA->ODR = num3;
			break;
		case 4:
			GPIOA->ODR = num4;
			break;
		case 5:
			GPIOA->ODR = num5;
			break;
		case 6:
			GPIOA->ODR = num6;
			break;
		case 7:
			GPIOA->ODR = num7;
			break;
		case 8:
			GPIOA->ODR = num8;
			break;
		case 9:
			GPIOA->ODR = num9;
			break;
	}
}
int main(void)
{
	RCC_GPIOx_enable(GPIOA);
	GPIOA->CRL = 0x22222222;
	uint8_t temp = 0;
	while (1)
	{
		if (temp < 10)
		{
			light(temp);
			delay();
			temp++;
		}
		else
		{
			temp = 0;
		}
	}
}

