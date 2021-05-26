/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** player_movement.c
*/
#include "include/my.h"

void player_next_pos(char **array, pos_t *pos, int y, int x)
{
    array[pos->y][pos->x] = ' ';
    pos->x += x;
    pos->y += y;
    if (array[pos->y][pos->x] == 'X') {
        if (array[pos->y + y][pos->x + x] == '#') {
            pos->x -= x;
            pos->y -= y;
        }
        else if (array[pos->y + y][pos->x + x] == 'X') {
            pos->x -= x;
            pos->y -= y;
        }
        array[pos->y + y][pos->x + x] = 'X';
    }
    array[pos->y][pos->x] = 'P';
}