SECTIONS
{
	. = 0x30000000;
	_code_start = . ;
	.text :
	{
		*(.text)
	}
	. = ALIGN(4);
	.data :
	{
		*(.data)
	}
	. = ALIGN(4);
	.rodata :
	{
		*(.rodata)
	}
	. = ALIGN(4);
	_bss_start = .;
	.bss :
	{
		*(.bss) *(.COMMON)
	}
	_end = .;
}