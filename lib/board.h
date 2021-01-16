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
#include "settings.h"

/**
 *
 * \enum BoardBlockState
 *
 * \brief Represents the states of single block after shoot
 * 
 *
 */

enum BoardBlockState
{
    notYetKnown, /**<    */
    water,       /**<    */
    shipHit      /**<    */
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
    BoardBlockState _position[15][15];

public:
    Board(/* args */);
    ~Board();

    void set_block(int x, int y, BoardBlockState state);

    BoardBlockState get_block_state(int x, int y);

    void reset_board();

    void fill_not_yet_known_with(BoardBlockState state);
};

#endif /* BOARD_H */
