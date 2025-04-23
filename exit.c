#include "main.h"

/**
 * handle_exit - Frees memory and exits the program.
 * @argv: Command and arguments.
 * @line: Input line to free.
 *
 * Return: Nothing. Exits with 0.
 */
void handle_exit(char **argv, char *line)
{
	int status = 0;

	if (argv[1])
		status = atoi(argv[1]);

	free_argv(argv);
	free(line);
	exit(status);
}
