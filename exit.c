#include "main.h"

/**
 * handle_exit - Frees memory and exits the program.
 * @argv: Array of arguments to free.
 * @line: Input line to free.
 *
 * Return: Nothing (exits the program).
 */
void handle_exit(char **argv, char *line)
{
	int i;

	for (i = 0; argv[i]; i++)
	free(argv[i]);
	free(argv);
	free(line);
	exit(0);
}
