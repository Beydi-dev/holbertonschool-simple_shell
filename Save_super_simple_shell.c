#include "main.h"

/**
 * main - Entry point of the super simple shell
 * @ac: Argument count
 * @av: Argument vector
 * @envp: Environment variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **envp)
{
	char *line = NULL, **argv;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status, line_number = 1;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		argv = tokenize_line(line);
		if (!argv || !argv[0])
		{
			free_argv(argv);
			line_number++;
			continue;
		}
		pid = fork();
		if (pid == 0)
		execute_command(av[0], argv, line_number, envp);
		else
			wait(&status);

		free_argv(argv);
		line_number++;
	}
	free(line);
	return (0);
}
