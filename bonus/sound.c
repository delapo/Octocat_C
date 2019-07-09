/*
** ETNA PROJECT, 08/05/2019 by delapo_a
** octocat
** File description:
**      read audio file to octocat
*/

#include "./octocat.h"

char *random_select(int r);

void play_sound(char *file_to_play)
{
    srand(time(NULL));
    if (my_strcmp(file_to_play, "lose") == 0)
        play_lose();
}

void play_lose()
{
    int r = rand()%99 + 1;
    char *str2 = malloc(sizeof(char*) * 2);
    
    str2 = random_select(r);
    char *str = my_strcat(my_strcat("mpg123 --quiet ./src/audio/lose", str2), ".mp3"); 
    system(str);
}

char *random_select(int r)
{
    char *str = malloc(sizeof(char*) * 2);
    
    if (r >= 1 && r < 10) {
        str = "2";
    }
    else if (r >= 10 && r < 50) {
        str = "1";
    }
    else {
        str = "3";
    }   
    return str;
}
