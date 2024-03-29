#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void main() {
	pid_t pid, Hijo_pid;
	pid = fork();
	
	if (pid == -1) //Ha ocurrido un error
	{
		printf("No se ha podido crear el proceso hijo...");
		exit (-1);
	}
	if (pid == 0) //Nos encontramos en Proceso hijo
	{
		printf("Soy el proceso hijo \n\tMi PID es %d, el PID de mi padre es: %d.\n", getpid(), getppid());
	}
	else //Nos encontramos en Proceso padre
	{
		Hijo_pid = wait(NULL); //espera la finalización del proceso hijo
		printf("Soy el proceso padre:\n\tMi PID es %d, el PID de mi padre es: %d.\n\tMi hijo: %d terminó.\n", getpid(), getppid(), pid);
	}
	exit(0);
}

