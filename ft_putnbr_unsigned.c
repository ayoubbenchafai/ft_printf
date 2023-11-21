#include "ft_printf.h"

int 	ft_putnbr_unsigned(unsigned int n)
{
    int len;

    len = nbr_digits(n);
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
    return (len);
}