/*
 *	Proyecto colabarativo: Interactive-C
 *	Cliente
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h> 

int 	len = 1024;
char	message[len];

int main(int argc, char *argv){
	
	ind cl;
	struct sockaddr_in server_struct;
/*	
 *	Creacion del SOCKET, para un cliente
 */
	if((cl = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("\n Error: No es posible crear socket")
	}
	
	server_struct.sin_family = AF_INET;
	server_struct.sin_port = htons(atoi(arv[1]));
	server_struct.sin_addr.s_addr = htonl(INADDR_ANY);

/*
 *	Estableciendo la conección al servidor.
 */
	if(connect(cl, (struct sockaddr *)&server_struct, sizeof(server_struct)) < 0){
		printf("\n Error: No es posible establecer la conexión")
	}
/*
 *	Mensajes, lee y escribe
 */


	while(1){
		read(cl, message, len-1);
		write(cl, 
			
		);
	}

}
