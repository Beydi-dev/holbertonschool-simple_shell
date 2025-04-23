#include "main.h"

/**
 * ispathname - Runs a command with a full or relative path.
 * @argv: Command and arguments.
 * @envp: Environment variables.
 *
 * Return: Nothing. Exits with 127 if it fails.
 */
void ispathname(char **argv, char **envp)
{
	execve(argv[0], argv, envp);
	perror(argv[0]);
	exit(127);
}
