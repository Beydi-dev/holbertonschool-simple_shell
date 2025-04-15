#include "main.h"

/**
 * main - ppid
 * affiche le parent process id
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_ppid;

    my_ppid = getppid();
    printf("%u\n", my_ppid);
    return (0);
}
