/*
** ETNA PROJECT, 26/09/2018 by delapo_a
** my_strlen
** File description:
**      exo 2
*/

#include "../my_printf.h"

int my_putstr(char *str) 
{
    int i;
    int length = 1;
    
    for (i = 0; str[i] != '\0'; i++) {
        length = length + 1;
        my_putchar(str[i]);
    }
    return length;
}

int my_putstr_print(va_list lst)
{
    char *str = va_arg(lst, char *);

    return (my_putstr(str));
}
