#include <stdint.h>

/*blue pill led is on pin PC13, which means its on the 13th pin of Port C*/
#define PIN 13

/*base address of peripheral registers - Section 5 of STM32F103C8 Datasheet*/
#define PORTC 	0x40011000 	
#define RCC 	0x40021000 		

/*register offsets of GPIOx_CRH, GPIOx_ODR, and RCC_APB2ENR - Section 9.2.2, 9.2.3 and 7.3.7 of RM0008, respectively*/
#define GPIOx_CRH_OFFSET 		0x04
#define GPIOx_ODR_OFFSET 		0x0C
#define RCC_APB2ENR_OFFSET		0x18

void gpioc_clock_enable(void)
{
	uint32_t * const pRCC_APB2ENR = (uint32_t *) (RCC+RCC_APB2ENR_OFFSET);
	*pRCC_APB2ENR |= 1<<4; //Section 7.3.7 of RM0008 shows that setting bit 4 of the register enables the IO port C clock
}

void pc13_output_mode_set(void)
{
	uint32_t * const pGPIOC_CRH = (uint32_t *) (PORTC+GPIOx_CRH_OFFSET);
	/*clear involved pins for easier setting*/
	*pGPIOC_CRH &= ~(1111UL<<20);
	
	*pGPIOC_CRH |= 0010UL<<20; //Section 9.2.2 of RM0008 shows corresponding bit configuration
}

void led_on(void)
{
	uint32_t * const pGPIOC_ODR = (uint32_t *) (PORTC+GPIOx_ODR_OFFSET);

	/*
	 *Looking at the schematic of the blue pill board, one would discover that the anode of the led is connected to vcc
	 *while the cathode is connected to PC13.
	 *Pulling the cathode low would cause the led to light up because of the voltage between the diode.
	*/
	*pGPIOC_ODR &= ~(1UL<<13); //Section 9.2.4 of RM0008
}

int main()
{
	/*turn on clock for GPIOC Port - Section 7.2 of RM0008*/
	gpioc_clock_enable();

	/*set pin 13 of Port C to 2 MHz Output mode and set pin as push-pull*/
	pc13_output_mode_set();

	/*turn led on*/
	led_on();

	while(1);

		
}
