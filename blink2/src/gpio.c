#include "gpio.h"

void GPIO_init(volatile GPIO_t* port,uint8_t pin, uint8_t config){
	if (pin < 7) {
		port->CRL &= ~((0xF)<<(4*pin));		
		port->CRL |= (config>>1)<<(4*pin);
	}
	else {
		port->CRH &= ~(0xF<<(4*(pin-8)));		
		port->CRH |= (config>>1)<<(4*(pin-8)); 

	}
	
	port->ODR |= ((config<<7)>>7)<<pin;
}
