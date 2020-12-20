#ifndef MENU_H_
#define MENU_H_

#define STDIN_FILENO 0

#include <iostream>
#include "menu.h"
#include <curses.h>

using namespace std;

/** \brief Enumerators to store the state of the menu in*/
enum CurrentScreen {home, client, server};
enum selectionScreen{selectClient, selectServer, goExit};
enum clientScreen {joinGame, back};
enum serverScreen {startServer, stopServer, goBack};


class Menu
{
private:
    /** \brief Determines whether the menu is active or not*/
    bool _menuActive = true;

    /** \brief Variables to store the state of the menu in*/
    CurrentScreen _currentScreen = home;
    selectionScreen _selectionScreen = selectClient;
    clientScreen _clientScreen;
    serverScreen _serverScreen;

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
};

#endif /* MENU */