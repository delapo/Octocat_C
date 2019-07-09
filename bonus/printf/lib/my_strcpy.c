/*
** ETNA PROJECT, 06/05/2019 by delapo_a
** my_strcpy
** File description:
**      copy a string
*/

#include "../my_printf.h"

char *my_strcpy(char *dest, char *src)
{
   int x = 0;
   while (src[x] != '\0') {
       dest[x] = src[x];
       x = x + 1;
   }
   dest[x] = '\0';
   return dest;
}
