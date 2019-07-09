/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_printf
** File description:
**      printf but better
*/

#include "../my_printf.h"

int my_putnbr_unsigned(unsigned int n)
{
    int length = 1;
    
    if (n > 9) {
        length += my_putnbr_unsigned(n / 10);
        my_putnbr_unsigned(n % 10);
    } else
        my_putchar(n+'0');
    return length;
}

int my_putnbr_unsigned_print(va_list lst)
{
    unsigned int n = va_arg(lst, unsigned int);
    
    return (my_putnbr_unsigned(n));
}
