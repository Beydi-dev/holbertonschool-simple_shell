#include "main.h"

/**
 * handle_exit - Gère la commande "exit" dans le shell
 * @argv: Tableau d'arguments (exit + éventuellement un code)
 * @line: Ligne lue à libérer
 *
 * Return: Le code de sortie (int)
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
