.global _start
.text
b reset
b undef
b swi_handler
undef:
ldr sp,=0x30040000
stmdb sp!,{r0-r12,lr}
mrs r0,cpsr
ldr r1,=Undef
bl putError
ldmia sp!,{r0-r12,pc}^ 
halt:
ldr r0,=halted
bl puts
b halt	
#这个死循环不起作用，因为在弹栈时恢复了cpsr和pc，所以每个未定义指令都被执行了
Undef:.string "Error:undef instruction"
.align 4
halted:.string "halted!"
.align 4
swi_message:.string"Error:swi interrupt!"
.align 4
swi_handler:
ldr sp,=0x30060000
stmfd sp!,{r0-r12,lr}
mrs r0,cpsr
ldr r1,=swi_message
mov r4,lr
bl putError	
sub r0,r4,#4
bl swi_exception
ldmfd sp!,{r0-r12,pc}^
reset:
_start:
ldr r0,=0x4c000000
ldr r1,=0xFFFFFFFF
str r1,[r0]



ldr r0,=0x4c000014
mov r1,#5
str r1,[r0]

mrc p15,0,r0,c1,c0,0
orr r0,r0,#0xc0000000
mcr p15,0,r0,c1,c0,0

ldr r0,=0x4c000004
ldr r1,=(0x5c<<12|1<<4|1)
str r1,[r0]
mov r0,#0
ldr r1,=0x53000000
str r0,[r1]
mov r0,#0
str r0,[r0]
ldr r0,[r0]
cmp r0,#0
ldreq sp,=4096
ldrne sp,=0x40000000+4096
bl sdram_init
bl sdram_copy
bl bss_clean
ldr pc,=ram_code
ram_code:
bl uart0_init
mrs r0,cpsr
bic r0,#0xf
msr cpsr_c,r0
ldr sp,=0x30001000
ldr r0,=main
blx r0
.word 0xdeadc0de
.word 0xdeadc0de
.word 0xdeadc0de
.word 0xdeadc0de
.word 0xdeadc0de
swi 0x123
bl main	
message:.string "hello"
.align 4
