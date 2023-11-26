/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:50:21 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/26 15:15:28 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversions(const char *s, va_list ap)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (*s == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*s == 'd' || *s == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (*s == 'u')
		len += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (*s == 'x')
		len += ft_hex(va_arg(ap, unsigned int), 'x');
	else if (*s == 'X')
		len += ft_hex(va_arg(ap, unsigned int), 'X');
	else if (*s == '%')
		len += ft_putchar('%');
	else if (*s == 'p')
		len += ft_putstr("0x") + ft_hex_p(va_arg(ap, unsigned long));
	else
		len += ft_putchar(*s);
	return (len);
}
