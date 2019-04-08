/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "generator.h"

void to_txt(char ** str, char ** av)
{
    FILE *fp = fopen("maze.txt","w");
    int fd = open("maze.txt", O_WRONLY);

    for (int h = 0; h < atoi(av[2]); h++)
        printf("%s", str[h]);
    for (int i = 0; str[i] != NULL; i++)
        write(fd, str[i], strlen(str[i]));
    fclose(fp);
}

void disp(char **str, char **av)
{
    int r = 0;
    int z = 0;

    srand(time(NULL));
    for (int i = 0; i != atoi(av[2]); i++) {
        for (int j = 0; j != atoi(av[1]) + 1; j++) {
            r = rand();
            if (j == atoi(av[1]))
                str[i][j] = '\n';
            else if ((j == 0 && i == 0) || i%2 != 0 ||
                ((j == atoi(av[1]) - 1 && i == atoi(av[2]) -1)))
                str[i][j] = '*';
            else
                str[i][j] = 'X';
        }
        z = r % atoi(av[1]);
        if (i%2 == 0)
            str[i][z] = '*';
    }
    to_txt(str, av);
}

void disp_np(char **str, char **av)
{
    int r = 0;
    int z = 0;

    srand(time(NULL));
    for (int i = 0; i != atoi(av[2]); i++) {
        for (int j = 0; j != atoi(av[1]) + 1; j++) {
            r = rand();
            if (j == atoi(av[1]))
                str[i][j] = '\n';
            else if ((j == 0 && i == 0) || i%3 != 0 ||
                ((j == atoi(av[1]) - 1 && i == atoi(av[2]) -1)))
                str[i][j] = '*';
            else
                str[i][j] = 'X';
        }
        z = r % atoi(av[1]);
        if (i%3 == 0)
            str[i][z] = '*';
    }
    to_txt(str, av);
}

void load_2d_arr_from_file(char **av, int ac)
{
    char **str = malloc(sizeof(char *) * (atoi(av[2])));
    int i = 0;

    while (i != atoi(av[2])) {
        str[i] = malloc(sizeof(char) * (atoi(av[1]) + 1));
        i = i + 1;
    }
    str[i] = NULL;
    if (ac == 4)
        disp(str, av);
    if (ac == 3)
        disp_np(str, av);
}

int main(int ac, char **av)
{
    if (ac == 3 || ac == 4)
        load_2d_arr_from_file(av, ac);
    else
        return (84);
    return (0);
}