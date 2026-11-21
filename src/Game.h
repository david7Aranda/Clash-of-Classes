// Game.h
// Game: the main menu and the game loop.

#ifndef GAME_H
#define GAME_H

#include "Character.h"

class Game
{
    private:
        Character * player;   // nullptr until a character is created or loaded
        bool running;
        void showMainMenu() const;
        void newCharacter();
        void loadCharacter();
        void saveCharacter() const;
        void startDuel();
        Character * createCharacter(const std::string & type, const std::string & name) const;
        Character * makeRandomOpponent() const;
    public:
        Game();
        void run();
        ~Game();
};

#endif
