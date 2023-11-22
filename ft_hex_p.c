/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:56:01 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/22 21:58:17 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_p(unsigned long n)
{
	int		len;
	char	*str;

	len = 0;
	str = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_hex_p(n / 16);
		len += ft_hex_p(n % 16);
	}
	else
		len += write(1, &str[n % 16], 1);
	return (len);
}
