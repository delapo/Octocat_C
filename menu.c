/*
** ETNA PROJECT, 03/05/2019 by delapo_a
** octocat
** File description:
**      file for menu
*/

#include "./octocat.h"

int display_menu(char *argv)
{
    char buf[150];
    
    my_printf(" 1. PLAY \n 2. QUIT \n");
    read(0, buf, sizeof(buf));
    my_printf("\e[1;1H\e[2J");
    choose_display_menu(buf, argv, "test");
    return 0;
}

int menu_hard(char *argv, char *hardcore)
{
    char buf[150];
    
    if (my_strcmp(hardcore, "--hardcore") == 0) {
        my_printf(" 1. PLAY \n 2. QUIT \n");
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
        my_printf("YOU CHOOSE TO PLAY \n");
        play(argv, hardcore);
        break;
    case '2' :
        my_printf("YOU QUIT THE GAME \n");
        break;
    default:
        my_printf("It's not a choice \n");
        break;
    }
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int x = 0;
    
    if (s1[0] == '\0')
        s1 = "";
    else if (s2[0] == '\0')
        s2 = "";
    while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x]) {
        x = x + 1;
    }
    if (s1[x] != s2[x])
        return (s1[x] - s2[x]);
    return 0;
}
