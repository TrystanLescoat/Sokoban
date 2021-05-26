/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** box_movement.c
*/
#include "include/my.h"

void next_pos_is_x_down(char **array, pos_t pos)
{
    if (array[pos.y + 1][pos.x] == '#')
        pos.y -= 1;
    array[pos.y][pos.x] = 'P';
    array[pos.y + 1][pos.x] = 'X';
}

void next_pos_is_x_up(char **array, pos_t pos)
{
    if (array[pos.y - 1][pos.x] == '#')
        pos.y += 1;
    array[pos.y][pos.x] = 'P';
    array[pos.y - 1][pos.x] = 'X';
}

void next_pos_is_x_right(char **array, pos_t pos)
{
    if (array[pos.y][pos.x + 1] == '#')
        pos.x -= 1;
    array[pos.y][pos.x] = 'P';
    array[pos.y][pos.x + 1] = 'X';
}

void next_pos_is_x_left(char **array, pos_t pos)
{
    if (array[pos.y][pos.x - 1] == '#')
        pos.x += 1;
    array[pos.y][pos.x] = 'P';
    array[pos.y][pos.x - 1] = 'X';
}