#include "main.h"

/**
 * main - Entry point of the super simple shell
 * @ac : Argument Count
 * @av : Argument Vector
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	size_t len = 0;
	char **argv = NULL;
	pid_t pid;
	int status, line_number;
	char *shell_name = av[0];

	while (1)
	{
		line_number++;
		if (read_line(&line, &len) == -1)
		{
			free(line);
			break;
		}

		argv = tokenize_line(line);
		if (!argv || !argv[0])
		{
			free_argv(argv);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(av[0], argv, environ) == -1)
			{
				fprintf(stderr, "%s: %d: %s: not found\n", shell_name, line_number, av[0]);
				exit(EXIT_FAILURE);/*exit(127);*/
			}
		}
		else
			wait(&status);

		free_argv(argv);
	}
	free(line);
	return (0);
}
