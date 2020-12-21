#include "menu.h"

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
        timeout(30);
        keypad(stdscr, TRUE); //set ncurses input mode to arrow navigation...

        //set color theme
        init_pair(1, COLOR_WHITE, COLOR_RED); //color pair 2
        init_pair(2, COLOR_WHITE, COLOR_BLACK); //color pair 1
    }


    void _redraw_periodically()
    {
        
    }

    void Menu::create_menu()
    {
        //get size of terminal width and height and store it in _winsize...
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize);

        //create key variable to store pressed key in
        int key = 1;

        //draw menu for the first time
        draw_menu();

        while (_menuActive)
        {
            // flushinp(); //flush ncurses input buffer before getting input
            key = getch();
            switch (key)
            {
                case 259:
                    switch (_currentScreen)
                    {
                        case home:
                            switch (_selectionScreen)
                            {
                                case selectClient:
                                    _selectionScreen = goExit;
                                    break;
                                case selectServer:
                                    _selectionScreen = selectClient;
                                    break;
                                case goExit:
                                    _selectionScreen = selectServer;
                                    break;
                            }
                        case client:
                            switch (_clientScreen)
                            {
                                case joinGame:
                                    _clientScreen = back;
                                    break;
                                case back:
                                    _clientScreen = joinGame;
                                    break;
                            }
                            break;
                        case server:
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
                case 258:
                    switch (_currentScreen)
                    {
                        case home:
                            switch (_selectionScreen)
                            {
                                case selectClient:
                                    _selectionScreen = selectServer;
                                    break;
                                case selectServer:
                                    _selectionScreen = goExit;
                                    break;
                                case goExit:
                                    _selectionScreen = selectClient;
                                    break;
                            }
                        case client:
                            switch (_clientScreen)
                            {
                                case joinGame:
                                    _clientScreen = back;
                                    break;
                                case back:
                                    _clientScreen = joinGame;
                                    break;
                            }
                            break;
                        case server:
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
                case 10:
                    switch (_selectionScreen)
                    {
                        case goExit:
                            exit(1);
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

        clear();
        switch (_currentScreen)
        {
            case home:
                attron(COLOR_PAIR(2));
                printw("x: %d y: %d\n", _winsize.ws_col, _winsize.ws_row);
                _selectionScreen == selectClient ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2-2, _winsize.ws_col/2-6);
                printw("Start Client\n");
                _selectionScreen == selectServer ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2-1, _winsize.ws_col/2-6);
                printw("Start Server\n");
                _selectionScreen == goExit ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
                move(_winsize.ws_row/2, _winsize.ws_col/2-2);
                printw("Exit\n");
                break;
            case server:
                /* code */
                break;
            case client:
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
    
