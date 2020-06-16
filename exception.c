#include "uart.h"
void swi_exception(unsigned int *state)
{
	unsigned int val = *state &=~(0xff000000);
	putHex(state);
	puts("SWI val = ");
	putHex(val);
}