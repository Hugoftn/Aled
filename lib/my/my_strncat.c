/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** |
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    for (j = 0; j <= nb - 1; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
