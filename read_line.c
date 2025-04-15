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
//const char *delim = " \n";
char *token;
int count = 0;
int i = 0;
char *str_save;

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

	count = 0;
	i = 0;
/*on travaille sur une copie de str car strtok modifie la chaîne*/
/*on compte le nombre de caracteres dans str pour le malloc dans av*/
	str_save = strdup(str);
	token = strtok(str_save, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
/*allocation dans av maintenant qu'on connait count, +1 pour NULL byte*/
	av = malloc(sizeof(char *) * (count + 1));

	if (av == NULL)
	{
		return (-1);
	}
	token = strtok(str_save, " \n");

	while (token != NULL)
	{
		av[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	av[i] = NULL;
	for (i = 0; av[i] != NULL; i++)
	{
		free(av[i]);
	}
	free(av);
	free(str_save);
}
free(str);
return (0);
}
