/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_putnbr_base
** File description:
**      put a nbr with a base
*/

#include "../my_printf.h"

int my_putnbr_base(int nbr, char *base)
{
    int str_base = my_strlen(base);
    int length = 1;
    
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    } else if (nbr == 0) 
        return 1;
    else {
        length++;
        my_putnbr_base(nbr / str_base, base);
        my_putchar(base[nbr % str_base]);
    }
    return length;
}

int my_putnbr_base_print_min (va_list lst)
{
    int nbr = va_arg(lst, int);
    
    return (my_putnbr_base(nbr,"0123456789abcdef"));
}

int my_putnbr_base_print_maj (va_list lst)
{
    int nbr = va_arg(lst, int);
    
    return (my_putnbr_base(nbr,"0123456789ABCDEF"));
}

int my_putnbr_base_print_octal (va_list lst)
{
    int nbr = va_arg(lst, int);
    
    return (my_putnbr_base(nbr,"01234567"));
}
