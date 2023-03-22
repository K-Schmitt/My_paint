/*
** EPITECH PROJECT, 2022
** geph1.0
** File description:
** main.c
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (helper(argc, argv[1]) == 1)
        return (0);
    files *file = init_file();
    if ((argc == 2 && open_file(argv[1], file, 0) == -1) || argc > 2)
        return (84);
    if (file == NULL)
        return (84);
    struct alll *all = malloc(sizeof(struct alll));
    srand(time(NULL));
    simulation(all, file);
    free(all);
    return (0);
}
