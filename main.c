/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** main.c
*/
#include "include/my.h"

int x_on_o(char **array, char **copy_map, int i)
{
    for (int j = 0; array[i][j]; j++)
        if (copy_map[i][j] == 'O' && array[i][j] != 'X')
            return (1);
    return (0);
}

void int_list_push_back(point_t **list, int x, int y)
{
    point_t *p = malloc(sizeof(point_t));
    point_t *a;

    p->x = x;
    p->y = y;
    p->next = NULL;
    if (*list == NULL)
        *list = p;
    else {
        for (a = *list; a->next != NULL; a = a->next);
        a->next = p;
    }
}

void search_pos_player(char **array, int i, pos_t *pos, point_t *point)
{
    point->next = NULL;
    for (int j = 0; array[i][j]; j++) {
        if (array[i][j] == 'P') {
            pos->x = j;
            pos->y = i;
        }
        if (array[i][j] == 'O') {
            point->x = j;
            point->y = i;
            int_list_push_back(&point, j, i);
        }
    }
}

int main(int argc, char **argv)
{
    char **array;
    char **copy_map;
    pos_t pos;
    point_t point;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        print_help();
    if (error(argc, argv) == 84)
        return (84);
    array = read_map(argv[1]);
    check_map(array);
    copy_map = read_map(argv[1]);
    for (int i = 0; array[i]; i++)
        search_pos_player(array, i, &pos, &point);
    initscr();
    noecho();
    curs_set(FALSE);
    my_popup(array, pos, &point, copy_map);
    return (0);
}