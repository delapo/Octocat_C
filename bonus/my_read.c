/*
** ETNA PROJECT, 08/05/2019 by delapo_a
** Octocat
** File description:
**      a modified read function
*/

#include "./octocat.h"

char *my_read(char *tab)
{
    int op;
    int ret;
    char buf[BUFFER_SIZE + 1];
    char *tmp = malloc(sizeof(char) * 1);
    
    op = open(tab, O_RDONLY);
    tmp[0] = '\0';
    while ((ret = read(op, buf, BUFFER_SIZE))) {
        buf[ret] = '\0';
        if (verify(buf) == 0)
            tmp = my_strcat(tmp, buf);
        else {
            my_printf("ERROR : Map format is not valid\n\n");
            return NULL;
        }
    }
    if ((count_char(tmp, 'P') == 1) && (count_char(tmp, 'X') == 1)) {
        my_putstr(tmp);
        return tmp;
    }
    return NULL;
}

char *my_read_win_lose(char *tab)
{
    int op;
    int ret;
    char buf[BUFFER_SIZE + 1];
    char *tmp = malloc(sizeof(char) * 1);
    
    op = open(tab, O_RDONLY);
    tmp[0] = '\0';
    while ((ret = read(op, buf, BUFFER_SIZE))) {
        buf[ret] = '\0';
        tmp = my_strcat(tmp, buf);
    }
    my_putstr(tmp);
    free(tmp);
    return tmp;
}

int my_read_for_rules(char *argv, char *hardcore)
{
    int op;
    int ret;
    char buf[BUFFER_SIZE + 1];
    char *tmp = malloc(sizeof(char*) * 1);
    
    op = open("./src/rules", O_RDONLY);
    tmp[0] = '\0';
    while ((ret = read(op, buf, BUFFER_SIZE))) {
        buf[ret] = '\0';
        tmp = my_strcat(tmp, buf);
    }
    my_printf("%s\n\n\n\n", tmp);
    if (my_strcmp(hardcore, "--hardcore") == 0)
        menu_hard(argv, hardcore);
    else
        display_menu(argv);
    return 0;
}

