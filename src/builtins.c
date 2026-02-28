/*
** EPITECH PROJECT, 2026
** sdsd
** File description:
** sdsd
*/

#include "../include/my.h"
void print_env(char **array, list_t **head)
{
    if (my_strcmp(array[0], "env") != 0 && my_strcmp(array[0], "setenv") != 0)
        return;
    if (array[1] != NULL)
        return;
    disp(head);
}

void add_env(list_t **head, char *var, char *value)
{
    list_t *tmp = *head;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->variable, var) == 0) {
            free(tmp->value);
            tmp->value = my_strdup(value);
            return;
        }
    }
    add(head, var, value);
}

static void manage_setenv(char **array, list_t **head)
{
    int ac = get_ac(array);
    int ret = minicheck(array, head);
    char *str = "setenv: Variable name must contain alphanumeric characters.\n";

    if (ret == 84)
        return;
    ret = big_check(array, head);
    if (ret == 1) {
        write(2, str, 60);
        (*head)->last_exit = 1;
        return;
    }
    if (ac == 2)
        add(head, array[1], "");
    if (ac == 3)
        add_env(head, array[1], array[2]);
}

void my_setenv(char **array, list_t **head)
{
    int ac = 0;

    if (my_strcmp(array[0], "setenv") != 0)
        return;
    for (; array[ac]; ac++);
    if (my_strcmp(array[0], "setenv") == 0 && ac == 1) {
        print_env(array, head);
        return;
    }
    if (my_strcmp(array[0], "setenv") == 0 && ac > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
        return;
    }
    manage_setenv(array, head);
}

static int free_head(list_t **head, char **array)
{
    list_t *tmp = NULL;

    if (my_strcmp((*head)->variable, array[1]) == 0) {
        tmp = *head;
        (*head) = tmp->next;
        free(tmp->variable);
        free(tmp->value);
        free(tmp);
        return 0;
    }
    return 1;
}

static void free_for_me(list_t *tmp, list_t *new_next)
{
    free(tmp->next->variable);
    free(tmp->next->value);
    free(tmp->next);
    tmp->next = new_next;
}

void my_unsetenv(char **array, list_t **head)
{
    list_t *tmp = *head;
    list_t *new_next = NULL;
    int ret = 0;

    if (my_strcmp(array[0], "unsetenv") != 0)
        return;
    if (array[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return;
    }
    ret = free_head(head, array);
    if (ret == 0)
        return;
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->next && my_strcmp(tmp->next->variable, array[1]) == 0)
            break;
    if (!tmp)
        return;
    new_next = (tmp->next)->next;
    free_for_me(tmp, new_next);
}

static void my_perror(char **array)
{
    if (errno == 13) {
        perror(array[0]);
        return;
    }
    my_printf("%s: %s.\n", array[1], strerror(errno));
}

static int go_target(list_t **head, char **array)
{
    char *pwd = getcwd(NULL, 0);
    char path[10000];

    copy(path, pwd);
    my_strcat(path, "/");
    my_strcat(path, array[1]);
    update_env(head, "OLDPWD", pwd);
    if (chdir(array[1]) != 0) {
        my_perror(array);
        free(pwd);
        return 1;
    }
    free(pwd);
    pwd = NULL;
    pwd = getcwd(pwd, 0);
    update_env(head, "PWD", pwd);
    free(pwd);
    return 0;
}

int my_cd(list_t **head, char **array)
{
    int ac = get_ac(array);

    if (my_strcmp(array[0], "cd") != 0)
        return -1;
    if (ac > 2) {
        errno = 7;
        write(2, "string not in pwd: ", 19);
        write(2, array[1], my_strlen(array[1]));
        write(2, "\n", 1);
        return 1;
    }
    if (ac == 1 || (ac == 2 && my_strcmp(array[1], "~") == 0))
        go_home(head, array);
    else if (ac == 2 && array[1][0] != '-')
        (*head)->last_exit = go_target(head, array);
    if (ac == 2 && my_strcmp(array[1], "-") == 0)
        manage_backcd(head, array);
    return (*head)->last_exit;
}
