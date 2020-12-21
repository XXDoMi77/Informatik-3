#include "menu.h"

    int key_temp = 0;

    Menu::Menu()
    {
        //set correct settings for ncurses input 
        initscr(); //initializes ncurses (input for arrow keys)
        start_color(); //starts color conponent of curses
        curs_set(0); //disables showing cursor
        clear(); //souldn't be neccessary because initscreen does it already
        noecho(); //idk what it does so I just commented it out
        cbreak(); // Line buffering disabled. pass on everything
        refresh(); //if not present cout won't output until first input
        timeout(30); //set timeout for input
        keypad(stdscr, TRUE); //set ncurses input mode to arrow navigation...

        //set color theme
        init_pair(1, COLOR_WHITE, COLOR_BLUE); //Selection color pair
        init_pair(2, COLOR_WHITE, COLOR_BLACK); //Unselected color pair
    }

    void start_server()
    {
        /** \brief create TCPserver object*/
        TCPserver _srv(5555, 25);
        /** \brief start the server on a new thread so that it runs concurrently*/
        thread server(&TCPserver::run, &_srv);
        server.detach();
    }

    void Menu::create_menu()
    {
        //create key variable to store pressed key in
        int key = 1;

        while (_menuActive)
        {
            // flushinp(); //flush ncurses input buffer before getting input
            key = getch();
            key == -1 ? 1 : key_temp = key;
            switch (key)
            {
                case arrow_up:
                    switch (_currentScreen)
                    {
                        case homeScreen:
                            switch (_selectionScreen)
                            {
                                case startClientItem:
                                    _selectionScreen = exitItem;
                                    break;
                                case startServerItem:
                                    _selectionScreen = startClientItem;
                                    break;
                                case exitItem:
                                    _selectionScreen = startServerItem;
                                    break;
                            }
                        case clientScreen:
                            switch (_clientScreen)
                            {
                                case joinGameItem:
                                    _clientScreen = backItem;
                                    break;
                                case backItem:
                                    _clientScreen = joinGameItem;
                                    break;
                            }
                            break;
                        case serverScreen:
                            switch (_serverScreen)
                            {
                                case startServer:
                                    _serverScreen = goBack;
                                    break;
                                case stopServer:
                                    _serverScreen = startServer;
                                    break;
                                case goBack:
                                    _serverScreen = stopServer;
                                    break;
                            }
                            break;
                    }
                    break;
                case arrow_down:
                    switch (_currentScreen)
                    {
                        case homeScreen:
                            switch (_selectionScreen)
                            {
                                case startClientItem:
                                    _selectionScreen = startServerItem;
                                    break;
                                case startServerItem:
                                    _selectionScreen = exitItem;
                                    break;
                                case exitItem:
                                    _selectionScreen = startClientItem;
                                    break;
                            }
                        case clientScreen:
                            switch (_clientScreen)
                            {
                                case joinGameItem:
                                    _clientScreen = backItem;
                                    break;
                                case backItem:
                                    _clientScreen = joinGameItem;
                                    break;
                            }
                            break;
                        case serverScreen:
                            switch (_serverScreen)
                            {
                                case startServer:
                                    _serverScreen = stopServer;
                                    break;
                                case stopServer:
                                    _serverScreen = goBack;
                                    break;
                                case goBack:
                                    _serverScreen = startServer;
                                    break;
                            }
                            break;
                    }
                    break;
                case enter:
                    switch (_currentScreen)
                    {
                        case homeScreen:
                            switch (_selectionScreen)
                            {
                                case startServerItem:
                                    _currentScreen = serverScreen;
                                    start_server();
                                    break;
                                case exitItem:
                                    exit(1);
                                    break;
                            }
                            break;
                    }
                    break;
                case key_q:
                    switch (_currentScreen)
                    {
                        case serverScreen:
                            //stop the server and go back to homeScreen, still needs implementation...
                            break;
                    }
                    break;
            }
            draw_menu();
        }
    }

    void Menu::draw_menu()
    {
        //get size of terminal width and height and store it in _winsize...
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize);

        //clear the screen
        clear();

        //draw width, height and pressed button id information in the upper left corner
        attron(COLOR_PAIR(2)); //set text output color pair, which are defined further up...
        printw("key_id: %d\nx: %d\ny: %d", key_temp, _winsize.ws_col, _winsize.ws_row);

        //drawing screen
        switch (_currentScreen)
        {
            case homeScreen:
                attron(COLOR_PAIR(2)); //set text output color pair, which are defined further up...
                _selectionScreen == startClientItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2-2, _winsize.ws_col/2-6);
                printw("Start Client\n");
                _selectionScreen == startServerItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2-1, _winsize.ws_col/2-6);
                printw("Start Server\n");
                _selectionScreen == exitItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2, _winsize.ws_col/2-2);
                printw("Exit\n");
                break;
            case serverScreen:
                attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2-2, _winsize.ws_col/2-22);
                printw("Server is running, to stop server press <Q>\n");
                break;
            case clientScreen:
                /* code */
                break;
        }
    }

    void Menu::open_menu()
    {
        _menuActive = true;
    }

    void Menu::close_menu()
    {
        _menuActive = false;
    }
    
