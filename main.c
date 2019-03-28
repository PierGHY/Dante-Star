/*
** EPITECH PROJECT, 2019
** main
** File description:
** a
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

char ** to_txt(char ** str)
{
    int i = 0;

    int fd = open("maze.txt", O_WRONLY);
    if (fd == -1)
        return (84);
    while (str[i] != NULL) {
        write(fd, str[i], strlen(str[i]));
        i++;
    }
}

void load_2d_arr_from_file(char ** av)
{
    //buffer = malloc(sizeof(char) * (atoi(av[1]) * atoi(av[2])));

    char **str = malloc(sizeof(char *) * (atoi(av[2])));
    int i = 0;

    while (i != atoi(av[2])) {
        str[i] = malloc(sizeof(char) * (atoi(av[1]) + 1));
        i = i + 1;
    }
    str[i] = NULL;
    disp(str, av);
}

void disp(char ** str, char ** av)
{
    int r = 0;

    srand(time(NULL));
    for (int i = 0; i != atoi(av[2]); i++) {
        for (int j = 0; j != atoi(av[1]) + 1; j++) {
            r = rand();
            if (j == atoi(av[1]))
                str[i][j] = '\n';
            else if (j == 0 && i == 0 || j == 0 ||
            i == atoi(av[2]) -1 || r % 2 == 0)
                str[i][j] = '*';
            else
                str[i][j] = 'X';
        }
    }
    for (int h = 0; h < atoi(av[2]); h++)
        for (int z = 0; z < atoi(av[1]) + 1; z++)
            printf("%c", str[h][z]);
    to_txt(str);
    return (str);
}

int main(int ac, char ** av)
{
    if (ac != 2)
        load_2d_arr_from_file(av);
    else
        return (84);
    return(0);
}