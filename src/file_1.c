/*
** EPITECH PROJECT, 2022
** file_1.c
** File description:
** first file of Minishell project
*/

#include "my.h"
#include "minishell.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

char **add_funct_to_paths(char **paths, char **args)
{
    char *buffer = malloc(sizeof(char) * 100);
    char *funct = malloc(sizeof(char) * my_strlen(args[0]));
    int temp = 0;
    int k = 0;

    funct = args[0];
    while (paths[k + 1] != NULL) {
        temp = my_strlen(paths[k]) + my_strlen(funct) + 1;
        buffer = my_strcpy(buffer, paths[k + 1]);
        paths[k] = malloc(sizeof(char) * temp);
        buffer = my_strcat(buffer, "/");
        paths[k] = my_strcat(buffer, funct);
        printf("paths[%d] during while: %s\n", k, paths[k]);
        k++;
    }
    printf("paths (end of funct):\n");
    for (int m = 0; paths[m] != NULL; m++)
        my_printf("paths[%d] after while: %s\n", m, paths[m]);
    free(funct);
    free(buffer);
    return paths;
}

int get_path_line(char **env)
{
    int line = 0;

    while(env[line] != NULL) {
        if (my_strncmp("PATH=", env[line], 5) != true)
            line++;
        else
            break;
    // printf("%d\n", line);
    // printf("env[line]: %s\n", env[line]);
    }
    return line;
}

char **get_paths(char **env)
{
    int i = get_path_line(env);
    int j = 0;
    char **paths = malloc(sizeof(char*) * 15);
    char *strToken = strtok(env[i], "=");

    while (strToken != NULL) {
        paths[j] = malloc(sizeof(char) * my_strlen(strToken));
        paths[j] = strToken;
        strToken = strtok(NULL, ":");
        j++;
    }
    paths[j] = NULL;
    // for (int k = 0; paths[k] != NULL; k++)
    //     my_printf("paths[%d]: %s\n", k, paths[k]);
    return paths;
}

int count_args(char *buffer)
{
    int count = 1;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == ' ')
            count++;
        if (buffer[i] == '\0') {
            count++;
        }
        i++;
    }
    return count;
}

char **get_args(char *buffer)
{
    int i = 0;
    int nb_args = count_args(buffer);
    char **args = malloc(sizeof(char*) * nb_args);
    char *strToken = strtok(buffer, " ");

    while (strToken != NULL) {
        args[i] = malloc(sizeof(char) * my_strlen(strToken));
        args[i] = strToken;
        strToken = strtok(NULL, " ");
        i++;
    }
    // for (int k = 0; args[k + 1] != NULL; k++)
    //     my_printf("args[%d]: %s\n", k, args[k]);
    return args;
}

void main(int ac, char **av, char **env)
{
    char *buffer = malloc(sizeof(char) * 150);
    char **args;
    char **paths;
    int temp = 0;

    while (1) {
        my_printf("$> ");
        temp = read(STDIN_FILENO, buffer, 150);
        args = get_args(buffer);
        for (int k = 0; args[k + 1] != NULL; k++)
            my_printf("final args[%d]: %s\n", k, args[k]);
        paths = get_paths(env);
        printf("post add\n");
        paths = add_funct_to_paths(paths, args);

        printf("paths:\n");
        for (int k = 0; paths[k] != NULL; k++)
            my_printf("paths[%d]: %s\n", k, paths[k]);
        buffer[temp - 1] = '\0';
    }
}
