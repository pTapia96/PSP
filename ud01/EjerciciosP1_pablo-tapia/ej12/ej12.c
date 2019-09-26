#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

	void main(void) {
	char mensaje[] = "Buenos dias padre.";
	int longitud = strlen(mensaje);
	char buffer[longitud];
	int fd[2];
	pid_t p;

	pipe(fd);
	p = fork();

	if (p == -1) {
		printf("Error al crear el proceso HIJO");
		exit(-1);
	} else if (p == 0) {
		printf("El HIJO envía algo al pipe.\n");
		write(fd[1], mensaje, longitud);
	} else {
		wait(NULL);
		read(fd[0], buffer, longitud);
		printf("El PADRE recibe algo del pipe: %s\n", buffer);
	}
}
