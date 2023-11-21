/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:29:51 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:52 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int hex_p(unsigned long n)
{
    int len;
    char *str;

    len  = 0;
    str = "0123456789abcdef";
    if(n >= 16)
    {
        len += hex_p(n/16);
        len += hex_p(n % 16);  
    }
    else 
        len += write(1, &str[n % 16], 1);
    return (len);    
}