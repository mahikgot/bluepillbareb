#include <stdint.h>

/*blue pill led is on pin PC13, which means its on the 13th pin of Port C*/
#define PIN 13

/*base address of peripheral registers - Section 5 of STM32F103C8 Datasheet*/
#define PORTC 	0x40011000 	
#define RCC 	0x40021000 		

/*base address of systick register block - Section 4.5.6 of PM0056*/
#define SYSTICK 0xE000E010 

/*register offsets of GPIOx_CRH, GPIOx_ODR, and RCC_APB2ENR - Section 9.2.2, 9.2.3 and 7.3.7 of RM0008, respectively*/
#define GPIOx_CRH_OFFSET 		0x04
#define GPIOx_ODR_OFFSET 		0x0C
#define RCC_APB2ENR_OFFSET		0x18

/*register offsets of systick registers - Section 4.5 of PM0056*/
#define STK_CTRL_OFFSET 	0x00
#define STK_LOAD_OFFSET 	0x04
#define STK_VAL_OFFSET 		0x08

#define DELAY_MS_HEX 0x7A0E18 //must not exceed 0xFFFFFF
volatile uint8_t toggle = 1;

void systick_init(void)
{
	uint32_t * const pSTK_CTRL = (uint32_t *) (SYSTICK+STK_CTRL_OFFSET);
	uint32_t * const pSTK_LOAD = (uint32_t *) (SYSTICK+STK_LOAD_OFFSET);
	uint32_t * const pSTK_VAL = (uint32_t *) (SYSTICK+STK_VAL_OFFSET);

	*pSTK_LOAD |= DELAY_MS_HEX; 	//set load and val value such that an interrupt will be triggered every DELAY_MS_HEX milliseconds
	*pSTK_VAL |= DELAY_MS_HEX;		//formula: DELAY_MS_HEX = (SysTick Clock * desired time delay in ms) - 1
	*pSTK_CTRL |= 0x7; 				//enable systick and interrupt request, and selected processor clock as systick clock
}

void gpioc_clock_enable(void)
{
	uint32_t * const pRCC_APB2ENR = (uint32_t *) (RCC+RCC_APB2ENR_OFFSET);

	*pRCC_APB2ENR |= 1U<<4; 			//Section 7.3.7 of RM0008 shows that setting bit 4 of the register enables the IO port C clock
}

void pc13_output_mode_set(void)
{
	uint32_t * const pGPIOC_CRH = (uint32_t *) (PORTC+GPIOx_CRH_OFFSET);

	*pGPIOC_CRH &= ~(1111U<<20); 	//clear involved pins for easier setting
	*pGPIOC_CRH |= 0010U<<20; 		//Section 9.2.2 of RM0008 shows corresponding bit configuration
}

void led_toggle(void)
{
	static uint32_t * const pGPIOC_ODR = (uint32_t *) (PORTC+GPIOx_ODR_OFFSET);
	/*
	 *Looking at the schematic of the blue pill board, one would discover that the anode of the led is connected to vcc
	 *while the cathode is connected to PC13.
	 *Pulling the cathode low would cause the led to light up because of the voltage between the diode.And vice versa.
	*/
	if (toggle)
	{
		*pGPIOC_ODR ^= 1U<<13; 		//Section 9.2.4 of RM0008
		toggle = 0;
	}
}

void SysTick_handler(void)
{
	/*
	 * this interrupt is called whenever STK_VAL decrements to zero, which is every 1125 milliseconds set in
	 * systick_init
	*/
	toggle = 1;
}
int main()
{
	gpioc_clock_enable(); 			//turn on clock for GPIOC Port - Section 7.2 of RM0008
	pc13_output_mode_set(); 		//set pin 13 of Port C to 2 MHz Output mode and set pin as push-pull
	systick_init();
	while(1)
	{
		led_toggle();
	}
		
}
