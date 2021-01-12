#include "algorithm_1.h"

Algorithm_1::Algorithm_1()
{
    _counter = new Counter;
}

Algorithm_1::~Algorithm_1()
{
    //_TCPclient->sendData("BYEBYE");
}

void Algorithm_1::run(TCPclient* _TCPclient)
{
    bool gameWon = false;
    char* msg = new char[25];
    string receivedMsg;
    int tmpX;
    int tmpY;
    reset:
    gameWon = false;
    _counter->next_game();
    for (int i = 0; i <= 25; i++)
    {
        msg[i] = '_';
    }
    receivedMsg = "_________________________";
    tmpX = 1;
    tmpY = 1;

    while (!gameWon)
    {
        sprintf(msg, "shoot(%02d;%02d)", tmpX, tmpY);

        _TCPclient->sendData(msg);

        receivedMsg = _TCPclient->receive(25);

        if (receivedMsg[0] == '~')
        {
            _board.set_block(tmpX, tmpY, water);
        }
        else if(receivedMsg[0] == 'x')
        {
            _board.set_block(tmpX, tmpY, shipHit);
        }
        else if(receivedMsg[0] == 'f')
        {
            gameWon = true;
        }
        
        if (tmpX <= 10)
        {
            tmpX++;
        }
        if (tmpX == 11)
        {
            tmpX = 1;
        }
        if (tmpY <= 10 && tmpX == 1)
        {
            if(tmpY != 10)
            {
                tmpY++;
            }
        }
        _counter->add_move();
        usleep(1000);
    }
    _board.set_block(tmpX-1, tmpY, shipHit);
    _board.fill_not_yet_known_with(water);
    usleep(100000);
    _TCPclient->sendData("new_game");
    receivedMsg = _TCPclient->receive(25);
    _board.reset_board();
    usleep(100000);
    goto reset;
}

Board Algorithm_1::get_board()
{
    return _board;
}

int Algorithm_1::get_move_count()
{
    return _counter->get_moves();
}

float Algorithm_1::get_avarage_move()
{
    return _counter->get_avarage();
}

int Algorithm_1::get_game_id()
{
    return _counter->get_game_id();
}
