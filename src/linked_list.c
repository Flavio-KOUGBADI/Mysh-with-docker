/*
** EPITECH PROJECT, 2026
** linked list
** File description:
** s
*/

#include "../include/my.h"

list_t *create_node(char *variable, char *value)
{
    list_t *tmp = malloc(sizeof(list_t));

    if (!tmp) {
        return NULL;
        errno = -5;
    }
    tmp->variable = my_strdup(variable);
    tmp->value = my_strdup(value);
    tmp->last_exit = 0;
    tmp->next = NULL;
    return tmp;
}

void add(list_t **head, char *variable, char *value)
{
    list_t *tmp = create_node(variable, value);

    if (!tmp)
        return;
    tmp->next = *head;
    *head = tmp;
}

void array_to_list(list_t **head, char **env)
{
    char *var = NULL;
    char *value = NULL;
    char *copy = NULL;

    for (int i = 0; env[i]; i++) {
        copy = my_strdup(env[i]);
        var = strtok(copy, "=");
        value = strtok(NULL, "=");
        add(head, var, value);
        free(copy);
    }
}

void disp(list_t **head)
{
    list_t *tmp = *head;

    for (; tmp != NULL; tmp = tmp->next)
        my_printf("%s=%s\n", tmp->variable, tmp->value);
}

void free_list(list_t **head)
{
    list_t *tmp = *head;
    list_t *previous;

    while (tmp != NULL) {
        previous = tmp;
        tmp = tmp->next;
        if (previous->variable)
            free(previous->variable);
        if (previous->value)
            free(previous->value);
        free(previous);
    }
}
