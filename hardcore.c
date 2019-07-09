/*
** ETNA PROJECT, 06/05/2019 by courco_a
** octocat
** File description:
**      mode hardcore
*/

#include "./octocat.h"

static const move_t tableau_hard[] = {
    {'z', &check_hard, 0, -1},
    {'w', &check_hard, 0, -1},
    {'q', &check_hard, -1, 0},
    {'a', &check_hard, -1, 0},
    {'s', &check_hard, 0, 1},
    {'d', &check_hard, 1, 0},
    {'\0', NULL, 0, 0},
};

void move_hard(char *buf, char **map, List_t *player)
{
    int size = my_strlen(buf) - 1;
    position_t p;
    
    for (int a = 0; a < size; a++) {
        p.x = player->x;
        p.y = player->y;
        p.a = a;
        if (switch_case(buf, p, player, map) == 1) {
            my_printf("\n You're Lost, and you've");
            my_printf(" been eaten by a Grievers ! \n");
            my_read_win_lose("./src/lose");
            return;
        } else if (switch_case(buf, p, player, map) == 2 && player->win != 1) {
            my_printf("\nFinish, you've been eaten by a Grievers! \n");
            my_read_win_lose("./src/lose");
            return;
        } else
            print_map(map, player);
    }
}

int switch_case(char *buf, position_t p, List_t *player, char **map)
{
    int newX;
    int newY;
    int lost = 0;
    
    for (int j = 0; tableau_hard[j].argument != '\0'; j++) {
        if (buf[p.a] == tableau_hard[j].argument) {
            newX = p.x + tableau_hard[j].x;
            newY = p.y + tableau_hard[j].y;
            player = tableau_hard[j].fptdr(map, player, newX, newY);
            lost = 1;
        }
    }
    if (player == NULL)
        return 2;
    else if (lost != 1)
        return 1;
    else
        return 0;
}

List_t *check_hard(char **map, List_t *player, int x, int y)
{
    char tmp;
    
    if (map[y][x] != '\0' && map[y][x] != '#') {
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
    } else {
        return NULL;
    }
    return player;
}
