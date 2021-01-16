#include "algorithm_1.h"

Algorithm_1::Algorithm_1()
{
    _counter = new Counter;
}

Algorithm_1::~Algorithm_1()
{
    //_TCPclient->sendData("BYEBYE");
}

void Algorithm_1::run(TCPclient *_TCPclient)
{
    bool shouldPlay = true;
    bool boardFinished = false;
    char msg[glset::bufferSize];
    char receivedMsg[glset::bufferSize];
    int tmpX;
    int tmpY;
    while (shouldPlay)
    {
        if (_counter->get_game_id() <= glset::maxGamesPlayed - 1)
        {
            boardFinished = false;

            if (glset::delayOn)
                usleep(glset::delay);
            _TCPclient->sendData("new_game");
            string tmp = _TCPclient->receive(glset::bufferSize);
            for (int i = 0; i <= glset::bufferSize; i++)
            {
                receivedMsg[i] = tmp[i];
            }
            _board.reset_board();
            if (glset::delayOn)
                usleep(glset::delay);
        }
        else
        {
            break;
        }
        _counter->next_game();
        for (int i = 0; i <= glset::bufferSize; i++)
        {
            msg[i] = '_';
        }
        for (int i = 0; i <= glset::bufferSize; i++)
        {
            receivedMsg[i] = '_';
        }
        tmpX = 1;
        tmpY = 1;

        while (!boardFinished)
        {
            if (glset::delayOn)
                usleep(glset::delay);

            sprintf(msg, "shoot(%02d;%02d)", tmpX, tmpY);

            _TCPclient->sendData(msg);

            string tmp = _TCPclient->receive(glset::bufferSize);
            for (int i = 0; i <= glset::bufferSize; i++)
            {
                receivedMsg[i] = tmp[i];
            }

            if (receivedMsg[0] == '~')
            {
                _board.set_block(tmpX, tmpY, water);
            }
            else if (receivedMsg[0] == 'x')
            {
                _board.set_block(tmpX, tmpY, shipHit);
            }
            else if (receivedMsg[0] == 'f')
            {
                boardFinished = true;
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
                if (tmpY != 10)
                {
                    tmpY++;
                }
            }
            _counter->add_move();
        }
        _board.set_block(tmpX - 1, tmpY, shipHit);
        _board.fill_not_yet_known_with(water);
    }
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
