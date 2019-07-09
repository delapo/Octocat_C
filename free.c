/*
** ETNA PROJECT, 06/05/2019 by courco_a
** octocat
** File description:
**      free
*/

#include "./octocat.h"

void make_free_map(char **map)
{
    int y = 0;
    
    for (y = 0; map[y][0] != '\0'; y++) {
        free(map[y]);
    }
    free(map[y]);
    free(map[++y]);
    free(map);
}
