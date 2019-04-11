/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** my_str_to_word_tab.c
*/

#include "solver.h"

unsigned int count_lines(char *str, char separator)
{
    unsigned int n = 1;

    if (str == NULL)
        return (n);
    for (unsigned int i = 0; str[i] != 0; i++)
        if (str[i] == separator)
            n++;
    return (n);
}

unsigned int count_to_next(char *str, char separator, int i)
{
    int n = 0;

    for (; str[i] != '\0' && str[i] != separator; i++, n++);
    return (n);
}

char **my_str_to_word_tab(settings_t *sets, char *str, char separator)
{
    unsigned const int n = count_lines(str, separator);
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    char **tab = malloc(sizeof(char *) * (n + 1));

    sets->rows = n;
    if (str == NULL) {
        free(tab);
        return (NULL);
    }
    for (i = 0; i < n; i++, j++) {
        tab[i] = malloc(sizeof(char) * (count_to_next(str, separator, j) + 1));
        for (k = 0; str[j] != '\0' && str[j] != separator; j++, k++)
            tab[i][k] = str[j];
        tab[i][k] = 0;
    }
    tab[i] = NULL;
    free(str);
    return (tab);
}