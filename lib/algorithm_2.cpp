#include "algorithm_2.h"

Algorithm_2::Algorithm_2()
{
    _counter = new Counter;
}

Algorithm_2::~Algorithm_2()
{
    //_TCPclient->sendData("BYEBYE");
}

void Algorithm_2::run(TCPclient *_TCPclient)
{
    srand(time(NULL));

    bool shouldPlay = true;
    bool boardFinished = false;
    char msg[glset::bufferSize];
    char receivedMsg[glset::bufferSize];
    int tmpX = 0;
    int tmpY = 0;
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
        bool hit = false;
        tmpX = rand() % 10 + 1;
        tmpY = rand() % 10 + 1;
        int tmpZ = 0;

        // tmpX = int(9/RAND_MAX*rand())+1;
        // tmpY = int(9/RAND_MAX*rand())+1;

        while (!boardFinished)
        {
            while (!hit)
            {
                tmpX = rand() % 10 + 1;
                tmpY = rand() % 10 + 1;

                if (_board.get_block_state(tmpX, tmpY) == notYetKnown)
                {
                    if (glset::delayOn)
                        usleep(glset::delay);
                    sprintf(msg, "shoot(%02d;%02d)", tmpX, tmpY);

                    _TCPclient->sendData(msg);
                    _counter->add_move();

                    string tmp = _TCPclient->receive(glset::bufferSize);
                    for (int i = 0; i <= glset::bufferSize; i++)
                    {
                        receivedMsg[i] = tmp[i];
                    }

                    if (receivedMsg[0] == '~')
                    {
                        hit = false;
                        _board.set_block(tmpX, tmpY, water);
                    }
                    else if (receivedMsg[0] == 'x')
                    {
                        hit = true;
                        _board.set_block(tmpX, tmpY, shipHit);
                    }
                    else if (receivedMsg[0] == 'f')
                    {
                        hit = true;
                        boardFinished = true;
                    }
                }
            }
            for (tmpZ = tmpX + 1; tmpZ <= 10; tmpZ++)
            {
                if (_board.get_block_state(tmpZ, tmpY) == notYetKnown)
                {

                    if (glset::delayOn)
                        usleep(glset::delay);
                    sprintf(msg, "shoot(%02d;%02d)", tmpZ, tmpY);

                    _TCPclient->sendData(msg);
                    _counter->add_move();

                    string tmp = _TCPclient->receive(glset::bufferSize);
                    for (int i = 0; i <= glset::bufferSize; i++)
                    {
                        receivedMsg[i] = tmp[i];
                    }

                    if (receivedMsg[0] == '~')
                    {
                        _board.set_block(tmpZ, tmpY, water);
                        tmpZ = 11;
                    }
                    else if (receivedMsg[0] == 'x')
                    {
                        hit = true;
                        _board.set_block(tmpZ, tmpY, shipHit);
                    }
                    else if (receivedMsg[0] == 'f')
                    {
                        hit = true;
                        boardFinished = true;
                    }
                }
            }
            for (tmpZ = tmpX - 1; tmpZ >= 1; tmpZ--)
            {
                if (_board.get_block_state(tmpZ, tmpY) == notYetKnown)
                {
                    if (glset::delayOn)
                        usleep(glset::delay);
                    sprintf(msg, "shoot(%02d;%02d)", tmpZ, tmpY);

                    _TCPclient->sendData(msg);
                    _counter->add_move();

                    string tmp = _TCPclient->receive(glset::bufferSize);
                    for (int i = 0; i <= glset::bufferSize; i++)
                    {
                        receivedMsg[i] = tmp[i];
                    }

                    if (receivedMsg[0] == '~')
                    {
                        _board.set_block(tmpZ, tmpY, water);
                        tmpZ = 0;
                    }
                    else if (receivedMsg[0] == 'x')
                    {
                        hit = true;
                        _board.set_block(tmpZ, tmpY, shipHit);
                    }
                    else if (receivedMsg[0] == 'f')
                    {
                        hit = true;
                        boardFinished = true;
                    }
                }
            }
            for (tmpZ = tmpY + 1; tmpZ <= 10; tmpZ++)
            {
                if (_board.get_block_state(tmpX, tmpZ) == notYetKnown)
                {
                    if (glset::delayOn)
                        usleep(glset::delay);
                    sprintf(msg, "shoot(%02d;%02d)", tmpX, tmpZ);

                    _TCPclient->sendData(msg);
                    _counter->add_move();

                    string tmp = _TCPclient->receive(glset::bufferSize);
                    for (int i = 0; i <= glset::bufferSize; i++)
                    {
                        receivedMsg[i] = tmp[i];
                    }

                    if (receivedMsg[0] == '~')
                    {
                        _board.set_block(tmpX, tmpZ, water);
                        tmpZ = 11;
                    }
                    else if (receivedMsg[0] == 'x')
                    {
                        hit = true;
                        _board.set_block(tmpX, tmpZ, shipHit);
                    }
                    else if (receivedMsg[0] == 'f')
                    {
                        hit = true;
                        boardFinished = true;
                    }
                }
            }
            for (tmpZ = tmpY - 1; tmpZ >= 1; tmpZ--)
            {
                if (_board.get_block_state(tmpX, tmpZ) == notYetKnown)
                {
                    if (glset::delayOn)
                        usleep(glset::delay);
                    sprintf(msg, "shoot(%02d;%02d)", tmpX, tmpZ);

                    _TCPclient->sendData(msg);
                    _counter->add_move();

                    string tmp = _TCPclient->receive(glset::bufferSize);
                    for (int i = 0; i <= glset::bufferSize; i++)
                    {
                        receivedMsg[i] = tmp[i];
                    }

                    if (receivedMsg[0] == '~')
                    {
                        _board.set_block(tmpX, tmpZ, water);
                        tmpZ = 0;
                    }
                    else if (receivedMsg[0] == 'x')
                    {
                        hit = true;
                        _board.set_block(tmpX, tmpZ, shipHit);
                    }
                    else if (receivedMsg[0] == 'f')
                    {
                        hit = true;
                        boardFinished = true;
                    }
                }
            }

            hit = false;
        }
        _board.fill_not_yet_known_with(water);
    }
}

Board Algorithm_2::get_board()
{
    return _board;
}

int Algorithm_2::get_move_count()
{
    return _counter->get_moves();
}

float Algorithm_2::get_avarage_move()
{
    return _counter->get_avarage();
}

int Algorithm_2::get_game_id()
{
    return _counter->get_game_id();
}