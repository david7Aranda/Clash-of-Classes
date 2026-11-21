// Game.cpp

#include "Game.h"
#include "CharacterTypes.h"
#include "Battle.h"
#include "UI.h"

Game::Game()
{
    // player starts as nullptr, running starts as true.
    payer = nullptr;
    running = true;

}

Game::~Game()
{
    // delete player (deleting a nullptr is safe).
    delete player;

}

void Game::run()
{
    // printTitle(). While running: showMainMenu(), read a choice, and call
    // newCharacter, loadCharacter, startDuel, saveCharacter, player->printStats(),
    // or set running to false to exit.
    showMainMenu();
    while(running)
    {

    }
}

void Game::showMainMenu() const
{
    // Print the menu in an ASCII box:
    // 1 New character, 2 Load character, 3 Duel, 4 Save, 5 View stats, 6 Exit.
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
