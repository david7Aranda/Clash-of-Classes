// main.cpp
// Program entry point: create the game and start it.
#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//  - In main(): seed the random numbers once with srand(time(0)),
//    make a Game object, call its run() function, then return 0.
int main()
{
    srand(time(0));

    Game game;
    game.run();
}