/*
** EPITECH PROJECT, 2022
** helper
** File description:
** helper
*/

#include "../my.h"
#include <unistd.h>

int helper(int argc, char *str)
{
    char *strr = "USAGE\n    ./my_paint file_path/name_image\n";
    if (argc == 2)
        if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
            write(1, strr, my_strlen(strr));
            return (1);
        }
    return (0);
}
