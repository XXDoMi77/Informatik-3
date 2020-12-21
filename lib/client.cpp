#include "client.h"

TCPClient::TCPClient(/* args */)
{
}

TCPClient::~TCPClient()
{
}

void TCPClient::start_client()
{
    clear();
    scrollok(stdscr,TRUE);
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printw("\n Socket creation error \n");
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printw("\nInvalid address/ Address not supported \n");
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printw("\nConnection Failed \n");
    }

    while (1)
    {
        send(sock , hello , strlen(hello) , 0 );
        // printw("Hello message sent\n");
        valread = read( sock , buffer, 1024);
		usleep(1500000);
        printw("%s\n",buffer );
    }
}
