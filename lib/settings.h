/**
 *
 * \file settings.h
 *
 * \brief Contains the settings for the program, such as delay betweenshots,
 * key bindings, amount of games to be played by the algorithms, starting port...
 * 
 *
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>

namespace glset
{
    //GAME SETTINGS
    const bool delayOn = false; //defines whether delays should be added or not
    const int delay = 50000;    //sets delay between shots
    // const int global_world_x = 10;//sets world size on the x axis, not yet implemented
    // const int global_world_y = 10;//sets world size on the y axis, not yet implemented
    const int maxGamesPlayed = 10000; //sets how many games the algorithm should play
    const int minRefreshRate = 30;    //defines the minimal refreshrate of drawing/rendering the menu/terminal display output

    //KEY BINDINGS
    const int keyArrowUp = 259;   //defines key to move up in the menu
    const int keyArrowDown = 258; //defines key to move down in the menu
    const int keyEnter = 10;      //defines key to confirm selection
    const int keyQ = 113;         //exits Server screen and Client screen, not yet properly implemented

    //SERVER SETTINGS
    const int startingPort = 7777;             //defines at what port the servers should start at
    const int bufferSize = 25;                 //defines the buffersize for server and for client
    const std::string ipAddress = "localhost"; //sets the ip address to use for client connection
} // namespace glset

#endif /* SETTINGS_H_ */
