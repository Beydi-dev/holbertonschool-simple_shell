#include "main.h"

char **tokenize_line(char *line)
{
	char *line_copy = NULL, *token;

	char **argv;
	int count = 0, i = 0;
	
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
		return;
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

	/*Test*/
	for (i = 0; argv[i]; i++)
		printf("-> %s\n", argv[i]);

	/*free*/
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(line_copy);
	free(line);
}
