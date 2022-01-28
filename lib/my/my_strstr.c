/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"
#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    char *found;

    found = malloc(sizeof(char) * my_strlen(str));
    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            found[j] = str[i];
            j++;
        } else if (j > 0) {
            found[j] = str[i];
            j++;
        }
        i++;
    }
    found[j] = '\0';
    return found;
}
