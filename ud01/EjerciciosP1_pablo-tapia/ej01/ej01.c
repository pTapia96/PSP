#include <stdio.h>
#include <stdlib.h>
void main()
{
	printf("Listado de los procesos activos y envío a un fichero...\n");
	system("ps > procesos_activos");
	printf("Abrimos en gedit el fichero...\n");
	system("gedit procesos_activos");
	printf("Fin del programa...\n");
}
