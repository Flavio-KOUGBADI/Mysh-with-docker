/*
** EPITECH PROJECT, 2025
** kds
** File description:
** dk
*/

#include "../include/my.h"
int my_getnbr(char const *str)
{
    int i = 0;
    double nb = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < '-' || str[i] > '9'))
            return -1;
        nb = nb + (str[i] - 32);
    }
    return nb;
}
