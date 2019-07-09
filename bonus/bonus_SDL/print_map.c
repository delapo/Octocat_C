/*
** ETNA PROJECT, 06/05/2019 by courco_a
** Octocat
** File description:
**      print a map
*/

#include "./octocat.h"

static const move_t tableau_hard[] = {
    {'P', &set_rect_renderer, 0, 0, 255, 255},
    {'X', &set_rect_renderer, 255, 0, 0, 255},
    {'#', &set_rect_renderer, 0, 0 ,0, 0},
    {' ', &set_rect_renderer, 255, 255 ,0, 0},
    {'\n', &set_rect_renderer, 0, 0 ,0, 0},
    {'\0', NULL, 0, 0, 0, 0},
};

SDL_Rect set_rect_renderer(SDL_Rect r, int pos[2], SDL_Renderer *renderer, color_t *color)
{
    r = return_square(r, pos[0], pos[1]);
    SDL_SetRenderDrawColor( renderer, color->a, color->b, color->c, color->d );
    SDL_RenderFillRect( renderer, &r );

    return r;
}

color_t init_color(int a, int b, int c, int d)
{
    color_t color = {a, b, c, d};

    color.a = a;
    color.b = b;
    color.c = c;
    color.d = d;

    return color;
}

void print_map(char **map, List_t *player, SDL_Renderer *renderer)
{
    SDL_Rect r;
    int pos[2];
    color_t color;
    int x = 0;
    if (player->win != 1) {
        for (int y = 0; map[y][0] != '\0'; y++) {
            for (x = 0; map[y][x] != '\0'; x++) {
                pos[0] = x;
                pos[1] = y;
                for (int j = 0; tableau_hard[j].argument != '\0'; j++) {
                    if (map[y][x] == tableau_hard[j].argument) {
                            color = init_color(tableau_hard[j].r, tableau_hard[j].g, tableau_hard[j].b, tableau_hard[j].a);
                            r = tableau_hard[j].fptdr(r, pos, renderer, &color);
                        }
                }
            }
        }
    }
}

void print_window(char **table, int width, int height, List_t *player, int hardcore)
{
    my_printf("c\n");

    SDL_Window* win = SDL_CreateWindow("Octocat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width * 20, height * 20, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    play_sound_SDL();

    while(player->win != 1) {
        //if (played == 0)
        //    play_sound_SDL();
        print_map(table, player, renderer);
        SDL_Event event;
        if (hardcore) {
            table = move_octocat(event, table, player, renderer);
        } else
            table = move_octocat(event, table, player, renderer);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

}

SDL_Rect return_square(SDL_Rect r, int x, int y)
{
    r.x = x * 20;
    r.y = y * 20;
    r.w = 20;
    r.h = 20; 
    return r;   
}