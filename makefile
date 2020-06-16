all:main.bin  main.dis 
FLAG = arm-none-eabi-
main.bin:main.elf
	$(FLAG)objcopy -O binary -S main.elf main.bin
main.elf:led.o start.o uart.o tacc.o main.o init.o copy.o exception.o
	$(FLAG)ld -Tsct.lds start.o led.o main.o uart.o tacc.o init.o copy.o exception.o -o main.elf 
main.o:main.c
	$(FLAG)gcc -c main.c -o main.o 
start.o:start.s
	$(FLAG)gcc -c start.s -o start.o 
%.o:%.c %.h
	$(FLAG)gcc -c $< -o $@  
%.dis:%.elf
	$(FLAG)objdump -D $< >$@
clean:
	-rm *.o *.elf *.bin
.PHONY:all clean