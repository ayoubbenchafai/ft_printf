/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:11:39 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/22 22:13:24 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	int	min_value;

	len = ft_nbr_digits(n);
	min_value = -2147483648;
	if (n == min_value)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n *= (-1);
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len);
}
