/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** check_map.c
*/

#include "include/my.h"

void count(char c, int *count_p, int *count_o, int *count_x)
{
    if (c != '#' && c != 'P' && c != 'O' && c != 'X' && c != '\n' && c != ' ')
        exit(84);
    if (c == 'P')
        (*count_p) += 1;
    if (c == 'O')
        (*count_o) += 1;
    if (c == 'X')
        (*count_x) += 1;
}

void check_map(char **array)
{
    int count_p = 0;
    int count_o = 0;
    int count_x = 0;

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            count(array[i][j], &count_p, &count_o, &count_x);
    if (count_p != 1)
        exit(84);
    if (count_o != count_x)
        exit(84);
    return;
}