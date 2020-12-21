#ifndef MENU_H_
#define MENU_H_

#define STDIN_FILENO 0

#define arrow_up 259
#define arrow_down 258
#define enter 10
#define key_q 113

#include <iostream>
#include "menu.h"
#include <curses.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
#include <thread>
#include <string>

#include "server.h"
#include "client.h"

using namespace std;

/** \brief Enumerators to store the state of the menu in*/
enum CurrentScreen {homeScreen, clientScreen, serverScreen};
enum SelectionScreen{startClientItem, startServerItem, exitItem};
enum ClientScreen {joinGameItem, backItem};
enum ServerScreen {startServer, stopServer, goBack};


class Menu
{
private:


    /** \brief create TCPserver object*/
    TCPServer _tcpServer;
    /** \brief create TCPClient object*/
    TCPClient _tcpClient;

    /** \brief struct to store terminal size in*/
    struct winsize _winsize;

    /** \brief Determines whether the menu is active or not*/
    bool _menuActive = true;

    /** \brief Variables to store the state of the menu in*/
    CurrentScreen _currentScreen = homeScreen;
    SelectionScreen _selectionScreen = startClientItem;
    ClientScreen _clientScreen;
    ServerScreen _serverScreen;

public:

    /** \brief Menu constructor */
    Menu();

    /** \brief Menu destructor */
    ~Menu();

    /** \brief Creates menu */
    void create_menu();

    /** \brief Draws menu */
    void draw_menu();
    
    /** \brief Closes menu */
    void open_menu();

    /** \brief Closes menu */
    void close_menu();

    void start_server();
    void stop_server();
    void start_client();
    void stop_client();

};

#endif /* MENU */