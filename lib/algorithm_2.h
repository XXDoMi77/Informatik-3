/*
 * ALGORITHM_2.H
 *
 *  Created on: 
 *      Author: 
 */

/**
 *
 * \file algorithm_2.h
 *
 * \brief Contains the code for the second shooting algorithm (random)
 * 
 *
 */

#ifndef ALGORITHM_2_H_
#define ALGORITHM_2_H_

#include "board.h"
#include "simplesocket.h"
#include <ctime>       /* time */
#include <unistd.h>

/**
 * 
 * \class Algorithm_2
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

    Board get_board();
};

#endif /* ALGORITHM_2_H_ */
