/*
** ETNA PROJECT, 06/05/2019 by delapo_a
** my_strcat
** File description:
**      put a string into a string
*/

#include "../my_printf.h"

char *my_strcat(char *dest, char *src)
{
   int x = 0;
   int dest_len = my_strlen(dest);
   char* tmp = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1));
   my_strcpy(tmp, dest);
   while (src[x] != '\0') {
       tmp[x + dest_len] = src[x];
       x = x + 1;
   }
   tmp[x + dest_len] = '\0';
   return tmp;
}
