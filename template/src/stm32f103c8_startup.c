/* system exceptions only, add interrupts as needed */
#include <stdint.h>
extern uint32_t _estack[];
extern uint32_t _sdata[];
extern uint32_t _edata[];
extern uint32_t _etext[];
extern uint32_t _sbss[];
extern uint32_t _ebss[];

int main(void);

void Reset_handler(void);
void NMI_handler(void) __attribute__ ((weak, alias("default_handler")));
void HardFault_handler(void) __attribute__ ((weak, alias("default_handler")));
void MemManage_handler(void) __attribute__ ((weak, alias("default_handler")));
void BusFault_handler(void) __attribute__ ((weak, alias("default_handler")));
void UsageFault_handler(void) __attribute__ ((weak, alias("default_handler")));
void SVCall_handler(void) __attribute__ ((weak, alias("default_handler")));
void Debug_Monitor_handler(void) __attribute__ ((weak, alias("default_handler")));
void PendSV_handler(void) __attribute__ ((weak, alias("default_handler")));
void SysTick_handler(void) __attribute__ ((weak, alias("default_handler")));


uint32_t vector_table[] __attribute__ ((section (".vector_tab"))) = {
	(uint32_t) _estack,
	(uint32_t) Reset_handler,
	(uint32_t) NMI_handler,
	(uint32_t) HardFault_handler,
	(uint32_t) MemManage_handler,
	(uint32_t) BusFault_handler,
	(uint32_t) UsageFault_handler,
	0,
	0,
	0,
	0,
	(uint32_t) SVCall_handler,
	(uint32_t) Debug_Monitor_handler,
	0,
	(uint32_t) PendSV_handler,
	(uint32_t) SysTick_handler,
};

void default_handler(void) {
	while(1);
};
void Reset_handler(void) {
	uint32_t size;
	uint32_t const *pSrc;
	uint32_t *pDst;
	
	size = _edata - _sdata;
	pSrc = _etext;
	pDst = _sdata;
	for(uint32_t i=0; i<size; i++)
	{
		*pDst++ = *pSrc++;	
	}

	size = _ebss - _sbss;
	for(uint32_t i=0; i<size; i++)
	{
		*pDst++ = 0;
	}

	main();
};
