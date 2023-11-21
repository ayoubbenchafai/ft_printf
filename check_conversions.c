/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:25 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/21 21:30:26 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    else if(*s == 'x')
    {
        unsigned int x = va_arg(ap , unsigned int);
        len += hex(x, 'x');
    }
    else if(*s == 'X')
    {
        unsigned int X = va_arg(ap , unsigned int);
        len += hex(X, 'X');
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