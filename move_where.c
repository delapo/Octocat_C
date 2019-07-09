/*
** ETNA PROJECT, 06/05/2019 by courco_a
** Octocat
** File description:
**      file to move the octocat
*/

#include "./octocat.h"

static const move_t tableau[] = {
    {'z', &check_possibilities, 0, -1},
    {'w', &check_possibilities, 0, -1},
    {'q', &check_possibilities, -1, 0},
    {'a', &check_possibilities, -1, 0},
    {'s', &check_possibilities, 0, 1},
    {'d', &check_possibilities, 1, 0},
    {'\0', NULL, 0, 0},
};

int play(char *argv, char *hardcore)
{
    char buf[150];
    char *str = my_read(argv);
    char **map;
    List_t *player;
    
    if (str == NULL)
        return 1;
    map = table_map_create(str);
    player = find_player(map);
    my_printf("\nSelect your way ! ");
    read(0, buf, sizeof(buf));
    if (my_strcmp(hardcore, "--hardcore") != 0)
        move_octocat(buf, map, player);
    else
        move_hard(buf, map, player); 
    make_free_map(map);
    free(player);
    free(str);
    return 0;
}

int play_again(char **map, List_t *player)
{
    char buf[150];
    
    my_printf("\nSelect your way ! ");
    read(0, buf, sizeof(buf));
    move_octocat(buf, map, player);
    return 0;
}

void move_octocat(char *buf, char **map, List_t *player)
{
    char direction = buf[0];
    int newX;
    int newY;
    
    for (int j = 0; tableau[j].argument != '\0'; j++) {
        if (direction == tableau[j].argument) {
            newX = player->x + tableau[j].x;
            newY = player->y + tableau[j].y;
            player = tableau[j].fptdr(map, player, newX, newY);
        }
    }
    if (player->win != 1) {
        print_map(map, player);
        if (player->wall == 1) {
            my_printf("\n\n !! You can't leave the map !!\n\n");
            player->wall = 0;
        }
        play_again(map, player);
    }
}

List_t *check_possibilities(char **map, List_t *player, int x, int y)
{
    char tmp;
    
    if (map[y][x] == '\0' || map[y][x] == '\n')
        player->wall = 1;
    else if (map[y][x] != '#') {
        map[player->y][player->x] = ' ';
        player->y = y;
        player->x = x;
        tmp = map[player->y][player->x];
        map[player->y][player->x] = 'P';
        if (tmp == 'X') {
            print_map(map, player);
            my_printf("\n\n");
            my_read_win_lose("./src/win");
            my_printf("\n\n");
            player->win = 1;
        }
    }
    return player;
}
