/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** self made and usable printf function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void printable_filter(char *base)
{
    char *final = malloc(sizeof(char) * my_strlen(base));

    for (int i = 0; base[i] != '\0'; i++) {
        if (base[i] >= 32 && base[i] <= 126)
            final[i] = base[i];
        else
            final[i] = '#';
    }
}

char *int_to_binary_str(int a)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * 50);
    char *result = malloc(sizeof(char) * 50);

    for (i = 0; a > 0; i++) {
        temp[i] = (a % 2);
        a /= 2;
    }
    for (i = i - 1; i >= 0; i--) {
        result[j] = temp[i] + '0';
        j++;
    }
    if (a % 2 == 1)
        result[j] = '1';
    return result;
}

int contain_type(char *s, int i)
{
    if ((s[i] == '%') && ((s[i + 1] == 'i') || (s[i + 1] == 'd')))
        return 1;
    if ((s[i] == '%') && (s[i + 1] == 'c'))
        return 2;
    if ((s[i] == '%') && ((s[i + 1] == 's') || (s[i + 1] == 'S')))
        return 3;
    if ((s[i] == '%') && (s[i + 1] == 'b'))
        return 4;
    if ((s[i] == '%') && (s[i + 1] == '%'))
        return 5;
    return 0;
}

void process_binary(char *s, va_list args, int i)
{
    if (contain_type(s, i) == 4) {
        my_putstr(int_to_binary_str(va_arg(args, int)));
        i += 2;
    }
}

void my_printf(char *s, ...)
{
    va_list args;
    va_start (args, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (contain_type(s, i) == 1) {
            my_put_nbr(va_arg(args, int));
            i += 2;
        }
        if (contain_type(s, i) == 2) {
            my_putchar(va_arg(args, int));
            i += 2;
        }
        if (contain_type(s, i) == 3) {
            my_putstr(va_arg(args, char *));
            i += 2;
        }
        process_binary(s, args, i);
        my_putchar(s[i]);
        va_end(args);
    }
}
