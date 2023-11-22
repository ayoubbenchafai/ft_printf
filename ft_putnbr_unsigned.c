/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:09:01 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/22 22:10:17 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

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
