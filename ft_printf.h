#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int     ft_printf(const char *s, ...);
int     ft_putchar(char c);
int     ft_putstr(const char *s);
int     nbr_digits(int n);
int     ft_putnbr_unsigned(unsigned int n);
int 	ft_putnbr(int n);
int     hex(unsigned int n, char c);
int     hex_p(unsigned long n);
int     check_conversions(const char *s, va_list ap);

#endif