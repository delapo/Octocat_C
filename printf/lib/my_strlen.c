/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_printf
** File description:
**      printf but better
*/

#include "../my_printf.h"

int my_strlen(char *str) 
{
    int	i = 0;
    
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
