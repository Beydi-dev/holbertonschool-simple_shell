#include "main.h"

/**
 * handle_exit - Libère la mémoire et quitte le programme.
 * @argv: Commande et arguments.
 * @line: Ligne lue à libérer.
 *
 * Return: Rien, quitte avec 0.
 */
void handle_exit(char **argv, char *line)
{
	free_argv(argv);
	free(line);
	exit(0);
}
