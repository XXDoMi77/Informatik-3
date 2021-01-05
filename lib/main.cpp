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

#include "menu.h"
#include "battleship.h"

using namespace std;



int main()
{
    //create a menu object
    Menu* menu1 = new Menu;

    //start timer for semi random numbers
    srand (time(NULL));

    menu1->create_menu();

    return 0;
}
