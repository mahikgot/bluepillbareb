/* 
 * This linker file is used to instruct the compiler how to "combine" all the objects into one executable file.
 * It specifically instructs the compiler to place the different sections of the program into different locations in
 * memory.
*/

_sflash = 0x08000000;
_lflash = 64K;
_sram = 0x20000000;
_lram = 20K;
_estack = _sram + _lram;

/* 
 * ENTRY() specifies the entry point of your program, in this case we set it to the Reset_handler which gets called
 * everytime the board is reset.
*/
ENTRY(Reset_handler)

/* MEMORY informs the linker about the available memory regions of your target and their attributes. */
MEMORY {
	flash(rx) :ORIGIN =_sflash, LENGTH =_lflash
	ram(rwx) :ORIGIN =_sram, LENGTH =_lram	
}

/* 
 * Tells the compiler how to map the different sections of your input files into your target's memory.
 * The different symbols such as _etext, _sdata, etc. are used by the startup file to copy the .data and .bss section
 * into ram at reset.
*/
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
