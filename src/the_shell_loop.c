/*
** EPITECH PROJECT, 2026
** the shell loop funct
** File description:
** d
*/

#include "../include/my.h"

void my_handle_signals(int sig)
{
    my_printf("\n");
    return;
}

char **get_commands(void)
{
    char *line = NULL;
    size_t len = 0;
    char **array = NULL;
    int ret = getline(&line, &len, stdin);

    if (ret == -1)
        exit(0);
    len = my_strlen(line) - 1;
    line[len] = '\0';
    array = clean_str(line, ' ');
    free(line);
    return array;
}

char *my_strtok(char *str)
{
    int i = 0;
    char *line = malloc(sizeof(char) * 100);

    for (; str[i] && str[i] != '='; i++)
        line[i] = str[i];
    line[i] = '\0';
    return line;
}

void display_pwd(list_t **head)
{
    list_t *tmp = *head;

    for (; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->variable, "PWD") == 0)
            break;
    if (!tmp)
        return;
    my_printf("\e[0;36m%s\e[0m", tmp->value);
    my_printf(" -> \e[0m");
}

static void display_prompt(list_t **head)
{
    list_t *tmp = *head;

    for (; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->variable, "USER") == 0)
            break;
    if (!tmp)
        return;
    my_printf("\e[1;34m[%s]↔\e[0;36m", tmp->value);
}

void shell_loop(int ac, char **av, char **env, list_t **head)
{
    char **array = NULL;

    while (1) {
        my_printf("$> ");
        signal(SIGINT, my_handle_signals);
        array = get_commands();
        if (!array)
            continue;
        my_exit(array, head);
        execute_line(head, array);
        free_array(array);
    }
}
