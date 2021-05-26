/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** my_popup.c
*/

#include "include/my.h"

char **read_map(char const *str)
{
    struct stat s;
    int x;
    char *buff;
    int a;
    char **array;

    a = open(str, O_RDONLY);
    stat(str, &s);
    x = s.st_size;
    buff = malloc(sizeof(char) * (x + 1));
    read(a, buff, x);
    buff[x] = '\0';
    array = my_str_to_word_array(buff, "\n");
    return (array);
}

void change_i_max_and_x(char **array, int max_x, int *x, int *i_max)
{
    for (int i = 0; array[i]; i++) {
        if (max_x / 2 - my_strlen(array[i]) / 2 > (*x))
            (*x) = max_x / 2 - my_strlen(array[i]) / 2;
        (*i_max)++;
    }
}

void body_my_popup(int max_y, int max_x, char **array)
{
    int x = 0;
    int i_max = 0;

    getmaxyx(stdscr, max_y, max_x);
    change_i_max_and_x(array, max_x, &x, &i_max);
    i_max = max_y / 2 - i_max / 2;
    for (int i = 0; array[i]; i++, i_max++)
        mvprintw(i_max, x, array[i]);
}

void my_popup(char **array, pos_t pos, point_t *point, char **copy_map)
{
    int x = 0;
    int max_y = 0;
    int max_x = 0;
    int c;
    int i_max = 0;

    while (1) {
        body_my_popup(max_y, max_x, array);
        is_finish_win(max_y, max_x, array, copy_map);
        is_finish_lose(max_y, max_x, array);
        c = getch();
        player_move(c, array, &pos, copy_map);
        refresh();
        clear();
    }
}