#include "ft_printf.h"

int nbr_digits(int n)
{
    int len = 0;
    if(n == 0)
        len += 1;
    if (n < 0)
        len += 1;
    while(n != 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}