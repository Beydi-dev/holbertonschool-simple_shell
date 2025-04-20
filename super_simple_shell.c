#include "main.h"

/**
 * main - Entry point of the super simple shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **argv = NULL;
	pid_t pid;
	int status;

	while (1)
	{
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
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);

		free_argv(argv);
	}
	return (0);
}
