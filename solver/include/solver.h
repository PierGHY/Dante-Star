/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** describe file here
*/

#ifndef DELIVERY_SOLVER_H
#define DELIVERY_SOLVER_H

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include <errno.h>
#include <string.h>

#include "struct.h"

// algorithm.c
int start_solve(settings_t *);

// init_struct.c
int init_struct(settings_t *);

// my_str_to_word_tab.c
unsigned int count_lines(char *, char);
unsigned int count_to_next(char *, char, int);
char **my_str_to_word_tab(settings_t *, char *, char);

// solver.c
int solver(char *);

#endif //DELIVERY_SOLVER_H
