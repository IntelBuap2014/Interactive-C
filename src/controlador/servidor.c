#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_CONN 10 //numero maximo de conexiones

int pid,conexiones[MAX_CONN];
int len = 1024, i=0;

typedef struct conexiones
{
  int fds;
  struct in_addr dir;
  int hora;
  int min;
  int seg;
}CONEXIONES;

main(int argc, char *argv)
{
 
  time_t t;
  struct tm *tm;
  int ds,size,nuevo_cliente;
  char *recivido = malloc(len);
  CONEXIONES clientes[MAX_CONN];
  
  t = time(NULL);
  tm=localtime(&t); 

  //structura que contiene, la familia a la que pertenece el socket, puerto y direccion de internet
  struct sockaddr_in server_struct, client_struct;

  if(argc == 2)
  {
    //creacion del socket de tipo TCP(SOCK_STREAM), y protocolo IPv4(AF_INET)
    ds = socket(AF_INET, SOCK_STREAM, 0); 
    
    if(ds != -1)
    {
      //actualizacion de la estructura del servidor 
      server_struct.sin_family = AF_INET;
      server_struct.sin_port = htons(atoi(argv[1]));
      server_struct.sin_addr.s_addr = htonl(INADDR_ANY);

      //asigna un nombre local al socket
      if( bind(ds, struct sockaddr*)&server_struct, sizeof(server_struct) != 1 )
      {
	//esperando peticion de conexion por parte de un cliente
	listen(ds,MAX_CONN);
	size = sizeof(struct sockaddr_in);	
	
	while((nuevo_cliente = accept(ds,(struct sockaddr*)&client_struct, &size)) >= 0)
	{
          clientes[i].fds = nuevo_cliente;
          clientes[i].hora = tm->tm_hour;
          clientes[i].min = tm->tm_min;
          clientes[i].seg = tm->tm_sec;
          
	  pid = fork();
	  if(pid < 0)	  
	  {
 	    perror("Error!! en la creacion del hijo!!: ");   //proceso hijo creado
	    exit(1);
	  }
          else if(pid == 0)
	  {
	    printf("\nConexion establecida con el cliente: %s.\n",inet_ntoa(cliente.sin_addr));
            recv(nuevo_cliente, recivido, len, 0);
	    printf()
           	    
	  }
	  
	}
	
	//....
      }
    }
  }
}

