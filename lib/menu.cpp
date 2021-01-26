#include "menu.h"

int key_temp = 0;

Menu::Menu()
{
    //set correct settings for ncurses input
    initscr();                      //initializes ncurses (input for arrow keys)
    start_color();                  //starts color conponent of curses
    curs_set(0);                    //disables showing cursor
    clear();                        //souldn't be neccessary because initscreen does it already
    noecho();                       //idk what it does
    cbreak();                       // Line buffering disabled. pass on everything
    refresh();                      //if not present cout won't output until first input
    timeout(glset::minRefreshRate); //set timeout for input
    keypad(stdscr, TRUE);           //set ncurses input mode to arrow navigation...
    resizeterm(400, 400);           //set the size of ncurses window

    //set color theme
    init_pair(1, COLOR_WHITE, COLOR_BLUE);  //Selection color pair
    init_pair(2, COLOR_WHITE, COLOR_BLACK); //Unselected color pair
}

void Menu::start_server()
{
    int port = glset::startingPort;
    int bufferSize = glset::bufferSize;

    /** \brief create TCPserver object*/
    for (int i = 0; i < 10; i++)
    {
        _tcpServer[i] = new TCPserver(port++, bufferSize);
        _serverThread[i] = new thread(&TCPserver::run, ref(_tcpServer[i]));
        _serverThread[i]->detach(); //starts parallel thread
    }
}

void Menu::stop_server()
{
    for (int i = 0; i < 10; i++)
    {
        delete (_serverThread[i]);
        _tcpServer[i]->~TCPserver();
        delete (_tcpServer[i]);
    }

    // _serverThread->join();

    // _serverThread[id]->~thread();
    // delete [] _serverThread;
}

void Menu::start_client()
{
    string msg;
    _tcpClient = new TCPclient;
    _clientThread = new thread(&TCPclient::conn, ref(_tcpClient), "localhost", get_port_from_user());
    _clientThread->detach();
}

// void Menu::stop_client()
// {
//     // _tcpServer.stop_server();
// }

void Menu::create_menu()
{
    //create key variable to store pressed key in
    int key = 1;

    while (1)
    {
        // flushinp(); //flush ncurses input buffer before getting input
        key = getch();
        key == -1 ? 1 : key_temp = key; //some keys cause issues, this should fix it
        switch (key)
        {
        case glset::keyArrowUp:
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
                break;
            case clientScreen:
                switch (_clientScreen)
                {
                case playManuallyItem:
                    _clientScreen = backItem;
                    break;
                case startAlgorithmOneItem:
                    _clientScreen = playManuallyItem;
                    break;
                case startAlgorithmTwoItem:
                    _clientScreen = startAlgorithmOneItem;
                    break;
                case backItem:
                    _clientScreen = startAlgorithmTwoItem;
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
        case glset::keyArrowDown:
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
                break;
            case clientScreen:
                switch (_clientScreen)
                {
                case playManuallyItem:
                    _clientScreen = startAlgorithmOneItem;
                    break;
                case startAlgorithmOneItem:
                    _clientScreen = startAlgorithmTwoItem;
                    break;
                case startAlgorithmTwoItem:
                    _clientScreen = backItem;
                    break;
                case backItem:
                    _clientScreen = playManuallyItem;
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
        case glset::keyEnter:
            switch (_currentScreen)
            {
            case homeScreen:
                switch (_selectionScreen)
                {
                case startClientItem:
                    close_menu();
                    _clientScreen = playManuallyItem;
                    _currentScreen = clientScreen;
                    start_client();
                    open_menu();
                    break;
                case startServerItem:
                    _currentScreen = serverScreen;
                    start_server();
                    break;
                case exitItem:
                    exit(1);
                    break;
                }
                break;
            case clientScreen:
                switch (_clientScreen)
                {
                case playManuallyItem:
                    _tcpClient->sendData("asd");
                    break;
                case startAlgorithmOneItem:
                    _currentScreen = playScreen;
                    _algorithm_1 = new Algorithm_1;
                    _algo1Thread = new thread(&Algorithm_1::run, ref(_algorithm_1), ref(_tcpClient));
                    _algo1Thread->detach();
                    break;
                case startAlgorithmTwoItem:
                    _currentScreen = playScreen;
                    _algorithm_2 = new Algorithm_2;
                    _algo1Thread = new thread(&Algorithm_2::run, ref(_algorithm_2), ref(_tcpClient));
                    _algo1Thread->detach();
                    break;
                case backItem:
                    _tcpClient->sendData("BYEBYE");
                    delete (_tcpClient);
                    delete (_clientThread);
                    _currentScreen = homeScreen;
                    break;
                }
                break;
            }
            break;
        case glset::keyQ:
            switch (_currentScreen)
            {
            case clientScreen:
                // stop_client();
                open_menu();
                _currentScreen = homeScreen;
                //stop the server and go back to homeScreen, still needs implementation...
                break;
            case serverScreen:
                stop_server();
                open_menu();
                _currentScreen = homeScreen;
                //stop the server and go back to homeScreen, still needs implementation...
                break;
            }
            break;
        }
        if (_menuActive)
        {
            draw_menu();
        }
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
        _selectionScreen == startClientItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2 - 2, _winsize.ws_col / 2 - 6);
        printw("Start Client\n");
        _selectionScreen == startServerItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2 - 1, _winsize.ws_col / 2 - 6);
        printw("Start Server\n");
        _selectionScreen == exitItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2, _winsize.ws_col / 2 - 2);
        printw("Exit\n");
        break;
    case serverScreen:
        attron(COLOR_PAIR(2));

        move(5, 1);
        for (int i = 0; i < 10; i++)
        {
            char tmp[glset::bufferSize];
            for (int a = 0; a < glset::bufferSize; a++)
            {
                tmp[a] = _tcpServer[i]->get_latest_inc_msg()[a];
            }

            printw("\nServer %d\tport: %d\tincoming message: %s\n", i, _tcpServer[i]->get_port(), tmp);
        }

        //     printw("Server is running, to stop server press <Q>\n");
        //     break;
        // case clientScreen:
        //     attron(COLOR_PAIR(2));
        //     move(_winsize.ws_row/2-2, _winsize.ws_col/2-22);
        //     printw("Client is running, to stop client press <Q>\n");
        break;
    case clientScreen:
        _clientScreen == playManuallyItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2 - 3, _winsize.ws_col / 2 - 9);
        printw("Play game manually\n");
        _clientScreen == startAlgorithmOneItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2 - 2, _winsize.ws_col / 2 - 9);
        printw("Start algorithm 1\n");
        _clientScreen == startAlgorithmTwoItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2 - 1, _winsize.ws_col / 2 - 9);
        printw("Start algorithm 2\n");
        _clientScreen == backItem ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
        move(_winsize.ws_row / 2, _winsize.ws_col / 2 - 2);
        printw("Back\n");
        break;
    case playScreen:
        switch (_clientScreen)
        {
        case startAlgorithmOneItem:
            attron(COLOR_PAIR(2));
            move(0, _winsize.ws_col / 2 - 5);
            printw("Algorithm 1");
            move(0, _winsize.ws_col - 14);
            printw("less efficient");
            //draw board of client
            for (int a = 1; a <= 10; a++)
            {
                move(_winsize.ws_row / 2 - 7 + a, _winsize.ws_col / 2 - 5);
                for (int i = 1; i <= 10; i++)
                {
                    if (_algorithm_1->get_board().get_block_state(i, a) == water)
                    {
                        printw("~");
                    }
                    else if (_algorithm_1->get_board().get_block_state(i, a) == shipHit)
                    {
                        printw("x");
                    }
                    else if (_algorithm_1->get_board().get_block_state(i, a) == notYetKnown)
                    {
                        printw("o");
                    }
                }
            }
            move(_winsize.ws_row / 2 + 5, _winsize.ws_col / 2 - 7);
            printw("Played:   %02d", _algorithm_1->get_game_id());
            move(_winsize.ws_row / 2 + 6, _winsize.ws_col / 2 - 7);
            printw("Moves:    %02d", _algorithm_1->get_move_count());
            move(_winsize.ws_row / 2 + 7, _winsize.ws_col / 2 - 7);
            printw("Average:  %.2f", _algorithm_1->get_avarage_move());
            break;
        case startAlgorithmTwoItem:
            attron(COLOR_PAIR(2));
            move(0, _winsize.ws_col / 2 - 5);
            printw("Algorithm 2");
            move(0, _winsize.ws_col - 14);
            printw("more efficient");
            //draw board of client
            for (int a = 1; a <= 10; a++)
            {
                move(_winsize.ws_row / 2 - 7 + a, _winsize.ws_col / 2 - 5);
                for (int i = 1; i <= 10; i++)
                {
                    if (_algorithm_2->get_board().get_block_state(i, a) == water)
                    {
                        printw("~");
                    }
                    else if (_algorithm_2->get_board().get_block_state(i, a) == shipHit)
                    {
                        printw("x");
                    }
                    else if (_algorithm_2->get_board().get_block_state(i, a) == notYetKnown)
                    {
                        printw("o");
                    }
                }
            }
            move(_winsize.ws_row / 2 + 5, _winsize.ws_col / 2 - 7);
            printw("Played:   %02d", _algorithm_2->get_game_id());
            move(_winsize.ws_row / 2 + 6, _winsize.ws_col / 2 - 7);
            printw("Moves:    %02d", _algorithm_2->get_move_count());
            move(_winsize.ws_row / 2 + 7, _winsize.ws_col / 2 - 7);
            printw("Average:  %.2f", _algorithm_2->get_avarage_move());
            break;
        }
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

int Menu::get_port_from_user()
{
    //"255.255.255.255" as string
    //"7777" as int
    int port = 7777;
    //set color
    attron(COLOR_PAIR(2));
    //create variable to store keystroke in
    int inputTmp = 0;
    //check if enter has been pressed
    while (inputTmp != glset::keyEnter)
    {
        //get input from user
        inputTmp = getch();
        //clear screen
        clear();
        //move cursor
        move(_winsize.ws_row / 2 - 2, _winsize.ws_col / 2 - 11);
        //set text output color pair, which are defined further up...
        printw("Please enter port: ");
        //get size of terminal width and height and store it in _winsize...
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize);
        switch (inputTmp)
        {
        case glset::keyArrowUp:
            port++;
            break;
        case glset::keyArrowDown:
            port--;
            break;
        }
        printw("%d", port);
        move(_winsize.ws_row / 2, _winsize.ws_col / 2 - int(67 / 2));
        printw("Use your arrow keys to cycle between numbers, to select press Enter");
    }

    // flushinp();
    // nocbreak();
    // echo();
    // noraw();
    // mvgetstr(10, 10, tmp);
    // scanw("%d",&tmp);
    // return strtol(tmp, nullptr, 10);
    return port;
}
