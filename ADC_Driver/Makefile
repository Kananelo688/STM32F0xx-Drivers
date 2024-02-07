#Makefile for automated compilation of source files for the GPIO Driver development

GCC = arm-none-eabi-gcc#specify the GCC compiler

CFLAGS  = -c -O2 -mcpu=cortex-m0 -mthumb -std=gnu11 -w -I/home/chabeli/Desktop/Repositories/STM32F0xx-Drivers/inc/ -Iinc/ -I/home/chabeli/Desktop/Repositories/STM32F0xx-Drivers/GPIO_Driver/inc/

LDFLAGS =  -T ~/Desktop/Repositories/STM32F0xx-Drivers/ld/stm32f0xx_linker_script.ld -nostdlib -Wl,-Map=final.map -mcpu=cortex-m0 -mthumb


all: bin/final.elf obj/main.o obj/stm32f0xx_start_up.o obj/stm32f0xx_adc.o

#command for compiling main.c
obj/main.o: src/main.c
	$(GCC) $(CFLAGS) -o $@ $^

#command for compiling stm32f0xx_driver.c
obj/stm32f0xx_drivers.o: ~/Desktop/Repositories/STM32F0xx-Drivers/src/stm32f0xx_drivers.c
	$(GCC) $(CFLAGS) -o $@ $^

#command for compiling stm32f0xx_start_up
obj/stm32f0xx_start_up.o: ~/Desktop/Repositories/STM32F0xx-Drivers/src/stm32f0xx_start_up.c
	$(GCC) $(CFLAGS) -o $@ $^

#command for  generating the final executable
bin/final.elf: obj/stm32f0xx_start_up.o obj/main.o obj/stm32f0xx_adc.o
	$(GCC) $(LDFLAGS) -o $@ $^

obj/stm32f0xx_adc.o: src/stm32f0xx_adc_driver.c
	$(GCC) $(CFLAGS) -o $@ $^

#Command that cleans the object, executable and map files
clean:
	rm obj/*.o bin/*.elf *.map

#command that open openocd serverfor debugging over the arm-none-eabi-gdb 
load:
	openocd -f interface/stlink-v2.cfg -f target/stm32f0x.cfg

#command that dubug the remote target

debug:
	arm-none-eabi-gdb

#command that display Map file of the final executable for analysis
elf: bin/final.elf
	arm-none-eabi-objdump -D bin/final.elf
