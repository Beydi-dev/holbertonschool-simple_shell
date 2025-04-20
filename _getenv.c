#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Pointer to the value of the variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		/* Compare le début de environ[i] avec "name=" */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/* Retourne ce qui se trouve après le '=' */
			return (environ[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
