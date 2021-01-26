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
#include <ctime> /* time */
#include <unistd.h>
#include "counter.h"
#include "settings.h"

/**
 * 
 * \class Algorithm_2
 * 
 * \brief Algorithm 2 shoots randomly until it finds a boat, if
 * it found a boat it strategically shoots around the boat...
 * 
 * 
*/

class Algorithm_2
{
private:
    /** \brief The _board object stores the state of a block which the algorithm writes into it*/
    Board _board;

    /** \brief The _counter object stores the game id, number of moves and avarage moves*/
    Counter *_counter;

public:
    /**
	 *
	 * \brief Initiates new counter object to store the game id, number of moves, avarage moves in
     * 
	 */
    Algorithm_2();

    /**
	 *
	 * \brief The destructor of the Algorithm. It does currently nothing but is 
     * supposed to stop the server connection to the client when it gets called.
     * Currently not implemented...
     * 
	 */
    ~Algorithm_2();

    /**
	 *
	 * \brief Starts the first algorithm
	 *
	 * \param *_TCPclient Takes a pointer to a client object to cummunicate with server
	 *
	 */
    void run(TCPclient *_TCPclient);

    /**
	 *
	 * \brief Forwards the Board object in which the client stores it's hits and misses to the menu
	 *
	 * \return Board object in which the hits and misses and water blocks are stored
	 *
	 */
    Board get_board();

    /**
	 *
	 * \brief Forwards to the menu, how many moves the algorithm has made in the specific game
	 *
	 * \return int that contains the number of moves the algoithm has made
	 *
	 */
    int get_move_count();

    /**
	 *
	 * \brief Forwards the avarage made moves to the menu
	 *
	 * \return float that conatins the calculated avarage moves
	 *
	 */
    float get_avarage_move();

    /**
	 *
	 * \brief Forwards the id aka. the number of the currently played game to the menu
	 *
	 * \return int that conatins the number/ id of the currently played game
	 *
	 */
    int get_game_id();
};

#endif /* ALGORITHM_2_H_ */
