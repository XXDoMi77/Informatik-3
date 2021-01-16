#ifndef SETTINGS_H_
#define SETTINGS_H_

namespace glset
{
    //GAME SETTINGS
    const bool delayOn = false;
    const int delay = 50000; //sets delay between shots
    // const int global_world_x = 10; //sets world size on the x axis
    // const int global_world_y = 10; //sets world size on the y axis
    const int maxGamesPlayed = 10000;

    //KEY BINDINGS
    const int keyArrowUp = 259;
    const int keyArrowDown = 258;
    const int keyEnter = 10;
    const int keyQ = 113;

    //SERVER SETTINGS
    const int startingPort = 7777;
    const int bufferSize = 25;
} // namespace glset

#endif /* SETTINGS_H_ */
