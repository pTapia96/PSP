#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(void)
{
	char saludo[] = "Un saludo!!!\n";
	char buffer[10]; //como leemos de uno en uno en un while, esto podría tener longitud 1
	int fd, bytesleidos;
	
	fd=open("texto.txt",1);//fichero se abre solo para escritura
	
	if( fd == -1 )
	{
		printf("ERROR AL ABRIR EL FICHERO...\n");
		exit(-1);
	}
	
	printf("Escribo el saludo...\n");
	write(fd,saludo, strlen(saludo));
	close(fd); //cierro el fichero
	
	fd=open("texto.txt", 0); //el fichero se abre solo para lectura
	printf("Contenido del fichero: \n");
	
	//leo bytes de uno en uno y lo guardo en buffer
	bytesleidos= read(fd, buffer, 1);
	while (bytesleidos!=0) {
		printf("%1c", buffer[0]); //pinto el byte lido
		bytesleidos= read(fd, buffer, 1); //leo otro byte
	}
	close(fd);
}		


//EXPLICACIÓN
//1-Creamos la string con el texto con el que queremos trabajar (char nombre[] = "Texto uwu")
//2-Creamos la string buffer donde iremos acumulando el texto a leer
//3-Creamos el int fd = open("texto.txt", 1) ((read only))
//4-Creamos el int bytesleidos para saber cuando ha terminado el read

//open abre el fichero y se utiliza como argumento en la función write y en la función read.
	//devuelve -1 si hay algún error.

//write tiene como argumentos: DONDE ESCRIBO, QUÉ ESCRIBO, CUANTO ESCRIBO
//read tiene como argumentos: QUÉ LEO, DONDE TRANSCRIBO, CUANTO LEO

//read devuelve el numero de bytes leídos; por eso cuando acaba devuelve 0

//se abre, se escribe, se cierra. se abre otra vez, se lee, se vuelve a cerrar.
//me imagino que hasta que no cierro un fichero, el puntero sigue donde leyó/escribió por última vez
