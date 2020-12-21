#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <curses.h>
#define PORT 5555

using namespace std;

class TCPServer
{
private:

	bool serverON = false;

public:

	TCPServer();
	~TCPServer();
	void start_server();
	void stop_server();

};

#endif
