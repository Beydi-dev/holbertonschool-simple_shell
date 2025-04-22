#include "main.h"

void handle_exit(char **argv, char *line)
{
	int status = 0;

	if (argv[1])
		status = atoi(argv[1]);

	free_argv(argv);
	free(line);
	exit(status);
}