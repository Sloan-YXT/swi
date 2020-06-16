#define GPFCON 0x56000050
#define GPFDAT 0x56000054

int led_run()
{
    unsigned int *gpfcon = GPFCON;
    unsigned int *gpfdat = GPFDAT;
    *gpfcon = 1<<12|1<<10|1<<8;
    int i=4;
    while(1)
    {
        if(i==7)i=4;
        *gpfdat=~(1<<i);
        delay(10000);
        i++;
    } 
}
void delay(int i)
{
    while(i--);
}
