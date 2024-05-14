/*
** EPITECH PROJECT, 2024
** my_speratator
** File description:
** This function takes fragments of sentences to turns it into an array
** It keeps the delimiters appart into the array, and separates
** the words by a space
*/

#include "../includes/lib.h"

#include <stdlib.h>
#include <stdio.h>

bool is_a_delim(char const *str, char const *delim)
{
    if (!str || !delim)
        return false;
    while (*str != *delim && *delim)
        delim++;
    if (!*delim)
        return false;
    while (*str == *delim && *str)
        str++;
    if (!*str)
        return true;
    else
        return false;
}

static int count_elements(char **reference_array, char const *delim)
{
    int elements_count = 1;
    bool last_state;
    bool current_state;

    if (!reference_array || !*reference_array)
        return 0;
    last_state = is_a_delim(reference_array[0], delim);
    for (; *reference_array; reference_array++) {
        current_state = is_a_delim(*reference_array, delim);
        if (last_state != current_state) {
            elements_count++;
            last_state = current_state;
        }
    }
    return elements_count;
}

static char *add_word(char *str, char *word)
{
    char *temp = my_strcat(str, " ");
    char *new_str = my_strcat(temp, word);

    FREE(str);
    FREE(temp);
    return new_str;
}

static char **malloc_array(size_t size)
{
    char **new_array = malloc(sizeof(char *) * (size));

    new_array[size - 1] = NULL;
    return new_array;
}

char **my_separator(char const *str, char const *delim)
{
    char **reference_array = my_str_to_word_array(str, " \t\n");
    char **ref_array_cpy = reference_array;
    int elements_count = count_elements(reference_array, delim);
    char **new_array = NULL;

    if (elements_count < 1)
        return NULL;
    new_array = malloc_array((size_t)(elements_count + 1));
    for (int i = 0; i < elements_count; i++) {
        new_array[i] = my_strdup(*ref_array_cpy);
        ref_array_cpy++;
        if (is_a_delim(new_array[i], delim))
            continue;
        while (*ref_array_cpy && !is_a_delim(*ref_array_cpy, delim)) {
            new_array[i] = add_word(new_array[i], *ref_array_cpy);
            ref_array_cpy++;
        }
    }
    my_arrayfree((void **)reference_array);
    return new_array;
}
