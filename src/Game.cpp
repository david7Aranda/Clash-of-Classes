// Game.cpp

#include "Game.h"
#include "CharacterTypes.h"
#include "Battle.h"
#include "UI.h"
#include <iostream>

using namespace std;

Game::Game()
{
    player = nullptr;
    running = true;

}

Game::~Game()
{
    delete player;

}

void Game::run()                        
{
    printTitle();

    while (running)
    {
        showMainMenu();
        int choice = readChoice(1, 6);

        switch (choice)
        {
            case 1:
                newCharacter();
                break;
            case 2:
                loadCharacter();
                break;
            case 3:
                startDuel();
                break;
            case 4:
                saveCharacter();
                break;
            case 5:
                if (player != nullptr)          
                {
                    player->printStats();       
                }
                else                            
                {
                    std::cout << "Create a character first." << std::endl;
                }
                break;
            case 6:
                running = false;
                break;
        }
    }
}                                       


void Game::showMainMenu() const
{
    cout << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|                MAIN MENU                 |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  1) New character  - create your hero    |" << endl;
    cout << "|  2) Load character - continue a save     |" << endl;
    cout << "|  3) Duel           - fight an opponent   |" << endl;
    cout << "|  4) Save           - save your hero      |" << endl;
    cout << "|  5) View stats     - see your hero       |" << endl;
    cout << "|  6) Exit                                 |" << endl;
    cout << "+------------------------------------------+" << endl;
}

void Game::newCharacter()
{
    // Show the three types, each with a one-line description.
    // Read the type (readChoice(1, 3)) and a name (readName()).
    // delete the old player, then player = createCharacter(type, name).
    // Greet the player by name and print their stats.
}

void Game::loadCharacter()
{
    // Ask for the save file name. Open an ifstream; if it didn't open, say so and return.
    // Read the type line, delete the old player, make the right type with
    // createCharacter(type, ""), then call player->load(in).
}

void Game::saveCharacter() const
{
    // If there is no player yet, say so and return.
    // Open an ofstream (for example name + ".sav"), write "type " and getType()
    // on the first line, then call player->save(out).
}

void Game::startDuel()
{
    // If there is no player yet, say so and return.
    // Make an opponent with makeRandomOpponent(), create a Battle with player and
    // opponent, run it, and print VICTORY or DEFEAT from the result.
    // delete the opponent afterwards, then let the player rest().
}

Character * Game::createCharacter(const std::string & type, const std::string & name) const
{
    // Return a new Warrior, Mage or Rogue (made with new) depending on type,
    // or nullptr if the type is unknown. newCharacter, loadCharacter and
    // makeRandomOpponent all use this.
}

Character * Game::makeRandomOpponent() const
{
    // Pick a random type and a random name from a short list,
    // and return createCharacter(type, name).
}
