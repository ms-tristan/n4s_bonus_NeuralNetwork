/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** This header contains lib's functions prototypes.
*/

#pragma once

#include <stdbool.h>

char **my_str_to_word_array(char const *str, char const *delim);
char **my_separator(char const *str, char const *delim);
char *my_strdup(char *str, bool do_free);
char *my_strcat(char const *src1, char const *src2);
void my_arrayfree(void **array);
int my_arraylen(void **array);
void my_strcpy(char *dest, char *src);
int my_strcmp(char const *str1, char const *str2);
int mini_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_nbrlen(long long nb);
int my_putchar(char c);
int my_putnbr(int nb);
bool my_char_isnum(char c);
bool my_str_isnum(char *str);
bool my_char_isalpha(char c);
bool my_str_isalphanum(char *str);
bool is_a_delim(char const *str, char const *delim);
