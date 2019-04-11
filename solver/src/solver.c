/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver functions
*/

#include "solver.h"

char *read_file(char *filepath)
{
    char *buffer = NULL;
    const int fd = open(filepath, O_RDONLY);
    int fs = 0;
    struct stat fi;

    if ((fs = stat(filepath, &fi)) == -1)
        return (NULL);
    if (fd == -1) {
        close(fd);
        return (NULL);
    }
    buffer = malloc(sizeof(char) * (fi.st_size + 1));
    if (read(fd, buffer, fi.st_size) == -1) {
        close(fd);
        free(buffer);
        return (NULL);
    }
    buffer[fi.st_size] = 0;
    close(fd);
    return (buffer);
}

int solver(char *filepath)
{
    settings_t *sets = (settings_t *)malloc(sizeof(settings_t));
    char *buffer = NULL;

    init_struct(sets);
    if ((buffer = read_file(filepath)) == NULL)
        return (84);
    sets->map = my_str_to_word_tab(sets, buffer, '\n');
    start_solve(sets);
    if (sets->map != NULL) {
        for (unsigned int i = 0; sets->map[i] != NULL; i++) {
            free(sets->map[i]);
        }
        free(sets->map);
    }
    free(sets);
    return (0);
}