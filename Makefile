cc=arm-none-eabi-gcc
mach=cortex-m3
cflags=-c -mcpu=$(mach) -mthumb -std=gnu11 -O0 -Wall
ldflags=-T *.ld -Wl,-Map=main.map
ldflags +=-nostdlib
ldflags +=-mcpu=$(mach) -mthumb
ldflags +=-mfloat-abi=soft
objs=stm32f103c8t6_startup.o

all: main.elf main.bin $(objs) 

main.bin: main.elf
	arm-none-eabi-objcopy $^ $@ -O binary
	
main.elf: *.ld $(objs) 
	$(cc) $(ldflags) $(objs) -o $@ 

%.o:%.c
	$(cc) $(cflags) $^ -o $@

clean:
	rm -rf *.o *.elf *.map *.bin

flash:
	openocd -f interface/stlink.cfg -f board/stm32f103c8_blue_pill.cfg -c "program main.bin reset exit 0x08000000"
