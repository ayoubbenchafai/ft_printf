#include "libftprintf.h"

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(const char *s)
{
    int i;
    i = 0;
    if (!s)
    {
        i += write(1,"(null)",6);
        return (i);
    }
    while(*s)
    {
        write(1, s++, 1);
        i++;
    }
    return (i);
}

int 	ft_putnbr(int n)
{
    int len;
	int	min_value;

    len = 0;
	min_value = -2147483648 ;
	if (n == min_value)
		len += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n *= (-1);
		len += ft_putchar('-');
		len += ft_putnbr(n);
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
    return (len);
}

int hex(int n, char c)
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
        len += ft_putnbr(u);
    }
    else if(*s == 'x' || *s == 'X')
    {
        char c = *s;
        int x = va_arg(ap , unsigned int);
        len += hex(x,c);
    }
    else if(*s == '%')
        len += ft_putchar('%');
    return (len);
}



int ft_printf(const char *s, ...)
{
    int c;
    int i;
    va_list ap;

    c = 0;
    i = 0;
    va_start(ap, s);

    while(s[i])
    {
        if(s[i] == '%')
        {
            c += check_conversions(&s[i + 1], ap);
            i++;
        }
        else
            c += write(1,&s[i],1);
        i++;    
    }

    va_end(ap);
    return (c);
}

#include <stdio.h>

int main() 
{
    //int a = ft_printf("my age:%r");
    //int a = printf("\n len  = %u",-15);
    int a = ft_printf("result : %x",16);
    printf("\na = %d",a);

    return 0;
}
