/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int char_to_int(char *str)
{
    int a = 0;
    int i = 0;

    if (str[0] == '-')
        i++;
    while (str[i] != '\0') {
        a = a * 10 + (str[i] - '0');
        i++;
    }
    if (str[0] == '-')
        a *= -1;
    return a;
}

int check_sign(char *str)
{
    int i = 0;

    while (str[i] == '-') {
        str[i] = '0';
        i++;
    }
    if (i == 0)
        return 0;
    else if (i % 2 == 0)
        return 0;
    else
        return 1;
}

void func_size(char const *str, char *str_value, int *i, int *j)
{
    int k = *i;

    if (str[*i] >= '0' && str[*i] <= '9') {
        k--;
        while (str[k] == '-') {
            str_value[*j] = '-';
            ++*j;
            k--;
        }
    }
    while ((str[*i] >= '0') && (str[*i] <= '9')) {
        str_value[*j] = str[*i];
        ++*i;
        ++*j;
    }
    str_value[*j] = '\0';
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    char *str_value;
    int sign = 0;

    str_value = malloc(sizeof(char) * my_strlen(str) + 10);
    while (str[i] != '\0') {
        if (j > 0)
            break;
        func_size(str, str_value, &i, &j);
        if ((str[i] < 48) && (str[i] > 57))
            i++;
        i++;
    }
    sign = check_sign(str_value);
    if (sign == 1)
        str_value[0] = '-';
    return char_to_int(str_value);
}
