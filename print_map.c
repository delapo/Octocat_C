/*
** ETNA PROJECT, 06/05/2019 by courco_a
** Octocat
** File description:
**      print a map
*/

#include "./octocat.h"

void print_map(char **map, List_t *player)
{
    if (player->win != 1) {
        my_printf("\e[1;1H\e[2J");
        for (int y = 0; map[y][0] != '\0'; y++) {
            my_printf("\n");
            for (int x = 0; map[y][x] != '\0'; x++) {
                my_printf("%c", map[y][x]);
            }
        }
    }
    return;
}
