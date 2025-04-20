#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *path = getenv("PATH");

    if (path)
        printf("La variable PATH est :\n%s\n", path);
    else
        printf("La variable PATH n'existe pas.\n");

    return 0;
}
