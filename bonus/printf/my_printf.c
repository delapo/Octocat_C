/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** snake
** File description:
**      SNAKE
*/

#include "./my_printf.h"

static const wow_t tableau[] = {
        {'s', &my_putstr_print},
        {'c', &my_putchar_print},
        {'i', &my_putnbr_print},
        {'d', &my_putnbr_print},
        {'u', &my_putnbr_unsigned_print},
        {'o', &my_putnbr_base_print_octal},
        {'x', &my_putnbr_base_print_min},
        {'X', &my_putnbr_base_print_maj},
        {'%', &my_pourcent_print},
        {'\0', NULL},
    };

int my_printf(const char *string, ...)
{
    int i = 0;
    int length = 0;
    int j;
    va_list lst;
    
    va_start(lst, string);
    while (string[i] != '\0') {
        j = 0;
        if (string[i] == '%') {
            i++;
            while (tableau[j].argument != '\0')
                if (string[i] == tableau[j++].argument)
                    length += tableau[j - 1].fptr(lst);
        } else
            length += my_putchar(string[i]);
        i++;
    }
    va_end(lst);
    return length;
}

int my_pourcent_print(va_list lst)
{
    int n = va_arg(lst, int);
    
    n = 1;
    my_putchar('%');
    return n;
}
