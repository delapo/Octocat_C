/*
** ETNA PROJECT, 03/05/2019 by delapo_a
** octocat
** File description:
**      file for menu
*/

#include "./octocat.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int display_menu(char *argv)
{
    my_printf("\x1b[33m 1. PLAY \n 2.RULES \n 3. QUIT \x1b[0m \n");
    
    char buf[150];
    read(0, buf, sizeof(buf));
    my_printf("\e[1;1H\e[2J");
    choose_display_menu(buf, argv, "test");
    return 0;
}

int menu_hard(char *argv, char *hardcore)
{
    char buf[150];
    
    if(my_strcmp(hardcore, "--hardcore") == 0) {
    my_printf("\x1b[33m 1. PLAY \n 2.RULES \n 3. QUIT \x1b[0m \n");
    read(0, buf, sizeof(buf));
    my_printf("\e[1;1H\e[2J");
    choose_display_menu(buf, argv, hardcore);
    } else
        my_printf("ERROR, choose a valid option ([map] [--hardcore])");
    return 0;
}


int choose_display_menu(char *buf, char *argv, char *hardcore)
{
    switch(buf[0]) {
    case '1' :
        my_printf(" \x1b[33m YOU CHOOSE TO PLAY \x1b[0m \n");
        play(argv, hardcore);
        break;
    case '2' :
        my_read_for_rules(argv, hardcore);
        break;
    case '3' :
        my_printf(" \x1b[31m YOU QUIT THE GAME \x1b[0m \n");
        break;
    default:
        my_printf(" \x1b[32m It's not a choice \x1b[0m \n");
        break;
    }
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int x;
    
    x = 0;
    if (s1[0] == '\0') {
        s1 = "";
    } else if (s2[0] == '\0') {
        s2 = "";
    }
    while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x]) {
        x = x + 1;
    }
    if (s1[x] != s2[x]) {
        return (s1[x] - s2[x]);
    }
    return 0;
}
