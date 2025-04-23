#include "main.h"

/**
 * handle_path - Finds and executes a command from the PATH.
 * @argv: Array of command and arguments.
 * @envp: Environment variables.
 * @line_number: Line number for error messages.
 *
 * Return: Nothing.
 */
void handle_path(char **argv, char **envp, int line_number)
{
	char *original_path = _getenv("PATH");
	char *path = strdup(original_path);
	char *token;
	int status, found = 0;
	size_t total_len;
	pid_t pid;
	char *full_path;
	struct stat buf;

	token = strtok(path, ":");
	while (token)
	{
		total_len = strlen(token) + strlen(argv[0]) + 2;
		full_path = malloc(sizeof(char) * total_len);

		if (!full_path)
		{
			free(path);
			return;
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);

		/* if the path is valid*/
		if (stat(full_path, &buf) == 0)
		{
			pid = fork();

			if (pid == 0)
			{
				execve(full_path, argv, envp);
				perror("execve"); /* you have to call execute_command function*/
				exit(1);
			}
			else if (pid > 0)
			{
				wait(&status);
				found = 1;
				free(full_path);
				free(path);
				return;
			}
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	if (!found)
		execute_command(argv[0], argv, line_number, envp);
	free(path);
}
