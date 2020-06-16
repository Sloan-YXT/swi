#ifndef uart
#define uart
#define GPHCON 0X56000070
#define ULCON0 0x50000000
#define GPHUP 0X56000078 
#define UCON0 0x50000004
#define UFCON0 0x50000008
#define UARTSTAT0 0x50000010
#define UFSTAT0 0x50000018
#define UMSTAT0 0x5000001c
#define UTXH0   0x50000020
#define URXH0   0X50000024
#define UBRDIV0 0x50000028
void putchar(char);
char *puts(char *);
int getchar(void);
void uart0_init(void);
void putHex(unsigned int);
#endif