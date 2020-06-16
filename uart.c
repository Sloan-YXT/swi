#include "uart.h"
void uart0_init()
{
    unsigned int * gphcon = GPHCON,*gphup=GPHUP,*ulcon=ULCON0,*ucon=UCON0,*ubrdiv0 = UBRDIV0;
   *gphcon &= ~(3<<4|3<<6);
   *gphcon |= 2<<4|2<<6;
    *gphup &= ~(1<<2|1<<3);
    *ulcon = 3;
    *ucon = 5;
    *ubrdiv0 = 26;
}
int getchar(void)
{
    unsigned int * uartstat = UARTSTAT0;
    while(!(*uartstat&1));
    return *(unsigned char*) URXH0;
}
void putchar(char c)
{
    unsigned int *uartstat = UARTSTAT0;
    while(!(*uartstat&1<<2));
    *(unsigned char*)UTXH0 = c;
    if(c=='\n'){
    while(!(*uartstat&1<<2));
    *(unsigned char*)UTXH0 = '\r';
    }
    if(c=='\r'){
    while(!(*uartstat&1<<2));
    *(unsigned char*)UTXH0 = '\n';
    }
}
char* puts(char *s)
{
    char *p = s;
    while(*s)
    {
        putchar(*s);
        s++;
    }
    putchar('\n');
    return p;
}
void putHex(unsigned int a)
{
    int i;
    unsigned char b[8];
    for(i=0;i<8;i++)
    {
        b[i]=a&0xf;
        a>>=4;
    }
    putchar('0');putchar('X');
    for(i=7;i>=0;i--)
    {
        if(b[i]>=0&&b[i]<=9)
        {
            putchar(b[i]+'0');
        }
        else
        {
            putchar(b[i]-0xA+'A');
        }
        
    }
}