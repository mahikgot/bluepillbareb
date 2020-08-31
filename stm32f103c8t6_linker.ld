_sflash = 0x08000000;
_lflash = 64K;
_sram = 0x20000000;
_lram = 20K;
_estack = _sram + _lram;

ENTRY(Reset_handler)

MEMORY {
	flash(rx) :ORIGIN =_sflash, LENGTH =_lflash
	ram(rwx) :ORIGIN =_sram, LENGTH =_lram	
}

SECTIONS {
	.text :
	{
		*(.vector_tab)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;
	}> flash

	.data :
	{
		_sdata = .;
		*(.data)	
		. = ALIGN(4);
		_edata = .;
	}> ram AT> flash 

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}> ram
	
}
