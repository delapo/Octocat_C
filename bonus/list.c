/*
** ETNA PROJECT, 06/05/2019 by courco_a
** octocat
** File description:
**      structure
*/

#include "./octocat.h"

List_t *init()
{
    List_t *list = malloc(sizeof(*list));

    if (list == NULL)
        exit(EXIT_FAILURE);

    list->x = 0;
    list->y = 0;
    list->win = 0;
    return list;
}

List_t *find_player(char **map)
{
    List_t *player;
    player = init();

    for(int y = 0; map[y][0] != '\0'; y++) {
        for(int x = 0; map[y][x] != '\0'; x++) {
            if(map[y][x] == 'P') {
                player->x = x;
                player->y = y;
                break;
            }
        }
    }
    return player;
}
