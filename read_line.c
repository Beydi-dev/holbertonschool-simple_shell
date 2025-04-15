#include "main.h"

/* fonction getline
** permet de recuperer les entrees utilisateur
*/
int main (int ac, char **av)
{
char *str = NULL;
size_t size = 0;
ssize_t line;
(void)ac;

/* boucle infinie*/
while (1)
{
	printf("$ ");
	line = getline(&str, &size, stdin);
	
	if (line == -1)
	{
		free (str);
		return (-1);
	}
	printf("%s", str);
}
return (0);
}
