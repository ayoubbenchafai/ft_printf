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