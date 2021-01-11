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
    bool hit = false;
    char msg[25];
    string receivedMsg;
    int tmpX = rand() % 10 + 1;
    int tmpY = rand() % 10 + 1;
    int tmpZ = 0;
    
    while (!gameWon)
    {        
        while(!hit)
        {
            tmpX = rand() % 10 + 1;
            tmpY = rand() % 10 + 1;
        
            if(_board.getBlockState(tmpX, tmpY) == notYetKnown )
            {        
                sprintf(msg, "shoot %02d %02d", tmpX, tmpY);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {   
                    hit = false;
                    _board.setBlock(tmpX, tmpY, water);
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.setBlock(tmpX, tmpY, shipHit);                   
                } 
                else if(receivedMsg[0] == 'f')
                {
                    hit = true;
                    gameWon = true;
                }
                usleep(500000);
            }
        
        }
        for(tmpZ = tmpX + 1 ; tmpZ <= 10; tmpZ++)
            {
                usleep(500000);
                sprintf(msg, "shoot %02d %02d", tmpZ, tmpY);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {                      
                    _board.setBlock(tmpZ, tmpY, water);
                    tmpZ = 11;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.setBlock(tmpZ, tmpY, shipHit);                   
                } 
                else if(receivedMsg[0] == 'f')
                {
                    hit = true;
                    gameWon = true;
                }
            }
        for(tmpZ = tmpX - 1 ; tmpZ >= 1; tmpZ--)
            {
                usleep(500000);
                sprintf(msg, "shoot %02d %02d", tmpZ, tmpY);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {                      
                    _board.setBlock(tmpZ, tmpY, water);
                    tmpZ = 0;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.setBlock(tmpZ, tmpY, shipHit);                   
                } 
                else if(receivedMsg[0] == 'f')
                {
                    hit = true;
                    gameWon = true;
                }
            }
        for(tmpZ = tmpY + 1 ; tmpZ <= 10; tmpZ++)
            {
                usleep(500000);
                sprintf(msg, "shoot %02d %02d", tmpX, tmpZ);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {                      
                    _board.setBlock(tmpX, tmpZ, water);
                    tmpZ = 11;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.setBlock(tmpX, tmpZ, shipHit);                   
                } 
                else if(receivedMsg[0] == 'f')
                {
                    hit = true;
                    gameWon = true;
                }
            }
        for(tmpZ = tmpY - 1 ; tmpZ >= 1; tmpZ--)
            {
                usleep(500000);
                sprintf(msg, "shoot %02d %02d", tmpX, tmpZ);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {                      
                    _board.setBlock(tmpX, tmpZ, water);
                    tmpZ = 0;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.setBlock(tmpX, tmpZ, shipHit);                   
                } 
                else if(receivedMsg[0] == 'f')
                {
                    hit = true;
                    gameWon = true;
                }
            }
            
            usleep(500000);
            hit = false;
    }
    
    
    //_board.setBlock(tmpX-1, tmpY, shipHit);
    for (int i = 1 ; i <= 10; i++)
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