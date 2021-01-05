#ifndef MENU_H_
#define MENU_H_

#define STDIN_FILENO 0

#define arrowUp 259
#define arrowDown 258
#define enter 10
#define keyQ 113

#include <curses.h> //library we use for our menu
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> //for STDOUT_FILENO
#include <thread> //each thread can only contain a single while loop
#include <string>
#include "simplesocket.h"

using namespace std;

/** \brief Enumerators to store the state of the menu in*/
enum CurrentScreen {homeScreen, clientScreen, serverScreen};
enum SelectionScreen{startClientItem, startServerItem, exitItem};
enum ClientScreen {joinGameItem, backItem};
enum ServerScreen {startServer, stopServer, goBack};

class Menu
{
private:

    // int _bufferSize = 25;
    // int _numberOfServers = 10;
    TCPserver* _tcpServer[10];
    thread* _serverThread[10];

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
    // ~Menu();

    /** \brief Creates menu */
    void create_menu();

    /** \brief Draws menu */
    void draw_menu();
    
    /** \brief Closes menu */
    void open_menu();

    /** \brief Closes menu */
    void close_menu();

    void start_server();
    // void stop_server();

    void start_client();
    // void stop_client();

};

#endif /* MENU */