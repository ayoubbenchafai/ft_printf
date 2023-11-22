/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:03:29 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/22 22:07:22 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		c;
	int		i;
	va_list	ap;

	c = 0;
	i = 0;
	va_start(ap, s);
	if (write(1, "", 0) == -1)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			c += ft_check_conversions(&s[i + 1], ap);
			i++;
		}
		else
			c += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (c);
}
