/*
** EPITECH PROJECT, 2026
** dds
** File description:
** dsds
*/

#include "../include/my.h"

void my_exit(char **array, list_t **head)
{
    if (!array)
        return;
    if (my_strcmp(array[0], "exit") == 0) {
        free_array(array);
        exit(0);
        //exit((*head)->last_exit);
    }
}

void manage_backcd(list_t **head, char **array)
{
    list_t *tmp0 = get_env_value(head, "PWD");
    list_t *tmp1 = get_env_value(head, "OLDPWD");

    if (array[1] == NULL)
        return;
    if (my_strcmp(array[1], "-") != 0)
        return;
    if (my_strcmp(tmp0->value, tmp1->value) == 0) {
        my_printf(": No such file or directory.\n");
        (*head)->last_exit = 1;
    }
    if (chdir(tmp1->value) == -1) {
        (*head)->last_exit = 1;
        return;
    }
    update_env(head, "PWD", tmp1->value);
    return;
}

list_t *get_env_value(list_t **head, char *variable)
{
    list_t *tmp = *head;

    if (!variable)
        return NULL;
    for (; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->variable, variable) == 0)
            break;
    if (!tmp)
        return NULL;
    return tmp;
}

void update_env(list_t **head, char *variable, char *value)
{
    list_t *tmp = get_env_value(head, variable);

    if (!tmp) {
        tmp = create_node(variable, value);
        tmp->next = *head;
        *head = tmp;
        return;
    }
    free(tmp->value);
    tmp->value = my_strdup(value);
}

void go_home(list_t **head, char **array)
{
    list_t *tmp = get_env_value(head, "HOME");
    int ac = get_ac(array);

    if (!tmp) {
        if (ac == 2) {
            write(2, "No $home variable set.\n", 23);
            (*head)->last_exit = 1;
        } else
            write(2, "No home directory.\n", 19);
        (*head)->last_exit = 1;
        return;
    }
    update_env(head, "PWD", tmp->value);
    chdir(tmp->value);
}
