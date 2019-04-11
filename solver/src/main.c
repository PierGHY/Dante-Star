/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "solver.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    return (solver(argv[1]));
}