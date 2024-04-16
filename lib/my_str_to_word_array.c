/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** This function splits the words of a string into mutiple strings.
*/

#include <stdlib.h>
#include "../includes/lib.h"

static int is_in_list(char c, char const *delim)
{
    if (c == '\0')
        return 0;
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return 0;
    }
    return 1;
}

static int go_to_next_word(int *i, char const *str, char const *delim)
{
    int offset = 0;
    int i_bis = *i;

    while (str[i_bis] != '\0' && is_in_list(str[i_bis], delim)) {
        offset++;
        i_bis++;
    }
    while (str[i_bis] != '\0' && !is_in_list(str[i_bis], delim)) {
        offset++;
        i_bis++;
    }
    return offset;
}

static int count_words(char const *str, char const *delim)
{
    int i = 0;
    int count = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    while (!is_in_list(str[i], delim) && str[i] != '\0')
        i++;
    while (str[i] != '\0') {
        count++;
        i += go_to_next_word(&i, str, delim);
    }
    return count;
}

static int get_next_word_len(char const *str, int *cursor, char const *delim)
{
    int len = 0;

    while (!is_in_list(str[*cursor], delim) && str[*cursor] != '\0')
        *cursor += 1;
    while (is_in_list(str[*cursor + len], delim) && str[*cursor + len] != '\0')
        len++;
    return len;
}

static char *add_element(char const *str, int *cursor, char const *delim)
{
    int element_len = get_next_word_len(str, cursor, delim);
    char *new_element = malloc(sizeof(char) * (element_len + 1));
    int i = *cursor;

    if (element_len < 1) {
        free(new_element);
        return NULL;
    }
    new_element[element_len] = '\0';
    while (is_in_list(str[*cursor], delim)) {
        new_element[*cursor - i] = str[*cursor];
        *cursor += 1;
    }
    return new_element;
}

char **my_str_to_word_array(char const *str, char const *delim)
{
    int word_count;
    char **array;
    int cursor = 0;

    if (str == NULL || delim == NULL)
        return NULL;
    word_count = count_words(str, delim);
    array = malloc(sizeof(char *) * (word_count + 1));
    array[word_count] = NULL;
    if (word_count < 1)
        return NULL;
    for (int i = 0; i < word_count; i++)
        array[i] = add_element(str, &cursor, delim);
    return array;
}
