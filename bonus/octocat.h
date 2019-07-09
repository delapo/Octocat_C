/*
** ETNA PROJECT, 03/05/2019 by courco_a
** octocat
** File description:
**      the .h file
*/

#ifndef __OCTOCAT__
#define __OCTOCAT__

#include "printf/my_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

typedef struct List_s {
    int x;
    int y;
    int win;
} List_t;

typedef struct position_s {
    int x;
    int y;
    int a;
} position_t;

int main(int argc, char **argv);
int display_menu(char* argv);
int choose_display_menu(char *buf, char* argv, char *hardcore);
int play_again(char** map, List_t* player);
int my_read_for_rules(char *argv, char *hardcore);
int play(char* argv, char *hardcore);
int play_hard(char *buf);
int menu_hard(char *argv, char *hardcore);
int my_strcmp(char *s1, char *s2);
int switch_case(char *buf, position_t p, List_t *player, char **map);
int verify(char *buf);
int count_char(char *str, char c);
char* my_read(char *tab);
char* my_read_win_lose(char *tab);
char** table_map_create(char *buf);
char** game(char** map);
char** move_up(char** map);
char** move_left(char** map);
char** move_down(char** map);
char** move_right(char** map);
void print_map(char** map, List_t *player);
void move_octocat(char *buf, char** map, List_t* player);
void move_hard(char *buf, char** map, List_t* player);
void delay(int number_of_seconds);
void play_sound(char *file_to_play);
void play_lose();
List_t* init();
List_t* find_player(char** map);
List_t* check_possibilities(char** map, List_t* player, int x, int y);
List_t* check_hard(char** map, List_t* player, int x, int y);

#endif
