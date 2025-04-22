#include "main.h"

/**
 * execute_command - Fork and execute a command with execve
 * @av: name of the shell (argv[0])
 * @argv: array of arguments (command + NULL)
 * @line_number: current line number
 * @envp: environment variables
 * Return: the status code of the child process
 */
void execute_command(char **av, char **argv, int line_number, char **envp)
{
	int status;

	if (execve(argv[0], argv, envp) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], line_number, argv[0]);
		exit(127);
	}
}