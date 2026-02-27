/*
** EPITECH PROJECT, 2026
** ssd
** File description:
** dsds
*/

#include "../include/my.h"

char *which_var(char *str)
{
    char *dest = malloc(sizeof(char) * my_strlen(str));
    int k = 0;

    for (int i = 1; str[i]; i++) {
        dest[k] = str[i];
        k++;
    }
    dest[k] = '\0';
    return dest;
}

void print_exit(list_t **head, char **array)
{
    int ac = get_ac(array);
    char *tofind = NULL;
    list_t *tmp = NULL;

    if (ac != 2 || my_strcmp(array[0], "echo") != 0)
        return;
    if (my_strcmp(array[1], "$?") == 0) {
        my_printf("%d\n", (*head)->last_exit);
        return;
    }
    if (array[1][0] == '$' && array[1][1] != '?') {
        print_env_var(head, array);
        return;
    }
}

void print_env_var(list_t **head, char **array)
{
    int ac = get_ac(array);
    list_t *tmp = NULL;
    char *tofind = NULL;

    tofind = which_var(array[1]);
    tmp = get_env_value(head, tofind);
    if (!tmp) {
        write(2, tofind, my_strlen(tofind));
        write(2, ": Undefined variable.\n", 22);
        free(tofind);
        return;
    }
    my_printf("%s\n", tmp->value);
    free(tofind);
}
