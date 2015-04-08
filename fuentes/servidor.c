#include <stdio.h>
#include <netinet/in.h>
#include <socket.h>

#define MAX_CONN 10 //numero maximo de conexiones

main(int argc, char *argv)
{
  int s;
  //structura que contiene, la familia a la que pertenece el socket, puerto y direccion de internet
  struct sockaddr_in server_struct;

  if(argc == 2)
  {
    //creacion del socket de tipo TCP(SOCK_STREAM), y protocolo IPv4(AF_INET)
    s = socket(AF_INET, SOCK_STREAM, 0); 
    
    if(s != -1)
    {
      //actualizacion de la estructura del servidor 
      server_struct.sin_family = AF_INET;
      server_struct.sin_port = htons(atoi(argv[1]));
      server_struct.sin_addr.s_addr = htonl(INADDR_ANY);

      //asigna un nombre local al socket
      if( bind(s, struct sockaddr*)&server_struct, sizeof(server_struct) != 1 )
      {
	//esperando peticion de conexion por parte de un cliente
	listen(s,MAX_CONN);
	
	//....
      }
    }
  }
}

