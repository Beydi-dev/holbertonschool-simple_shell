#include "main.h"

int main(int ac, char **av, char **envp)
{
	char *line = NULL, *line_copy = NULL, *token;
	size_t len = 0;
	ssize_t nread;
	char **argv;
	int count, i;
	/*for execve variables*/
	(void) ac;
	(void) av;
	pid_t pid = 0;
	int status;
	//char *args[] = {argv[0], NULL, NULL};

	while (1)
	{
		count = 0, i = 0;
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line_copy = strdup(line);
		if (!line_copy)
			break;

		/*compter les tokens*/
		token = strtok(line, " \n");
		while (token)
		{
			count++;
			token = strtok(NULL, " \n");
		}

		/*allouer argv*/
		argv = malloc(sizeof(char *) * (count + 1));
		if (!argv)
		{
			free(line_copy);
			break;
		}

		/*remplir argv*/
		token = strtok(line_copy, " \n");
		while (token)
		{
			argv[i] = strdup(token);
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

/*fork et execve*/
		pid = fork();
		if (pid == -1)
		{
			break;
		}
		else if (pid == 0)
		{
			if (execve( argv[0],argv, envp) == -1)
			{
				break;
			}
		}
		else
		wait (&status);
		

		/*Test
		for (i = 0; argv[i]; i++)
			printf("-> %s\n", argv[i]);
		*/

		/*free*/
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(line_copy);
	}
	free(line);
	return (0);
}
