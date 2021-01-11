/*
 * BOARD.H
 *
 *  Created on: 
 *      Author: 
 */

/**
 *
 * \file board.h
 *
 * \brief Contains the code to create the battlefield
 * 
 *
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

/**
 *
 * \enum BoardBlockState
 *
 * \brief Represents the states of single block after shoot
 * 
 *
 */

enum BoardBlockState   {notYetKnown, /**<    */
                        water, /**<    */
                        shipHit /**<    */
                        };

/**
 *
 * \class Board
 *
 * \brief Implements a class to create a battlefield
 * 
 *
 */


class Board
{
private:

    BoardBlockState _position [15] [15];
    
public:
    Board(/* args */);
    ~Board();

    void setBlock(int x, int y, BoardBlockState state);


    BoardBlockState getBlockState(int x, int y);
};

#endif /* BOARD_H */