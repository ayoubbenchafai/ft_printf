/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:07 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/21 21:30:08 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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