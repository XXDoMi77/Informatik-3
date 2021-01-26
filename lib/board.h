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
    /** 
     * 
     * \brief Stores BoardBlockState
     * 
     */
    BoardBlockState _position[15][15];

public:
    /** \brief  It calls the function reset_board()*/
    Board();

    /** \brief  Currently does nothing*/
    ~Board();

    /**
	 *
	 * \brief Sets the specific coordinate into a specific BoardBlockState
	 *
	 * \param x Defines the x coordinate for setting block
	 * \param y Defines the y coordinate for setting block
	 * \param state Defines to which state the block should be set to
	 */

    void set_block(int x, int y, BoardBlockState state);

    /**
	 *
	 * \brief Gives us the status of the specific coordinate
	 *
	 * \param x Defines the x coordinate for getting block
	 * \param y Defines the y coordinate for getting block
	 */
    BoardBlockState get_block_state(int x, int y);

    /**
	 *
	 * \brief Resets the board to create a new game
	 */
    void reset_board();

    /**
	 *
	 * \brief Fills not yet know fields with the specified BoardBlockState argument
	 *
	 * \param state defines what the now_yet_known flieds should be filled with
	 */
    void fill_not_yet_known_with(BoardBlockState state);
};

#endif /* BOARD_H */
