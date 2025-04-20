#include "main.h"

ssize_t read_line(char **line, size_t *len)
{
    ssize_t nread;

    printf("$ ");
    nread = getline(line, len, stdin);
    if (nread == -1)
        return -1;

    return nread;
}

