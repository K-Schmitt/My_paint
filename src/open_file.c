/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** save file
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

static off_t get_file_size(const char *str)
{
    struct stat stats;
    if (stat(str, &stats) == -1) {
        write(1, "Can't get file size\n", 20);
        return (-1);
    }
    return (stats.st_size);
}

static char *open_read(const char *str, const off_t size)
{
    char *buffer = NULL;
    int folder = 0;
    int read_size = 0;

    if ((folder = open(str, O_RDONLY)) == -1) {
        write(1, "Can't open file\n", 16);
        return (NULL);
    }
    buffer = malloc(sizeof(char) * (size + 1));
    if ((buffer == NULL) || (read_size = read(folder, buffer, size)) == -1) {
        write(1, "Can't read file\n", 16);
        return (NULL);
    }
    if (close(folder) == -1) {
        write(1, "Can't close file\n", 17);
        return (NULL);
    }
    buffer[read_size] = '\0';
    return (buffer);
}

int open_file(char *str, files *file, int option)
{
    if (option == 0) {
        off_t size = 0;
        file->buffer = NULL;
        if ((size = get_file_size(str)) == -1)
            return (-1);
        if ((file->buffer = open_read(str, size)) == NULL)
            return (-1);
        file->path = str;
        return (0);
    }
    off_t size = 0;
    file->buffer_open = NULL;
    if ((size = get_file_size(str)) == -1)
        return (-1);
    if ((file->buffer_open = open_read(str, size)) == NULL)
        return (-1);
    file->path_open = str;
    file->open_active = 1;
    return (0);
}
