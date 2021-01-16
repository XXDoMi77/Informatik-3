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

#ifndef COUNTER_2_H_
#define COUNTER_2_H_

#include "settings.h"

class Counter
{
private:
    int *_moveCounter;
    int _gameID = 0;
    float _avarage = 0;

public:
    Counter();
    ~Counter();
    void next_game();
    void add_move();
    int get_moves();
    float get_avarage();
    int get_game_id();
    void calculate_avarage();
    void reset();
};

#endif /* COUNTER_2_H_ */
