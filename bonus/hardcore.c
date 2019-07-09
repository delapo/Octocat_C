/*
** ETNA PROJECT, 06/05/2019 by courco_a
** octocat
** File description:
**      mode hardcore
*/

#include <time.h>
#include "./octocat.h"

void move_hard(char *buf, char **map, List_t *player)
{
    int size = my_strlen(buf) - 1;
    
    for(int a = 0; a < size; a++) {
        delay(300);
        position_t p;

        p.x = player->x;
        p.y = player->y;
        p.a = a;
        if(switch_case(buf, p, player, map) == 1) {
            my_printf("\n You're Lost, and you've been eaten by a Grievers ! \n");
            my_read_win_lose("./src/lose");
            play_sound("lose");
            return;
        } else if(switch_case(buf, p, player, map) == 2) {
            my_printf("\nFinish, you've been eaten by a Grievers! \n");
            my_read_win_lose("./src/lose");
            play_sound("lose");
            return;
        } else
            print_map(map, player);
    }
}

int switch_case(char *buf, position_t p, List_t *player, char **map)
{
    switch (buf[p.a]) {
    case 'z' :
        player = check_hard(map, player, p.x, p.y - 1);
        break;
    case 'q' :
        player = check_hard(map, player, p.x - 1, p.y);
        break;
    case 's' :
        player = check_hard(map, player, p.x, p.y + 1);
        break;
    case 'd' :
        player = check_hard(map, player, p.x + 1, p.y);
        break;
    default:
        return 1;
        break;
    }
    if(player == NULL)
        return 2;
    else
        return 0;
}

List_t *check_hard(char **map, List_t *player, int x, int y)
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
            system("mpg123 --quiet ./src/audio/howdoyoufoundme.mp3");
        }
    } else {
        return NULL;
    }
    return player;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // String start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}
