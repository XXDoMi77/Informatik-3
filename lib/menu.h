/*
 * MENU.H
 *
 *  Created on: 
 *      Author: 
 */

/**
 *
 * \file menu.h
 *
 * \brief Contains code for Menuscreen
 * 
 *
 */

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
#include <ctype.h> //to check if character is number, letter or punctuation
#include "algorithm_1.h"
#include "algorithm_2.h"

using namespace std;

/** \brief Enumerators to store the state of the menu in*/

/**
 *
 * \enum CurrentScreen
 *
 *  Represents the states the userscreen can have.
 *
 */

enum CurrentScreen {homeScreen, /**<    */
                    clientScreen, /**<    */
                    serverScreen, /**<    */
                    playScreen /**<    */
                    };

/**
 *
 * \enum SelectionScreen
 *
 *  Represents the states the SelectionScreen can have.
 *
 */

enum SelectionScreen{startClientItem, /**<    */
                    startServerItem, /**<    */
                    exitItem /**<    */
                    };

/**
 *
 * \enum ClientScreen
 *
 *  Represents the states the ClientScreen can have.
 *
 */

enum ClientScreen   {playManuallyItem, /**<    */
                    startAlgorithmOneItem, /**<    */
                    startAlgorithmTwoItem, /**<    */
                    backItem /**<    */
                    };

/**
 *
 * \enum ServerScreen
 *
 *  Represents the states the ServerScreen can have.
 *
 */

enum ServerScreen   {startServer, /**<    */
                    stopServer, /**<    */
                    goBack /**<    */
                    };

/** 
 * 
 * \class Menu
 * 
 * \brief This class represents the Menu and its possibility of choices
*/

class Menu
{
private:

    // int _bufferSize = 25;
    // int _numberOfServers = 10;
    const string _host = "localhost";
    TCPserver* _tcpServer[10];
    thread* _serverThread[10];
    TCPclient* _tcpClient;
    thread* _clientThread;
    Algorithm_1* _algorithm_1;
    thread* _algo1Thread;
    Algorithm_2* _algorithm_2;
    thread* _algo2Thread;

    /** \brief struct to store terminal size in*/
    struct winsize _winsize;

    /** \brief Determines whether the menu is active or not*/
    bool _menuActive = true;

    /** \brief Variables to store the state of the menu in*/
    CurrentScreen _currentScreen = homeScreen;
    SelectionScreen _selectionScreen = startClientItem;
    ClientScreen _clientScreen = playManuallyItem;
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
    
    /** \brief Opens menu */
    void open_menu();

    /** \brief Closes menu */
    void close_menu();

    /** \brief Starts server */
    void start_server();
    // void stop_server();

    /** \brief Starts client */
    void start_client();
    // void stop_client();

    /** \brief Get ip adress from user */
    int get_port_from_user();

};

#endif /* MENU_H */