#include "stk.h"

void STK_init(uint8_t ctrl, uint32_t load) {
	STK->CTRL |= ctrl;
	STK->LOAD |= load;
}
