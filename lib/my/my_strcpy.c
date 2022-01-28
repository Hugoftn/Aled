/*
** EPITECH PROJECT, 2021
** My_strcpy
** File description:
** |
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
