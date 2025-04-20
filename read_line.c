#include "main.h"

ssize_t read_line(char **line, size_t *len)
{
	printf("$ ");
	return getline(line, len, stdin);
}
