/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:58:41 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/22 22:00:55 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char c)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'X')
		str = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_hex(n / 16, c);
		len += ft_hex(n % 16, c);
	}
	else
		len += write(1, &str[n % 16], 1);
	return (len);
}
