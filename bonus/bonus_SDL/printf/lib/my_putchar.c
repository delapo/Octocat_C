/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_printf
** File description:
**      printf but better
*/

#include "../my_printf.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putchar_print(va_list lst)
{
    char c = va_arg(lst, int);
    
    return (my_putchar(c));
}
