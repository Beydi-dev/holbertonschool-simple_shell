#include <stdio.h>
#include <unistd.h>
int main(void){
	char *argv[] = {"./affichage",(char *) NULL};
	execve("./affichage", argv, NULL);
}