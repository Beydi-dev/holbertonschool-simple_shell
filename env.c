#include "main.h"

/**
 * handle_env - Affiche les variables d’environnement
 * @argv: Tableau des arguments (sera libéré ici)
 * @envp: Variables d’environnement
 */
void handle_env(char **argv, char **envp)
{
	int i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	free_argv(argv);
}
