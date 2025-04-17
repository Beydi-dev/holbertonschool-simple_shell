#include "main.h"

int main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	pid_t pid = 0;
	int count;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (count = 0; count < 5; count++)
	{
		pid = fork();
		if (pid == -1)
		{
			break;
		}
		else if (pid == 0)
		{
			if (execve( argv[0],argv, envp) == -1)
			{
				break;
			}
		}
	
		else
		wait (&status);
	}
}
