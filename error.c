/*
** EPITECH PROJECT, 2020
** B-PSU-200-MPL-2-1-mysokoban-trystan.lescoat
** File description:
** error.c
*/
#include "include/my.h"

void print_help(void)
{
    my_printf("USAGE\n");
    my_printf("    ./my_sokoban map\n\n");
    my_printf("DESCRIPTION\n");
    my_printf("    map file representing the warehouse map, containing ");
    my_printf("'#' for walls,\n");
    my_printf("        'P' for the player, 'X' for boxes and 'O'");
    my_printf("for for storage locations\n");
    exit(0);
}

int error(int argc, char **argv)
{
    struct stat s;
    char *buff;
    int o;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
        return (84);
    if (stat(argv[1], &s) == -1)
        return (84);
    if (S_ISREG(s.st_mode) ==  0)
        return (84);
    buff = malloc(sizeof(char) * (s.st_size + 1));
    if (buff == NULL)
        return (84);
    if (read(o, buff, s.st_size) == -1)
        return (84);
    return (0);
}