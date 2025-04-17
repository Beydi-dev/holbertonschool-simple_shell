#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	pid_t panda = fork();
	int status;
	pid_t fils;

	if (panda == -1)
	{
		printf("Erreur lors de l'appel à fork()\n");
		return -1;
	}

	if (panda == 0)
	{
		printf("Le processus enfant a été créé avec succès.\n");
		printf("PID de l'enfant : %u\n", getpid());
		printf("PID du parent (vu depuis l'enfant) : %u\n", getppid());
	}
	else
	{
		fils = wait(&status);
		printf("le fils vient de se finir\n");
		sleep(3);
		printf("Processus parent en cours d'exécution.\n");
		printf("PID du parent : %u\n", getpid());
		printf("PID de l'enfant (retourné par fork) : %u\n", panda);
		printf("PID du parent du parent : %u\n", getppid());
	}

	return 0;
}
