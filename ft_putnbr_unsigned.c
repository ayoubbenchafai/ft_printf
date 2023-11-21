#include "ft_printf.h"

int 	ft_putnbr_unsigned(unsigned int n)
{
    int len;

    len = 0;
	if (n > 9)
	{
		len += ft_putnbr_unsigned(n / 10);
		len += ft_putnbr_unsigned(n % 10);
	}
	else
		len += ft_putchar(n + '0');
    return (len);
}