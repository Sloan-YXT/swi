extern int _code_start,_bss_start,_end;
void sdram_copy()
{
	
	volatile unsigned int *start = &_code_start;
	volatile unsigned int *end = &_bss_start;
	volatile unsigned int *src = 0;
	while(start<end)
	{
		*start++=*src++;
	}
}
void bss_clean()
{
	volatile unsigned int *start = &_bss_start;
	volatile unsigned int *end = &_end;
	while(start < end)
	{
		*start ++ = 0;
	}
}