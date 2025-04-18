#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Exemple d'utilisation de fork + execv
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();

	if (pid == 0)
	{
		execv("/bin/ls", argv);
		perror("execv");
	}
	else if (pid > 0)
	{
		
		wait(NULL);
		printf("Fils terminé.\n");
	}
	else
	{
		perror("fork");
	}

	return (0);
}
