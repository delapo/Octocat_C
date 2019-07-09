/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_printf
** File description:
**      printf but better
*/

#include "../my_printf.h"

int my_putnbr(int n)
{
    int length = 1;
    
    if (n < 0 && n > -2147483647) {
        n = -n;
        my_putchar('-');
    } else if (n > 9) {
        length++;
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    } else 
        my_putchar(n + '0');
    return length;
}

int my_putnbr_print(va_list lst)
{
    int n = va_arg(lst, int);
    
    return (my_putnbr(n));
}
