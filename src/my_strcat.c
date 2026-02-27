/*
** EPITECH PROJECT, 2026
** worl
** File description:
** world
*/

#include "../include/my.h"
int size(char *src)
{
    int i;

    for (int i = 0; src[i] != '\0'; i++);
    return i;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr_dest = dest;
    const char *ptr_src = src;

    while (*ptr_dest != '\0') {
        ptr_dest++;
    }
    while (*ptr_src != '\0') {
        *ptr_dest = *ptr_src;
        ptr_dest++;
        ptr_src++;
    }
    *ptr_dest = '\0';
    return dest;
}
