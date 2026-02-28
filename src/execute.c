/*
** EPITECH PROJECT, 2026
** execute
** File description:
** find path
*/

#include "../include/my.h"

int is_bultin(char **array)
{
    int ac = get_ac(array);

    if (my_strcmp(array[0], "cd") == 0 || my_strcmp(array[0], "env") == 0
        || my_strcmp(array[0], "setenv") == 0 ||
        my_strcmp(array[0], "unsetenv") == 0)
        return 1;
    if (ac == 2) {
        if (my_strcmp(array[0], "echo") == 0 && array[1][0] == '$')
            return 1;
    }
    return 0;
}

int execute_bultins(list_t **head, char **array)
{
    print_env(array, head);
    my_setenv(array, head);
    my_unsetenv(array, head);
    print_exit(head, array);
    if (my_cd(head, array) == 1)
        (*head)->last_exit = 1;
    return (*head)->last_exit;
}

char *build_path(char **array, char *value)
{
    char path[1000];
    int ret = 1;

    for (char *squel = strtok(value, ":"); squel; squel = strtok(NULL, ":")) {
        copy(path, squel);
        my_strcat(path, "/");
        my_strcat(path, array[0]);
        ret = access(path, X_OK);
        if (ret == 0) {
            free(value);
            return my_strdup(path);
        }
    }
    free(value);
    return NULL;
}

static char *find_binary(list_t **head, char **array)
{
    list_t *tmp = get_env_value(head, "PATH");
    char *path = NULL;

    if (!tmp)
        return NULL;
    if (array[0][0] == '/' || array[0][0] == '.')
        if (access(array[0], X_OK) == 0)
            return my_strdup(array[0]);
    path = build_path(array, my_strdup(tmp->value));
    if (!path) {
        write(2, array[0], my_strlen(array[0]));
        write(2, ": Command not found.\n", 21);
    }
    return path;
}

static char **list_to_array(list_t **head)
{
    char **array = NULL;
    int count = 0;
    list_t *tmp = *head;
    int len1 = 0;
    int len2 = 0;

    for (list_t *tmp0 = *head; tmp0; tmp0 = tmp0->next)
        count++;
    array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        len1 = my_strlen(tmp->variable);
        len2 = my_strlen(tmp->value);
        array[i] = malloc(sizeof(char) * (len1 + len2) + 2);
        copy(array[i], tmp->variable);
        my_strcat(array[i], "=");
        my_strcat(array[i], tmp->value);
        tmp = tmp->next;
    }
    array[count] = NULL;
    return array;
}

static void execute(list_t **head, char **array, char *path)
{
    char *str_error = NULL;
    char **n_env = NULL;

    n_env = list_to_array(head);
    execve(path, array, n_env);
    if (errno == 8) {
        str_error = strerror(errno);
        my_printf("%s: %s. Binary file not executable.\n", array[0], str_error);
        //(*head)->last_exit = 1;
        exit(1);
    }
    perror(array[0]);
    //(*head)->last_exit = 1;
    exit(1);
}

static void funct1(int *status)
{
    if (WCOREDUMP(*status)) {
        write(2, strsignal(WTERMSIG(*status)),
            my_strlen(strsignal(WTERMSIG(*status))));
        write(2, " (core dumped)\n", 15);
        return;
    }
    write(2, strsignal(WTERMSIG(*status)),
        my_strlen(strsignal(WTERMSIG(*status))));
    write(2, "\n", 2);
}

static void in_parent(list_t **head, int *status)
{
    wait(status);
    if (WIFSIGNALED(*status)) {
        if (WCOREDUMP(*status)) {
            funct1(status);
            //(*head)->last_exit = *status;
            return;
        }
        funct1(status);
    }
    if (WIFEXITED(*status)) {
        //(*head)->last_exit = WEXITSTATUS(*status);
        return;
    }
}

int execute_binary(list_t **head, char **array)
{
    char *path = find_binary(head, array);
    pid_t pid = 0;
    int status = 0;

    if (!path) {
        (*head)->last_exit = 127;
        return 127;
    }
    pid = fork();
    if (pid == -1)
        return 84;
    if (pid == 0) {
        execute(head, array, path);
        return 1;
    }
    if (pid > 0) {
        in_parent(head, &status);
    }
    free(path);
    return (*head)->last_exit;
}

void execute_line(list_t **head, char **array)
{
    if (is_bultin(array)) {
        (*head)->last_exit = execute_bultins(head, array);
        return;
    }
    //(*head)->last_exit = execute_binary(head, array);
    return;
}
