/*
** EPITECH PROJECT, 2020
** my_minishell
** File description:
** myls.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int sep_cmp(const char *str, int i, const char *sep)
{
    for (int j = 0; sep[j]; j++){
        if (str[i] == sep[j])
            return (1);
    }
    return (0);
}