/*
** EPITECH PROJECT, 2025
** Current project
** File description:
** Tek1 project at Epitech
*/

#include "../include/my.h"

int get_ac(char **array)
{
    int ac = 0;

    if (!array)
        return 0;
    for (; array[ac]; ac++);
    return ac;
}

int main(int ac, char **av, char **env)
{
    int return_value = 0;
    list_t *head = NULL;

    array_to_list(&head, env);
    shell_loop(ac, av, env, &head);
    return_value = head->last_exit;
    free_list(&head);
    return return_value;
}
