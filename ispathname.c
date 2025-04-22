#include "main.h"

/**
 * execute_direct_command - Tente d'exécuter une commande avec un chemin direct
 * @argv: tableau d'arguments (la commande + NULL)
 * @envp: environnement
 * Return : void
 **/
void ispathname(char **argv, char **envp)
{
	execve(argv[0], argv, envp);
	perror(argv[0]);
	exit(127);
}
