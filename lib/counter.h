/*
 * ALGORITHM_2.H
 *
 *  Created on: 
 *      Author: 
 */

/**
 *
 * \file counter.h
 *
 * \brief Contains the code to count the games, moves and avarage moves for a player or in this case algorithm
 * 
 *
 */

#ifndef COUNTER_2_H_
#define COUNTER_2_H_

#include "settings.h"

class Counter
{
private:
    /** \brief Stores how many moves has been mande*/
    int *_moveCounter;

    /** \brief Stores the ID/ Number of the currently played game*/
    int _gameID = 0;

    /** \brief Stores the avarage number of moves it took to finish game*/
    float _avarage = 0;

public:
    /** \brief It creates a new integer at the _moveCounter pointer */
    Counter();

    /** \brief */
    ~Counter();

    /** \brief It adds +1 to the _gameID aka. counter */
    void next_game();

    /** \brief Adds +1 move to the _moveCounter */
    void add_move();

    /**
	 *
	 * \brief It returns how many moves the algorithm has made in a current game
	 *
	 * \return int that stores how many moves the algorithm has made in a current game
	 *
	 */
    int get_moves();

    /**
	 *
	 * \brief Returns the avarage number of moves made in a current game
	 *
	 * \return float that stores the avarage number of moves made in a current game
	 *
	 */
    float get_avarage();

    /**
	 *
	 * \brief Returns the current gameID/number
	 *
	 * \return int that stores the current gameID/number
	 *
	 */
    int get_game_id();

    /**
	 *
	 * \brief Calculates the avarage number of moves until current gameID
	 *
	 */
    void calculate_avarage();

    /**
	 *
	 * \brief Resets counter
	 *
	 */
    void reset();
};

#endif /* COUNTER_2_H_ */
