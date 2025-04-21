#include "main.h"

/**
 * main - Entry point of the super simple shell
 * @ac: Argument count
 * @av: Argument vector
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	char **argv, *shell_name = av[0];
	pid_t pid;
	int status, line_number = 1;
	(void)ac;

	while (1)
	{
		if (read_line(&line, &len) == -1)
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
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				fprintf(stderr,
						"%s: %d: %s: not found\n",
						shell_name,
						line_number,
						argv[0]);
				exit(127);
			}
		}
		else
			wait(&status);

		free_argv(argv);
		line_number++;
	}
	free(line);
	return (0);
}
