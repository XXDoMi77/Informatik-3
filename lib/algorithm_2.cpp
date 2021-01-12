#include "algorithm_2.h"

Algorithm_2::Algorithm_2()
{
}

Algorithm_2::~Algorithm_2()
{
    //_TCPclient->sendData("BYEBYE");
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

    // tmpX = int(9/RAND_MAX*rand())+1;
    // tmpY = int(9/RAND_MAX*rand())+1;
    
    while (!gameWon)
    {        
        while(!hit)
        {
            tmpX = rand() % 10 + 1;
            tmpY = rand() % 10 + 1;
        
            if(_board.get_block_state(tmpX, tmpY) == notYetKnown )
            {        
                sprintf(msg, "shoot %02d %02d", tmpX, tmpY);

                _TCPclient->sendData(msg);

                receivedMsg = _TCPclient->receive(25);

                if (receivedMsg[0] == '~')
                {   
                    hit = false;
                    _board.set_block(tmpX, tmpY, water);
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.set_block(tmpX, tmpY, shipHit);                   
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
                    _board.set_block(tmpZ, tmpY, water);
                    tmpZ = 11;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.set_block(tmpZ, tmpY, shipHit);                   
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
                    _board.set_block(tmpZ, tmpY, water);
                    tmpZ = 0;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.set_block(tmpZ, tmpY, shipHit);                   
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
                    _board.set_block(tmpX, tmpZ, water);
                    tmpZ = 11;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.set_block(tmpX, tmpZ, shipHit);                   
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
                    _board.set_block(tmpX, tmpZ, water);
                    tmpZ = 0;
                }
                else if(receivedMsg[0] == 'x')
                {   
                    hit = true;
                    _board.set_block(tmpX, tmpZ, shipHit);                   
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
    _board.fill_not_yet_known_with(water);
}

Board Algorithm_2::get_board()
{
    return _board;
}
