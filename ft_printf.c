#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int c;
    int i;
    va_list ap;

    c = 0;
    i = 0;
    va_start(ap, s);
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
//     ft_printf("%d\n",231);
// }
