#include "main.h"
#include <stdlib.h>

void handle_exit(char **argv, char *line_copy, char *line)
{
	int i;

	for (i = 0; argv[i]; i++)
	free(argv[i]);
	free(argv);
	free(line_copy);
	free(line);
	exit(0);
}
