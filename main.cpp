//============================================================================
// Name        : INF3_Prak.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <cstdio>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

// #include <unistd.h>

#include "battleship.h"     //include battleship

using namespace std;

// int main(){
//     cout << "\n\n\n\n\nHello World!\n\n\n\n\n";
//     return 0;
// }

int main(){
    battleship::World world1; //create world
    cout << "\n\n\n"; //leave some space above
    world1.printBoard(); //print the current state of the board
    cout << "\n\n\n"; //leave some space below

    return 0;
}
