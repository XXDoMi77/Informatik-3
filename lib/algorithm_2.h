#ifndef ALGORITHM_2_H_
#define ALGORITHM_2_H_

#include "board.h"
#include "simplesocket.h"
#include <ctime>       /* time */
#include <unistd.h>

/**
 * 
 * \class
 * 
 * \brief Algorithm for randomized shooting
 * 
 * 
*/

class Algorithm_2
{
private:
    Board _board;
    
public:
    Algorithm_2();
    ~Algorithm_2();

    void run(TCPclient* _TCPclient);

    Board getBoard();
};

#endif /* ALGORITHM_2_H_ */