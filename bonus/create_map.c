/*
** ETNA PROJECT, 06/05/2019 by delapo_a
** Octocat
** File description:
**      create the map
*/

#include "./octocat.h"

char **table_map_create(char *buf) 
{
    char **tableau = malloc(sizeof(char*) * (count_char(buf, '\n') + 1));
    int y = 0;
    int x = 0;
    
    tableau[0] = malloc(sizeof(char) * (my_strlen(buf) / count_char(buf, '\n')));
    for (int z = 0; buf[z] != '\0'; z++) {
        if (buf[z] != '\n')
            tableau[y][x++] = buf[z];
        else {
            tableau[y][x] = '\0';
            tableau[++y] = malloc(sizeof(char) * (my_strlen(buf) / count_char(buf, '\n')));
            x = 0;
        }
    }
   tableau[++y] = malloc(sizeof(char));
   tableau[y][0] = '\0';
   return tableau;
}


int verify(char *buf)
{
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (buf[i] != '#' && buf[i] != 'X' && buf[i] != 'P')
            if (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\0')
                return 1;
    }
    return 0;
}

int count_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}
