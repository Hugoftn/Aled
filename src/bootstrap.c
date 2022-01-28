/*
** EPITECH PROJECT, 2022
** file_one.c
** File description:
** first file for minishell
*/

#include "my.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

void disp_env(char **env)
{
    int i = 0;
    int j = 0;

    while (1) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
        if (env[i] == NULL)
            break;
    }  
}

void print_arg(char **arg)
{
    const char *separators = " ";
    char *strToken = strtok(arg[1], separators);

    while (strToken != NULL) {
        my_printf("%s\n", strToken);
        strToken = strtok(NULL, separators);
    }
}

void execute(char **av, char **env)
{
    int i = -1;
    int j = 0;
    int statut = 0;
    char *strToken = strtok(av[1], " ");
    char *pathname = malloc(sizeof(char) * 30);

    my_printf("Program name: %s\n", strToken);
    pathname = strToken;
    while (strToken != NULL) {
        strToken = strtok(NULL, " ");
        if (j == 0) {
            av[1] = strToken;
            j++;
        }
        i++;
    }
    my_printf("Nb args: %d\n", i);
    my_printf("PID: %d\n", getpid());
    statut = execve(pathname, av, env);
    if (statut == -1)
        my_putstr("Program terminated.\nStatus: Segmentation fault\n");
    else
        my_putstr("Program terminated.\nStatus: OK\n");
}

// void main(int ac, char **av, char **env)
// {
//     execute(av, env);
// }
