#include "ft_printf.h"

int hex(unsigned int n, char c)
{
    int len;
    char *str;
    
    len  = 0;
    if(c == 'x')
        str = "0123456789abcdef";
    else if (c == 'X')
        str = "0123456789ABCDEF";
    if(n >= 16)
    {
        len += hex(n / 16, c);
        len += hex(n % 16, c);  
    }
    else 
        len += write(1, &str[n%16], 1);
    return (len);    
}