/*
** EPITECH PROJECT, 2025
** Project
** File description:
** project
*/


#include <stdio.h>
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n && (s1[i] != '\0' && s1[i] == s2[i]); i++);
    if (s1[i] < s2[i])
        return (s1[i] - s2[i]);
    else if (s1[i] > s2[i])
        return (s1[i] - s2[i]);
    else
        return 0;
}
