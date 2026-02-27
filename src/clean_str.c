/*
** EPITECH PROJECT, 2026
** sddsd
** File description:
** sds
*/

#include "../include/my.h"

int count_elements(char *copy)
{
    char *tmp = NULL;
    int count = 0;

    if (!copy)
        return -1;
    tmp = strtok(copy, " \t");
    if (tmp)
        count = 1;
    if (count != 1)
        return -1;
    while (tmp) {
        tmp = strtok(NULL, " \t");
        if (!tmp)
            break;
        count++;
    }
    return count;
}

char **load_array(char *str, char delim)
{
    char *copy = my_strdup(str);
    int nb_rows = count_elements(copy);
    char **array = NULL;

    if (nb_rows == -1)
        return NULL;
    free(copy);
    copy = my_strdup(str);
    array = malloc(sizeof(char *) * (nb_rows + 1));
    if (array == NULL)
        return NULL;
    for (int i = 0; i <= nb_rows; i++)
        array[i] = NULL;
    array[0] = my_strdup(strtok(copy, " \t"));
    for (int i = 1; i < nb_rows; i++)
        array[i] = my_strdup(strtok(NULL, " \t"));
    free(copy);
    return array;
}

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

char **clean_str(char *str, char delim)
{
    char **array = load_array(str, delim);

    return array;
}
