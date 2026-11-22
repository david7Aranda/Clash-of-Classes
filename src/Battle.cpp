// Battle.cpp
#include "Battle.h"
#include "UI.h"
#include "Art.h"
#include <iostream>

using namespace std;

Battle::Battle(Character * _player, Character * _opponent)
{
    player = _player;
    opponent = _opponent;
    round = 0;
}

BattleResult Battle::run()
{
    cout << player->getName() << " VS " << opponent->getName() << endl;

    while(player->isAlive() && opponent->isAlive())
    {
        round = round + 1;

        showStatus();

        if(playerTurn() == false)
        {
            cout << player->getName() << " fled the battle!" << endl;

            return PLAYER_FLED;
        }

        if(opponent->isAlive())
        {
            opponentTurn();
        }
    }

    if(player->isAlive())
    {
        player->updateAfterCombat(true);
        opponent->updateAfterCombat(false);

        return PLAYER_WON;
    }
    else
    {
        player->updateAfterCombat(false);
        opponent->updateAfterCombat(true);

        return PLAYER_LOST;
    }
}

void Battle::showStatus() const
{
    cout << endl;
    cout << "========== Round " << round
         << " ==========" << endl;

    cout << player->getName() << ": ";
    printHealthBar(player->getHealth(),
                   player->getMaxHealth());

    cout << opponent->getName() << ": ";
    printHealthBar(opponent->getHealth(),
                   opponent->getMaxHealth());

    cout << endl;

    player->printPortrait(false);

    cout << VS_ART << endl;

    opponent->printPortrait(true);
}

bool Battle::playerTurn()
{
    player->updateDuringCombat();

    cout << endl;
    cout << "Your turn!" << endl;

    cout << "1. Attack" << endl;
    cout << "2. Special Attack" << endl;
    cout << "3. Defend" << endl;
    cout << "4. Use Potion" << endl;
    cout << "5. Flee" << endl;

    int choice = readChoice(1, 5);

    if(choice == 1)
    {
        player->attack(*opponent);
    }
    else if(choice == 2)
    {
        player->specialAttack(*opponent);
    }
    else if(choice == 3)
    {
        player->defend();
    }
    else if(choice == 4)
    {
        player->usePotion();
    }
    else if(choice == 5)
    {
        return false;
    }

    return true;
}

void Battle::opponentTurn()
{
    opponent->updateDuringCombat();

    cout << endl;
    cout << opponent->getName()
         << "'s turn!" << endl;

    int choice = randomNumber(1, 10);

    if(opponent->getHealth() < opponent->getMaxHealth() / 2
       && randomNumber(1, 4) == 1)
    {
        opponent->usePotion();
    }
    else if(choice <= 6)
    {
        opponent->attack(*player);
    }
    else if(choice <= 8)
    {
        opponent->specialAttack(*player);
    }
    else
    {
        opponent->defend();
    }
}