#include "main.h"

int main(void)
{
	char *line = NULL, *line_copy = NULL, *token;
	size_t len = 0;
	ssize_t nread;
	char **av;
	int count = 0, i = 0;

	while (1)
	{
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

		/*allouer av*/
		av = malloc(sizeof(char *) * (count + 1));
		if (!av)
		{
			free(line_copy);
			break;
		}

		/*remplir av*/
		token = strtok(line_copy, " \n");
		while (token)
		{
			av[i] = strdup(token);
			i++;
			token = strtok(NULL, " \n");
		}
		av[i] = NULL;

		/*Test*/
		for (i = 0; av[i]; i++)
			printf("-> %s\n", av[i]);

		/*free*/
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(line_copy);
	}
	free(line);
	return (0);
}
