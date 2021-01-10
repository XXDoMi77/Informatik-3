#ifndef ALGORITHM_1_H_
#define ALGORITHM_1_H_

#include "board.h"
#include "simplesocket.h"
#include <ctime>       /* time */
#include <unistd.h>

/**
 * 
 * \class
 * 
 * \brief Algorithm to shot row after row
 * 
 * 
*/

class Algorithm_1
{
private:
    Board _board;
    
public:
    Algorithm_1();
    ~Algorithm_1();

    void run(TCPclient* _TCPclient);

    Board getBoard();
};

#endif /* ALGORITHM_1_H_ */