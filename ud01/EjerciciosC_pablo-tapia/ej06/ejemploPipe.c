#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	int fd[2];
	char buffer [30];
	pid_t pid;

	pipe(fd); //se crea el pipe

	pid=fork(); //se crea el proceso hijo

	switch(pid) {
		case -1: //ERROR
			printf("NO SE HA PODIDO CREAR HIJO...");
			exit(-1);
			break;
		case 0:
			printf("EL HIJO  escribe en el pipe...\n");
			write(fd[1], "Hola papi", 10);
			break;
		default: //PADRE
			wait(NULL); //espera que finalice proceso hijo
			printf("El PADRE lee del pipe... \n");
			read(fd[0], buffer, 10);
			printf("\tMensaje leido: %s\n", buffer);
			break;
	}
}
