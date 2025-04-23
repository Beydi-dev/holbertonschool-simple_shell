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
	int status, line_number = 1;
	(void)ac;
	(void)av;

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

		/* handling exit */
		if (strcmp(argv[0], "exit") == 0)
			handle_exit(argv, line);

		/*handling env*/
		if (strcmp(argv[0], "env") == 0)
		{
			handle_env(argv, envp);
			line_number++;
			continue;
		}
		/* if a command is a pathname*/
		if (strchr(argv[0], '/'))
		{
			ispathname(argv, envp, line_number);
		}
		else
		{
			handle_path(argv, envp, line_number);
		}
		wait(&status);

		free_argv(argv);
		line_number++;
	}
	free(line);
	return (0);
}
