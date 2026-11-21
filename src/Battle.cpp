// Battle.cpp

#include "Battle.h"
#include "UI.h"

Battle::Battle(Character * _player, Character * _opponent)
{
    // Store the two pointers and start at round 0.
}

BattleResult Battle::run()
{
    // Print the VS banner and both names.
    // Loop while both characters are alive:
    //   add 1 to round, showStatus(),
    //   playerTurn() - if it returns false, the player fled: return PLAYER_FLED,
    //   if the opponent is still alive, opponentTurn().
    // After the loop, call updateAfterCombat on both characters
    // and return PLAYER_WON or PLAYER_LOST.
}

void Battle::showStatus() const
{
    // Print the round number, both portraits (the opponent facing left),
    // and both names with their health bars.
}

bool Battle::playerTurn()
{
    // Call player->updateDuringCombat().
    // Show the actions: 1 Attack, 2 Special, 3 Defend, 4 Use potion, 5 Flee.
    // Read a choice (readChoice(1, 5)) and call the matching function on player,
    // with *opponent as the target. Return false only for Flee.
}

void Battle::opponentTurn()
{
    // Call opponent->updateDuringCombat().
    // Pick an action with randomNumber: mostly attacks, sometimes special or defend,
    // and a potion when health is low. The target is *player.
}
