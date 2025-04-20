#include "main.h"

void free_args(char **argv)
{
	int i = 0;
	if (!argv)
		return;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
