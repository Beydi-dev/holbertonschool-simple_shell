#include "main.h"


int super_simple_shell(char **envp)
{
	char *line = NULL, *line_copy = NULL, *token;
	int count, i;
	char **line;
	size_t *len;

	while (1)
	{
		count = 0, i = 0;

		read_line(&line, &len);
		if (read_line(&line, &len) == -1)
			break;
	}
} 