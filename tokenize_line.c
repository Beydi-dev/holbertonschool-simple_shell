#include "main.h"

/**
 * tokenize_line - Splits a line into an array of words (tokens).
 * @line: Input string to tokenize.
 *
 * Return: Array of tokens (strings), or NULL on failure.
 */
char **tokenize_line(char *line)
{
	char *line_copy, *token;
	char **argv;
	int count = 0, i = 0;

	line_copy = strdup(line);
	if (!line_copy)
		return (NULL);

	token = strtok(line, " \n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \n");
	}

	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
	{
		free(line_copy);
		return (NULL);
	}

	token = strtok(line_copy, " \n");
	while (token)
	{
		argv[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
