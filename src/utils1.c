/*
** EPITECH PROJECT, 2026
** sd
** File description:
** sd
*/

#include "../include/my.h"

int minicheck(char **array, list_t **head)
{
    int is_present = 0;

    if ((array[1][0] >= 0 && array[1][0] <= 64) ||
        (array[1][0] >= 91 && array[1][0] <= 96) ||
        (array[1][0] >= 123 && array[1][0] <= 127))
        is_present = 1;
    if (array[1][0] == '_')
        is_present = 0;
    if (is_present == 1) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        (*head)->last_exit = 1;
        return 84;
    }
    return 0;
}

int big_check(char **array, list_t **head)
{
    int is_present = 0;

    for (int i = 1; array[1][i]; i++) {
        if ((array[1][i] >= 0 && array[1][i] <= 64) ||
            (array[1][i] >= 91 && array[1][i] <= 96) ||
            (array[1][i] >= 123 && array[1][i] <= 127)) {
            is_present = 1;
            return is_present;
        }
    }
    return 0;
}
