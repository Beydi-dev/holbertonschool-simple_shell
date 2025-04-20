#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h> /*pour utiliser struc stat*/
char *_getenv(const char *name);
char **tokenize_line(char *line);
ssize_t read_line(char **line, size_t *len);
void free_argv(char **argv);
extern char **environ;
#endif
