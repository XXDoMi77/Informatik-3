#include "algorithm_2.h"

Algorithm_2::Algorithm_2()
{
}

Algorithm_2::~Algorithm_2()
{
}

void Algorithm_2::run(TCPclient* _TCPclient)
{
    srand (time(NULL));
    bool gameWon = false;
    char msg[25];
    string receivedMsg;
    int tmpX;
    int tmpY;
    while (!gameWon)
    {
        // tmpX = int(9/RAND_MAX*rand())+1;
        // tmpY = int(9/RAND_MAX*rand())+1;
        tmpX = rand() % 10 + 1;
        tmpY = rand() % 10 + 1;

        sprintf(msg, "shoot %02d %02d", tmpX, tmpY);

        _TCPclient->sendData(msg);

        receivedMsg = _TCPclient->receive(25);

        if (receivedMsg[0] == '~')
        {
            _board.setBlock(tmpX, tmpY, water);
        }
        else if(receivedMsg[0] == 'x')
        {
            _board.setBlock(tmpX, tmpY, shipHit);
        }
        else if(receivedMsg[0] == 'x')
        {
            _board.setBlock(tmpX, tmpY, shipHit);
        }
        else if(receivedMsg[0] == 'f')
        {
            gameWon = true;
        }
        else if(receivedMsg[0] == 'f')
        {
            gameWon = true;
        }

        usleep(100000);
    }
    _board.setBlock(tmpX-1, tmpY, shipHit);
    for (int i = 1; i <= 10; i++)
    {
        for (int a = 1; a <= 10; a++)
        {
            if(_board.getBlockState(i, a) == notYetKnown)
            {
                _board.setBlock(i, a, water);
            }
        }
        
    }
    
}

Board Algorithm_2::getBoard()
{
    return _board;
}