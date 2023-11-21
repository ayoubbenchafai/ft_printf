#include "ft_printf.h"

int check_conversions(const char *s, va_list ap)
{
    int len;

    len  = 0;
    if(*s == 'c')
    {
        char c = va_arg(ap, int);
        len += ft_putchar(c);
    }
    else if(*s == 's')
    {
        char *s = va_arg(ap , char *);
        len += ft_putstr(s);
    }
    else if(*s == 'd' || *s == 'i')
    {
        int d = va_arg(ap, int);
        len += ft_putnbr(d);
    }
    else if(*s == 'u')
    {
        unsigned int u = va_arg(ap, unsigned int);
        len += ft_putnbr_unsigned(u);
    }
    else if(*s == 'x' || *s == 'X')
    {
        unsigned int x = va_arg(ap , unsigned int);
        len += hex(x, *s);
    }
    else if(*s == '%')
        len += ft_putchar('%');
    else if(*s == 'p')
    {
        unsigned long p =(unsigned long)va_arg(ap, void *);
        len += ft_putstr("0x") + hex_p(p);
    }    
    else
        len += ft_putstr(s); 
    return (len);
}