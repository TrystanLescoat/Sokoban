/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** defeat_condition.c
*/
#include "include/my.h"

int wall_side(char **map, int i, int j, int nb_wall)
{
    if (map[i + 1][j] == 'X' || map[i + 1][j] == '#') {
        if (map[i][j + 1] == 'X' || map[i][j + 1] == '#')
            return (84);
        if (map[i][j - 1] == 'X' || map[i][j - 1] == '#')
            return (84);
    }
    if (map[i - 1][j] == 'X' || map[i - 1][j] == '#') {
        if (map[i][j + 1] == 'X' || map[i][j + 1] == '#')
            return (84);
        if (map[i][j - 1] == 'X' || map[i][j - 1] == '#')
            return (84);
    }
    return (0);
}

int search_wall_side(char **map, int i, int nb_wall)
{
    int count_s = 0;
    int count_f = 0;

    for (int j = 0; map[i][j]; j++) {
        nb_wall = 0;
        if (map[i][j] == 'X' && wall_side(map, i, j, nb_wall) == 84)
            return (84);
    }
    return (0);
}

int box_cannot_move(char **map)
{
    int nb_wall = 0;

    for (int i = 0; map[i]; i++)
        if (search_wall_side(map, i, nb_wall) == 84)
            return (84);
    return (0);
}