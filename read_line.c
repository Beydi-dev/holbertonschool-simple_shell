#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
char *str = NULL;
size_t size = 0;
char line;

printf("$ ");

line = getline(&str, &size, stdin);

if (line == -1)
{
	free(str);
	return (-1);
}
printf("%s", str);
free (str);
return (0);
}