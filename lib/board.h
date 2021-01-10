#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
enum BoardBlockState {notYetKnown, water, shipHit};

class Board
{
private:

    BoardBlockState _position [10] [10];
    
public:
    Board(/* args */);
    ~Board();

    void setBlock(int x, int y, BoardBlockState state);


    BoardBlockState getBlockState(int x, int y);
};

#endif /* BOARD */