#include "board.h"

Board::Board(/* args */)
{
    reset_board();
}

Board::~Board()
{
}

void Board::set_block(int x, int y, BoardBlockState state)
{
    _position[x][y] = state;
}

BoardBlockState Board::get_block_state(int x, int y)
{
    return _position[x][y];
}

void Board::reset_board()
{
    for (int i = 0; i < 15; i++)
    {
        for (int a = 0; a < 15; a++)
        {
            _position[i][a] = notYetKnown;
        }
    }
}

void Board::fill_not_yet_known_with(BoardBlockState state)
{
    for (int i = 0; i <= 10; i++)
    {
        for (int a = 0; a <= 10; a++)
        {
            if (_position[i][a] == notYetKnown)
            {
                _position[i][a] = state;
            }
        }
    }
}
