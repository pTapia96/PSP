#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
	int n = 6;
	pid_t p1 = fork();	
	if (p1 == 0) {
		printf("Valor inicial de la variable: %d\n", n);
		n -= 5;
		printf("Variable en el Proceso Hijo: %d\n", n);			
	} else {
		wait(NULL);
		n += 5;
		printf("Variable en el Proceso Padre: %d\n", n);
	}
}
