/*
 * ALGORITHM_1.H
 *
 *  Created on: 
 *      Author: 
 */

/**
 *
 * \file algorithm_1.h
 *
 * \brief Contains the code for the first shooting algorithm (row by row)
 * 
 *
 */

#ifndef ALGORITHM_1_H_
#define ALGORITHM_1_H_

#include "board.h"
#include "simplesocket.h"
#include <ctime>       /* time */
#include <unistd.h>


/**
 * 
 * \class Algorithm_1
 * 
 * \brief Algorithm to shoot row after row
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