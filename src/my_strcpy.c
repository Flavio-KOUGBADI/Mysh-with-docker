/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** a function that copies a string into another.
*/

#include "../include/my.h"

char *copy(char *dest, char *src)
{
    int i = 0;
    char x;

    for (; src[i] != '\0'; i++) {
        x = src[i];
        dest[i] = x;
    }
    dest[i] = '\0';
    return dest;
}
