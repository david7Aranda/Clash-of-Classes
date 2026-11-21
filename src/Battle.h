// Battle.h
// Battle: a duel between the player and an opponent.


#ifndef BATTLE_H
#define BATTLE_H

#include "Character.h"

enum BattleResult { PLAYER_WON, PLAYER_LOST, PLAYER_FLED };

class Battle
{
    private:
        Character * player;   // points to the Game's player; Battle does not delete it
        Character * opponent;
        int round;
        void showStatus() const;
        bool playerTurn();    // returns false if the player fled
        void opponentTurn();
    public:
        Battle(Character * _player, Character * _opponent);
        BattleResult run();
};

#endif
