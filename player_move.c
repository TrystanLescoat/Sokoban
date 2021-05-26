/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** player_move.c
*/
#include "include/my.h"

void player_move(int c, char **array, pos_t *pos, char **copy_map)
{
    if (c == 65)
        player_up(array, pos);
    if (c == 66)
        player_down(array, pos);
    if (c == 67)
        player_right(array, pos);
    if (c == 68)
        player_left(array, pos);
    for (int i = 0; copy_map[i]; i++)
        for (int j = 0; copy_map[i][j]; j++)
            if (copy_map[i][j] == 'O' && array[i][j] == ' ')
                array[i][j] = 'O';
}

void player_up(char **array, pos_t *pos)
{
    if (array[pos->y - 1][pos->x] == '#')
        return;
    player_next_pos(array, pos, -1, 0);
}

void player_down(char **array, pos_t *pos)
{
    if (array[pos->y + 1][pos->x] == '#')
        return;
    player_next_pos(array, pos, 1, 0);
}

void player_right(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x + 1] == '#')
        return;
    player_next_pos(array, pos, 0, 1);
}

void player_left(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x - 1] == '#')
        return;
    player_next_pos(array, pos, 0, -1);
}