#include "main.h"

void handle_exit(char **argv, char *line)
{
	int i;

	for (i = 0; argv[i]; i++)
	free(argv[i]);
	free(argv);
	free(line);
	exit(0);
}
