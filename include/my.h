/*
** EPITECH PROJECT, 2025
** Current project
** File description:
** Tek1 project at Epitech
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <wait.h>
typedef struct list {
    char *variable;
    char *value;
    struct list *next;
    int last_exit;
} list_t;

//Mini printf
int mini_printf(const char *format, ...);
int my_putchar(char c);
int my_printf(const char *format, ...);
int my_putnbr(int nb);
unsigned int my_put_un(unsigned int nb);
int my_putstr(char const *str);
//
int my_strlen(char const *str);
char *my_strdup(char *src);
int my_strcmp(char *first, char *second);
int my_strncmp(char const *s1, char const *s2, int n);
void shell_loop(int ac, char **av, char **env, list_t **head);
char **clean_str(char *str, char delim);
int my_getnbr(char const *str);
int get_ac(char **array);
void free_array(char **array);
char *my_strcat(char *dest, const char *src);
void execute_line(list_t **head, char **array);
char *copy(char *dest, char *src);
int minicheck(char **array, list_t **head);
int big_check(char **array, list_t **head);
//builtins fonctions
list_t *get_env_value(list_t **head, char *variable);
void update_env(list_t **head, char *variable, char *value);
void print_env(char **array, list_t **head);
void my_setenv(char **array, list_t **head);
void my_unsetenv(char **array, list_t **head);
void go_home(list_t **head, char **array);
int my_cd(list_t **head, char **array);
void print_exit(list_t **head, char **array);
void my_exit(char **array, list_t **head);
void manage_backcd(list_t **head, char **array);
void print_env_var(list_t **head, char **array);
//functions to manipulate the linked list
list_t *create_node(char *variable, char *value);
void add(list_t **head, char *variable, char *value);
void array_to_list(list_t **head, char **env);
void disp(list_t **head);
void free_list(list_t **head);
#endif
