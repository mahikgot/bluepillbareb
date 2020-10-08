#ifndef STK_h
#define STK_H

#include <stdint.h>
typedef struct {
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t vAL;
	uint32_t CALIB;
} STK_t;

#define STK ((volatile STK_t*) 0xE000E010)

void STK_init(uint8_t ctrl, uint32_t load);

#endif
