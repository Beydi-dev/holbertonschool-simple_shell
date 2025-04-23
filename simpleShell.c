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
			int i = 0;

			while (envp[i])
			{
				printf("%s\n", envp[i]);
				i++;
			}

			free_argv(argv);
			line_number++;
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (strchr(argv[0], '/'))
				ispathname(argv, envp);
			else
			{
				handle_path(argv, envp, line_number);
				exit(127); /* if nothing were found in the path */
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
