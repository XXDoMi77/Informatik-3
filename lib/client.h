#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <cstdlib>
#include <ctime>
#define PORT 5555 

using namespace std;

class TCPClient
{
private:
    /* data */
public:
    TCPClient(/* args */);
    ~TCPClient();
    void start_client();
};

#endif
