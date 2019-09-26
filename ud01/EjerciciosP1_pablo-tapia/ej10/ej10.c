#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
	pid_t p1 = fork();
	if (p1 == -1) {
		printf("Error al crear el Proceso Hijo");
		exit(-1);
	} else if (p1 == 0) {
		pid_t p2 = fork();
		if (p2 == -1) {
			printf("Error al crear el Proceso Nieto");	
		} else if (p2 == 0) {
			printf("Soy el Proceso Nieto (PID: %d):\n"
				"-Mi padre es el Proceso Hijo (PID: %d).\n\n", getpid(), getppid());
		} else {
			wait(NULL);
			printf("\tSoy el Proceso Hijo (PID: %d):\n"
				"\t-Mi hijo, el Proceso Nieto (%d), terminó.\n"
				"\t-Mi padre es el Proceso Abuelo (PID: %d).\n\n", getpid(), p2, getppid());
		}
	} else {
	wait(NULL);
	printf("\t\tSoy el Proceso Abuelo (PID: %d):\n"
		"\t\t-Mi hijo, el Proceso Hijo (%d), terminó.\n", getpid(), p1);
	}
}
