/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** win_lose_conditions.c
*/
#include "include/my.h"

void is_finish_win(int max_y, int max_x, char **array, char **copy_map)
{
    for (int i = 0; array[i]; i++)
        if (x_on_o(array, copy_map, i) == 1)
            return;
    body_my_popup(max_y, max_x, array);
    refresh();
    clear();
    endwin();
    exit(0);
}

int for_is_finish_lose(char **array, int i)
{
    for (int j = 0; array[i][j]; j++) {
        if (array[i][j] == 'X' && wall_side(array, i, j, 0) != 84)
            return (0);
    }
    return (1);
}

void is_finish_lose(int max_y, int max_x, char **array)
{
    for (int i = 0; array[i]; i++)
        if (for_is_finish_lose(array, i) == 0)
            return;
    body_my_popup(max_y, max_x, array);
    refresh();
    clear();
    endwin();
    exit(1);
}