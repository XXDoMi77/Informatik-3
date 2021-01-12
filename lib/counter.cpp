#include "counter.h"

Counter::Counter()
{
    _moveCounter = new int[MAX_COUNT];
    
}

Counter::~Counter()
{
}


void Counter::next_game()
{
    _gameID++;
    calculate_avarage();
}

void Counter::add_move()
{
    _moveCounter[_gameID]++;
}

float Counter::get_avarage()
{
    return _avarage;
}

int Counter::get_moves()
{
    return _moveCounter[_gameID];
}

int Counter::get_game_id()
{
    return _gameID;
}

void Counter::reset()
{
    for (int i = 0; i < MAX_COUNT; i++)
    {
        _moveCounter[i] = 0;
    }
    _gameID = 0;
}

void Counter::calculate_avarage()
{
    if(_gameID != 0 && _gameID != 1)
    {
        float tmp = 0.0;
        for (int i = 1; i <= _gameID; i++)
        {
            tmp = tmp + _moveCounter[i];
        }
        _avarage = float(float(tmp)/float(_gameID-1));
    }
}
