#include <stdio.h>
#include <stdlib.h>
void main()
{
	printf("Listado de los procesos activos:\n");
	system("ps");
	printf("Envío a un fichero... ");
	system("ps > procesos_activos");
	printf("Fin del programa.\n");
}
