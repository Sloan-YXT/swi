#include "tacc.h"
void tacc(int a)
{
    unsigned int *tacc=(unsigned int*)BANKCON0;
    *tacc =   a<<8;
}