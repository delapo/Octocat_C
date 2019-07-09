/*
** ETNA PROJECT, 06/05/2019 by courco_a
** Octocat
** File description:
**      file to move the octocat
*/

#include "./octocat.h"

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
    if(my_strcmp(hardcore, "--hardcore") != 0) {
        move_octocat(buf, map, player);
    } else
        move_hard(buf, map, player);

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
    int x = player->x;
    int y = player->y;

    switch (direction) {
    case 'z' :
        player = check_possibilities(map, player, x, y - 1);
        break;
    case 'q' :
        player = check_possibilities(map, player, x - 1, y);
        break;
    case 's' :
        player = check_possibilities(map, player, x, y + 1);
        break;
    case 'd' :
        player = check_possibilities(map, player, x + 1, y);
        break;
    }
    if(player->win != 1) {
        print_map(map, player);
        play_again(map, player);
    }
}

List_t *check_possibilities(char **map, List_t *player, int x, int y)
{
    char tmp;

    if(map[y][x] != '\0' && map[y][x] != '#') {
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
