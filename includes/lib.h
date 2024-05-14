/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** This header contains lib's functions prototypes.
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>

char **my_str_to_word_array(char const *str, char const *delim);
char **my_separator(char const *str, char const *delim);
char *my_strdup(char *str);
char *my_strcat(char const *src1, char const *src2);
char *my_extractor(const char *src, const char *delimiter);
char *my_strncpy(char *dest, const char *src, size_t n);
int my_arraylen(void **array);
void my_strcpy(char *dest, char *src);
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
bool my_strcmp(char const *str1, char const *str2);
bool is_a_delim(char const *str, char const *delim);
bool is_in_list(char c, const char *list);
void my_arrayfree(void **array);
void *my_free(void **ptr);
void *my_alloc(size_t size);
void *my_realloc(void **ptr, size_t size);
bool my_strstr(const char *str, const char *pattern);

#define FREE(ptr) my_free((void **)&ptr)
#define ALLOC(size) my_alloc(size)
#define REALLOC(ptr, size) my_realloc((void **)&ptr, size)
#define ARRAYFREE(array) my_arrayfree((void **)array)
