#include <stdio.h>
#include <unistd.h>

/**
 * main - ppid
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t print_env;
	extern char **environ;

    print_env = **environ;
    printf("%u\n", print_env);
    return (0);
}
