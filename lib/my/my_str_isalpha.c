/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** ah
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i]; i++)
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
            return (0);
    return (1);
}
