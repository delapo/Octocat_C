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
                if (map[y][x] == 'P') {
                    my_printf("\033[33m%c", map[y][x], "\033[0m");
                } else if (map[y][x] == 'X') {
                    my_printf("\033[31m%c", map[y][x], "\033[0m");
                } else {
                    if(map[y][x] == '#')
                        my_printf("\033[46;36m%c", map[y][x], "\033[0m");
                    else
                        my_printf("%c", map[y][x]);
                    my_printf("\033[0m");
                }
            }
        }
    }
    return;
}
