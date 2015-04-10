#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
	
#define PORT 4950
#define BUFSIZE 1024
#define MAX_CONN 10

typedef struct conexiones
{
  int fds;
  struct in_addr dir;
  int hora;
  int min;
  int seg;
}CONEXIONES;

void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master, char *client)
{	
	strcat(client,recv_buf);
	if (FD_ISSET(j, master)){
		if (j != sockfd && j != i) {			
			if (send(j, client, nbytes_recvd+18, 0) == -1) {
				perror("send");
			}
		}
	}
}
		
void send_recv(int i, fd_set *master, int sockfd, int fdmax, char *client)
{
	int nbytes_recvd, j;
	char recv_buf[BUFSIZE], buf[BUFSIZE];
	
	if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0) {
		if (nbytes_recvd == 0) {
			printf("sockte %d desconectado\n", i);
		}else {
			perror("recv");
		}
		close(i);
		FD_CLR(i, master);
	}else { 
		for(j = 0; j <= fdmax; j++){
			send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master, client);
		}
	}	
}
		
int connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr)
{
	socklen_t addrlen;
	int newsockfd;
	
	addrlen = sizeof(struct sockaddr_in);
	if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1) {
		perror("accept");
		exit(1);
	}else {
		FD_SET(newsockfd, master);
		if(newsockfd > *fdmax){
			*fdmax = newsockfd;
		}
		printf("new connection from %s on port %d \n",inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
		return newsockfd;
	}	
}
	
void connect_request(int *sockfd, struct sockaddr_in *my_addr, int puerto)
{
	int yes = 1;
		
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
		
	my_addr->sin_family = AF_INET;
	my_addr->sin_port = htons(puerto);
	my_addr->sin_addr.s_addr = INADDR_ANY;
	memset(my_addr->sin_zero, '\0', sizeof my_addr->sin_zero);
		
	if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("setsockopt");
		exit(1);
	}
		
	if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
		perror("Unable to bind");
		exit(1);
	}
	if (listen(*sockfd, 10) == -1) {
		perror("listen");
		exit(1);
	}
	printf("\nTCPServer Waiting for client on port %d\n",puerto);
	fflush(stdout);
}
int main(int argc, char *argv[])
{
	time_t t;
	struct tm *tm;
	fd_set master;
	fd_set read_fds;
	int fdmax, i, j=0, k=0;
	int sockfd=0;
	char *cad = malloc(BUFSIZE);
	struct sockaddr_in my_addr, client_addr;

	if(argc==2)
	{
		CONEXIONES clientes[MAX_CONN];
	
		FD_ZERO(&master);
		FD_ZERO(&read_fds);
		connect_request(&sockfd, &my_addr, atoi(argv[1]));
		FD_SET(sockfd, &master);
	
		t = time(NULL);
		tm=localtime(&t); 

		fdmax = sockfd;
		while(1){
			read_fds = master;
			if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
				perror("select");
				exit(4);
			}
		
			for (i = 0; i <= fdmax; i++){
				if (FD_ISSET(i, &read_fds)){
					if (i == sockfd)	
					{							
						clientes[j].fds=connection_accept(&master, &fdmax, sockfd, &client_addr);
						clientes[j].dir = client_addr.sin_addr;
						clientes[j].hora = tm->tm_hour;
						clientes[j].min = tm->tm_min;
						clientes[j].seg = tm->tm_sec;
						j++;					
					}
					else
					{
						for(k=0;k<j;k++)
						{
							if(clientes[k].fds == i)
							{
								sprintf(cad, "[%s]-Dice: ",inet_ntoa(clientes[k].dir));
								send_recv(i, &master, sockfd, fdmax, cad);
							}

						}					
					}
				}
			}
		}	
	return 0;
	}
	else	
	{
		printf("Número de argumentos invalido\n");
		return -1;
	}
}
		
