/*
** ETNA PROJECT, 06/05/2019 by courco_a
** Octocat
** File description:
**      file to move the octocat
*/

#include "./octocat.h"

int play(char *argv, char *hardcore)
{
    char *str = my_read(argv);
    char **map;
    List_t *player;

    if (str == NULL)
        return 1;
    map = table_map_create(str);
    player = find_player(map);
    if(my_strcmp(hardcore, "--hardcore") != 0) {
        print_window(map, (my_strlen(str) / count_char(str, '\n')),(count_char(str, '\n')), player, 0);
    } else
        print_window(map, (my_strlen(str) / count_char(str, '\n')),(count_char(str, '\n')), player, 1);

    return 0;
}

char **move_octocat(SDL_Event event, char **map, List_t *player, SDL_Renderer *renderer)
{
    int x = player->x;
    int y = player->y;
    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN ) {
            switch (event.key.keysym.sym) {
                case SDLK_UP : player = check_possibilities(map, player, x, y - 1, renderer);
                    break;
                case SDLK_LEFT : player = check_possibilities(map, player, x - 1, y, renderer);
                    break;
                case SDLK_DOWN : player = check_possibilities(map, player, x, y + 1, renderer);
                    break;
                case SDLK_RIGHT : player = check_possibilities(map, player, x + 1, y, renderer);
                    break;
            }
        }
        else if(event.type == SDL_QUIT)
            exit(0);
    }
    return map;
}

List_t *check_possibilities(char **map, List_t *player, int x, int y, SDL_Renderer *renderer)
{
    char tmp;

    if(map[y][x] != '\0' && map[y][x] != '#') {
        map[player->y][player->x] = ' ';
        player->y = y;
        player->x = x;
        tmp = map[player->y][player->x];
        map[player->y][player->x] = 'P';
        if (tmp == 'X') {
            print_map(map, player, renderer);
            my_read_win_lose("./src/win");
            player->win = 1;
        }
    }
    return player;
}
