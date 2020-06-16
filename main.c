#include "uart.h"
#include "tacc.h"
int main(void)
{
	puts("\nmain!");
    //uart0_init();
    retry:puts("\nplease enter numbers between 0-7");
    char in = getchar();
    if(in>'7'|in<'1')
    {
        puts("please enter 0 - 7!");
        goto retry;
    }
    putchar(in);
    tacc(in-'0');
    led_run();
}
void putError(unsigned int a,char *b)
{
    putHex(a);
    putchar('\n');
    puts(b);
}