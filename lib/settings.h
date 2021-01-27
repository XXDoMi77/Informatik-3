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

/**
 * \namespace glset
 * 
 * \brief Most of the important settings are stored in here
 */

namespace glset
{
    //GAME SETTINGS
    const bool delayOn = false; /**< \brief Defines whether delays should be added or not*/
    const int delay = 50000;    /**< \brief Sets delay between shots*/
    // const int global_world_x = 10;/**< \brief sets world size on the x axis, not yet implemented*/
    // const int global_world_y = 10;/**< \brief sets world size on the y axis, not yet implemented*/
    const int maxGamesPlayed = 10000; /**< \brief Sets how many games the algorithm should play*/
    const int minRefreshRate = 30;    /**< \brief Defines the minimal refreshrate of drawing/rendering the menu/terminal display output*/

    //KEY BINDINGS
    const int keyArrowUp = 259;       /**< \brief Defines key to move up in the menu */
    const int keyArrowDown = 258;     /**< \brief Defines key to move down in the menu */
    const int keyEnter = 10;          /**< \brief Defines key to confirm selection */
    const int keyQ = 113;             /**< \brief Exits Server screen and Client screen, not yet properly implemented */
    const int keySelectLocalhost = 6; /**< \brief Selects localhost instead of manual ip */
    const int keyBackspace = 127;
    const int keyDot = 46;
    const int keyComma = 44;
    const int key9 = 57;
    const int key8 = 56;
    const int key7 = 55;
    const int key6 = 54;
    const int key5 = 53;
    const int key4 = 52;
    const int key3 = 51;
    const int key2 = 50;
    const int key1 = 49;
    const int key0 = 48;

    //SERVER SETTINGS
    const int startingPort = 7777; /**< \brief Defines at what port the servers should start at */
    const int bufferSize = 25;     /**< \brief Defines the buffersize for server and for client */
} // namespace glset

#endif /* SETTINGS_H_ */
