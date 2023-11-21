#include "libftprintf.h"

int hex_p(unsigned long n)
{
    int len;
    char *str;

    len  = 0;
    str = "0123456789abcdef";
    if(n >= 16)
    {
        len += hex_p(n/16);
        len += hex_p(n % 16);  
    }
    else 
        len += write(1, &str[n % 16], 1);
    return (len);    
}