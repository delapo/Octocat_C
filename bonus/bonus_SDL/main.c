/*
** ETNA PROJECT, 03/05/2019 by courco_a
** octocat
** File description:
**      main function
*/

#include "./octocat.h"

int main(int argc, char **argv)
{
    if (argc == 2) { 
        display_menu(argv[1]);
    } else if(argc == 3) {
        menu_hard(argv[1], argv[2]);
    } else 
        my_printf("\nERROR : not enough arguments \nThe format is ./octocat [path_to_map] [--hardcore(optional)]\n\n");
    return 0;
}
