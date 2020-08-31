cc=arm-none-eabi-gcc
mach=cortex-m3
cflags=-c -mcpu=$(mach) -mthumb -std=gnu11 -O0 -Wall
ldflags=-T *.ld -Wl,-Map=main.map
ldflags +=-nostdlib
ldflags +=-mcpu=$(mach) -mthumb
ldflags +=-mfloat-abi=soft
objs=stm32f103c8t6_startup.o

all: main.elf $(objs)

main.elf: *.ld $(objs) 
	$(cc) $(ldflags) $(objs) -o $@ 

%.o:%.c
	$(cc) $(cflags) $^ -o $@

clean:
	rm -rf *.o *.elf *.map
