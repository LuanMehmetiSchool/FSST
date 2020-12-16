/*
author: Luan Mehmeti
version: 1.0
name: tcp_echo
description:
Client should send databits to the server and the server should send them back.
For the programm POSIX calls should be used.
*/




#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "rle.c"

#define PORT 60400
#define BACKLOG 50
#define BUFFER 256

int main(){

	char *buffer = malloc(BUFFER);
	if(buffer==NULL){
		perror("Allocate buffer");
		exit("EXIT_FAILURE");
	}

	// define socket
	int sfd = socket(AF_INET, SOCK_STREAM,0);

	if(sfd == -1){
		perror("Something went wrong with the creation of the socket...");
		exit("EXIT_FAILURE");
	}

	// creating sockadress structure
	struct sockaddr_in srv_addr;
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(PORT);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int bfd = bind(sfd, (struct sockadr *)&srv_addr, sizeof(struct sockaddr));

	if(bfd == -1){
		close(sfd);
		perror("The binding failed");
		exit("EXIT_FAILURE");
	}
	
	int lfd = listen(sfd, BACKLOG);

	if(lfd == -1){
		close(sfd);
		perror("The listening failed");
		exit("EXIT_FAILUR");
	}
	
	// accepting incoming connections
	struct sockaddr_in peer_addr;
	socklen_t addrlen = sizeof(struct sockaddr);
	int cfd = accept(sfd, (struct sockaddr *)&peer_addr, &addrlen);
	
	// echo
	ssize_t recv_status;
	for(;;){
		// clearing buffer
		bzero(buffer, 256);

		// recieving
		recv_status = recv(cfd, buffer, 256,0);

		if(recv_status = 0){
			break;
		}else if(recv_status < 0){
			close(sfd);
			free(buffer);
			exit(EXIT_FAILURE);
		}

		
		// rle-encoding message
		buffer[strlen(buffer) - 1] = '\0';
		buffer = encode(buffer);
		
		//sending answer
		if (send(cfd, buffer, strlen(buffer), 0) < 0 ){
			continue;
		}
	}
	// close socket
	close(sfd);
	free(buffer);
	return 0;

}
