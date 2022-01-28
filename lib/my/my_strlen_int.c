/*
** EPITECH PROJECT, 2021
** my_strlen_int.c
** File description:
** Get the number of int in an int array.
*/

int my_strlen_int(int const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}
