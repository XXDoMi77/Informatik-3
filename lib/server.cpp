#include "server.h"

using namespace std;

TCPServer::TCPServer()
{
}

TCPServer::~TCPServer()
{
}

void TCPServer::start_server()
{
	serverON = true;
	clear();
    scrollok(stdscr,TRUE);
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char asd [32] = "asdasdasd";
	char *hello = asd;
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	
	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	while (serverON)
	{
		for (int i = 0; i < 16; i++)
		{
			asd[i] = rand();
		}
		valread = read( new_socket , buffer, 1024);
		printw("%s\n",buffer );
		send(new_socket , hello , strlen(hello) , 0 );
		usleep(1500000);
		// printw("Hello message sent\n");
	}
}

void TCPServer::stop_server()
{
	serverON = false;
}