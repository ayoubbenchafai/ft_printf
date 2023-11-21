#include <stdio.h>
#include "libftprintf.h"
int main() 
{

    int num =255;

    int *ptr= &num;

    int a = ft_printf(" a= %f");
    printf("\n");

    int b = ft_printf(" b= %f");

    printf("\na = %d,\n,b = %d\n",a,b);

    return 0;
}