/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:19 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/21 22:05:10 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int c;
    int i;
    va_list ap;

    c = 0;
    i = 0;
    va_start(ap, s);

    if (write(1, "", 0) == -1)
        return -1;
    while(s[i])
    {
        if(s[i] == '%')
        {
            c += check_conversions(&s[i + 1], ap);
            i++;
        }
        else
            c += write(1,&s[i],1);
        i++;    
    }
    va_end(ap);
    return (c);
}


// #include <libc.h>
// int main()
// {
//     // close(1);
//     // int d = printf("%1023s", "g");
//     // fprintf(stderr, "%d\n", d);
//     // d = printf("io");
//     // fprintf(stderr, "%d\n", d);
//     // d = printf("%1022s", "g");
//     // fprintf(stderr, "%d\n", d);
//     // d = printf("%1021s", "g");
//     // fprintf(stderr, "%d\n", d);
//     ft_printf("");

// }
