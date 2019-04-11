/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** algorithm functions
*/

#include "solver.h"

char choose_a_way(settings_t *sets, unsigned int i, unsigned int j)
{
    int move[4] = {((-1 + sets->last_pos) + 4) % 4,
    ((0 + sets->last_pos) + 4) % 4, ((1 + sets->last_pos) + 4) % 4,
    ((2 + sets->last_pos) + 4) % 4};
    char moves[4] = {((i > 0) ? sets->map[i - 1][j] : 'X'),
     ((j < sets->cols) ? sets->map[i][j + 1] : 'X'),
     ((i < sets->rows) ? sets->map[i + 1][j] : 'X'),
     ((j > 0) ? sets->map[i][j - 1] : 'X')};

    for (int k = 0; k < 4; k++) {
        if (moves[move[k]] != 'X') {
            sets->last_pos = k;
            moves[move[k]] = (moves[move[k]] == '*') ? 'o' : '*';
            return ('o');
        }
    }
    return (0);
}

int start_solve(settings_t *sets)
{
    for (unsigned int i = 0; i < sets->rows - 1; i++) {
        for (unsigned int j = 0; j < strlen(sets->map[i]); j++) {
            choose_a_way(sets, i, j);
        }
        printf("%s\n", sets->map[i]);
    }
    return (0);
}