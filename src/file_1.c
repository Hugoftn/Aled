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
#include <errno.h>

void exec(char *command, char **args, char **env)
{
    if (fork() == 0) {
        execve(command, args, env);
        if (errno != 0)
            my_printf("%s\n", strerror(errno));
    }
}

char **get_tab_args(char **args)
{
    char **tab_args = malloc(sizeof(char*) * 20);
    int i = 0;

    while (args[i] != NULL) {
        tab_args[i] = malloc(sizeof(char) * 30);
        tab_args[i] = args[i + 1];
        i++;
    }
    return tab_args;
}

char *get_working_paths(char **paths)
{
    for (int i = 0; paths[i + 1] != NULL; i++) {
        if (access(paths[i], F_OK) != -1)
            return paths[i];
    }
}

char **add_funct_to_paths(char **paths, char **args)
{
    char **buffer = malloc(sizeof(char*) * 15);
    char *funct = malloc(sizeof(char) * my_strlen(args[0]));
    int temp = 0;

    funct = args[0];
    for (int k = 0; paths[k + 1] != NULL; k++) {
        temp = my_strlen(paths[k]) + my_strlen(funct) + 1;
        buffer[k] = malloc(sizeof(char) * temp);
        buffer[k] = my_strcpy(buffer[k], paths[k + 1]);
        paths[k] = malloc(sizeof(char) * temp);
        buffer[k] = my_strcat(buffer[k], "/");
        paths[k] = my_strcat(buffer[k], funct);
    }
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
    return args;
}

void main(int ac, char **av, char **env)
{
    char *command;
    char *buffer = malloc(sizeof(char) * 150);
    char **tab_args;
    char **args;
    char **paths;
    int temp = 0;
    int status;

    while (1) {
        my_printf("$> ");
        temp = read(STDIN_FILENO, buffer, 150);
        args = get_args(buffer);
        paths = get_paths(env);
        paths = add_funct_to_paths(paths, args);
        tab_args = get_tab_args(args);
        for (int i = 0; args[i + 1] != NULL; i++)
            printf("args[%d]: %s\n", i, args[i]);
        command = get_working_paths(paths);
        printf("command: %s\n", command);
        // for (int i = 0; env[i + 1] != NULL; i++)
        //     printf("%s\n", env[i]);
        exec(command, args, env);
        printf("status: %d\n", status);
        buffer[temp - 1] = '\0';
    }
}
