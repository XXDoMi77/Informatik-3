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

#include <curses.h>    //library we use for our menu
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>    //for STDOUT_FILENO
#include <thread>      //each thread can only contain a single while loop
#include <string>
#include "simplesocket.h"
#include <ctype.h> //to check if character is number, letter or punctuation
#include "algorithm_1.h"
#include "algorithm_2.h"
#include "settings.h"

using namespace std;

/** \brief Enumerators to store the state of the menu in*/

/**
 *
 * \enum CurrentScreen
 *
 *  Represents the states the userscreen can have.
 *
 */

enum CurrentScreen
{
    homeScreen,   /**<    */
    clientScreen, /**<    */
    serverScreen, /**<    */
    playScreen    /**<    */
};

/**
 *
 * \enum SelectionScreen
 *
 *  Represents the states the SelectionScreen can have.
 *
 */

enum SelectionScreen
{
    startClientItem, /**<    */
    startServerItem, /**<    */
    exitItem         /**<    */
};

/**
 *
 * \enum ClientScreen
 *
 *  Represents the states the ClientScreen can have.
 *
 */

enum ClientScreen
{
    playManuallyItem,      /**<    */
    startAlgorithmOneItem, /**<    */
    startAlgorithmTwoItem, /**<    */
    backItem               /**<    */
};

/**
 *
 * \enum ServerScreen
 *
 *  Represents the states the ServerScreen can have.
 *
 */

enum ServerScreen
{
    startServer, /**<    */
    stopServer,  /**<    */
    goBack       /**<    */
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
    TCPserver *_tcpServer[10];
    thread *_serverThread[10];
    TCPclient *_tcpClient;
    thread *_clientThread;
    Algorithm_1 *_algorithm_1;
    thread *_algo1Thread;
    Algorithm_2 *_algorithm_2;
    thread *_algo2Thread;

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
    /** \brief Sets some settings for ncurses everything is commented within the code, see yourself... */
    Menu();

    /** \brief Menu destructor, currently does nothing */
    // ~Menu();

    /** \brief Starts the menu and runs a while(1) loop for navigations,
     * it scans for keypresses and takes action based on that. It is responsible
     * for menu navigation
    */
    void create_menu();

    /** \brief Draws/renders the whole menu, everything from the menu options
     * through the server screen, to the client screen. Everything is drawn in here except
     * the port selection screen that has it's own function/method... 
     */
    void draw_menu();

    /** \brief Starts to draw the menu */
    void open_menu();

    /** \brief Stops drawing/rendering the menu*/
    void close_menu();

    /** \brief Starts servers (in this case 10 servers on ports starting at the number set in settings.h)
     * Every server is run on a new thread for maximal performance. This way it takes advantage of multiple
     * cores/ processors...
     */
    void start_server();

    /** \brief It should stop the server, but currently not correctly implemented, so the program 
     * just errors out if you try to pause the game with the key set in settings.h
     */
    void stop_server();

    /** \brief Starts client connection at a specific port defined by the function get_port_from_user() */
    void start_client();

    /** \brief It should stop the client, but currently not correctly implemented, so the program 
     * just goes back to the menu (if you press the button specified in settings.h), but doesn't stop the running client thread
     */
    void stop_client();

    /** \brief Get ip adress from user, user navigates with up and down arrows*/
    int get_port_from_user();
};

#endif /* MENU_H */
