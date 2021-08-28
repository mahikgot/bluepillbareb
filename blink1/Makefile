#Tools used

CC 		= arm-none-eabi-gcc
OBJ 	= arm-none-eabi-objcopy

#Directories

SRCDIR 		= src
INCDIR 		= include
BUILDDIR 	= build

#Machine dependent variables

MACH			= cortex-m3
OOCDMACHCONF	= stm32f103c8_blue_pill.cfg
OOCDINTCONF		= stlink.cfg

#Compiler options

CFLAGS		= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -I$(INCDIR) -g

#Linker file

LINKER		= stm32f103c8_linker.ld

#Linker options

LDFLAGS		= -T$(LINKER) 						#specifies linker file							
LDFLAGS		+= -Wl,-Map=$(BUILDDIR)/main.map			#produces .map file, useful to see memory mapping of produced binary
LDFLAGS 	+= -nostdlib						#no standard system startup files and only the libraries you specify are passed to the linker
LDFLAGS 	+= -mcpu=$(MACH) -mthumb				#specifies target arm processor and specifies assembler to assemble thumb instructions
LDFLAGS 	+= -mfloat-abi=soft					#specifies software float computation since stm32f103c8 does not have floating point unit
LDFLAGS		+= -g							#add debug symbols to output file
#Objects files generated from .c files in src/ and include/

OBJECTS 	= $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(wildcard $(SRCDIR)/*.c))

#Commands

all: dir $(BUILDDIR)/main.elf $(BUILDDIR)/main.bin $(OBJECTS)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/main.bin: $(BUILDDIR)/main.elf
	$(OBJ) $^ $@ -O binary
	
$(BUILDDIR)/main.elf: $(LINKER) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ 

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(BUILDDIR)

flash:
	openocd -f interface/$(OOCDINTCONF) -f board/$(OOCDMACHCONF) -c "program $(BUILDDIR)/main.bin reset exit 0x08000000"

port:
	openocd -f interface/$(OOCDINTCONF) -f board/$(OOCDMACHCONF)
