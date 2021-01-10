#include "board.h"


Board::Board(/* args */)
{
    for (int i = 0; i < 10; i++)
    {
        for (int a = 0; a < 10; a++)
        {
            _position [i] [a] = notYetKnown;
        }
    }
}

Board::~Board()
{
}

void Board::setBlock(int x, int y, BoardBlockState state)
{
    _position [x] [y] = state;
}

BoardBlockState Board::getBlockState(int x, int y)
{
    return _position [x] [y];
}