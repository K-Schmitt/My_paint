/*
** EPITECH PROJECT, 2022
** detect
** File description:
** detect
*/

int detection(char *format, int i)
{
    char IDC[20] = {'d', 'i', 'o', 'u', 'x', 'X', 'c', 'E', 'f', 'F', 'g', 'G',
        'a', 'A', 'e','s', 'p', 'n', 'w', '\0'};
    int size_variable = 0;
    for (int y = 0; IDC[y] != '\0'; y++) {
        if (IDC[y] == 'w') {
            i++;
            size_variable++;
            y = 0;
        }
        if (format[i] == IDC[y]) {
            return (y);
        }
    }
    return (0);
}
