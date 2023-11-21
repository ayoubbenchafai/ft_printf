/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:29:56 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:57 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_putstr(const char *s)
{
    int i;
    i = 0;
    if (!s)
    {
        i += write(1,"(null)",6);
        return (i);
    }
    while(*s)
    {
        write(1, s++, 1);
        i++;
    }
    return (i);
}