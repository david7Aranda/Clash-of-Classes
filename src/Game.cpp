
#include "Game.h"
#include "CharacterTypes.h"
#include "Battle.h"
#include "UI.h"
#include <iostream>
#include <fstream>
#include <string>

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

    while(running)
    {
        showMainMenu();
        int choice = readChoice(1, 6);

        switch(choice)
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
                if(player != nullptr)
                {
                    player->printStats();
                }
                else
                {
                    cout << "Create a character first." << endl;
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

// Create a character
Character * Game::createCharacter(const string & type, const string & name) const
{
    if(type == "Warrior")
    {
        return new Warrior(name);
    }
    else if(type == "Mage")
    {
        return new Mage(name);
    }
    else if(type == "Rogue")
    {
        return new Rogue(name);
    }
    else
    {
        return nullptr;
    }
}

// Create a new player
void Game::newCharacter()
{
    cout << endl;
    cout << "Choose your character type:" << endl;
    cout << "1. Warrior - High health and defense" << endl;
    cout << "2. Mage - Strong magic attacks" << endl;
    cout << "3. Rogue - Fast attacks and critical hits" << endl;

    int choice = readChoice(1, 3);

    string type;

    if(choice == 1)
    {
        type = "Warrior";
    }
    else if(choice == 2)
    {
        type = "Mage";
    }
    else
    {
        type = "Rogue";
    }

    string name = readName();

    delete player;
    player = createCharacter(type, name);

    cout << endl;
    cout << "Welcome, " << player->getName() << "!" << endl;
    cout << "You are a " << player->getType() << "!" << endl;

    player->printStats();
}

// Create a random opponent
Character * Game::makeRandomOpponent() const
{
    int choice = randomNumber(1, 3);

    string type;

    if(choice == 1)
    {
        type = "Warrior";
    }
    else if(choice == 2)
    {
        type = "Mage";
    }
    else
    {
        type = "Rogue";
    }

    string names[5] = {
        "Grok",
        "Shadow",
        "Dragon",
        "Knight",
        "Hunter"
    };

    int nameChoice = randomNumber(0, 4);

    string name = names[nameChoice];

    return createCharacter(type, name);
}

// Start a battle
void Game::startDuel()
{
    if(player == nullptr)
    {
        cout << "Create a character first." << endl;
        return;
    }

    Character * opponent = makeRandomOpponent();

    if(opponent == nullptr)
    {
        cout << "Could not create an opponent." << endl;
        return;
    }

    cout << endl;
    cout << "A new opponent has appeared!" << endl;

    Battle battle(player, opponent);

    BattleResult result = battle.run();

    if(result == PLAYER_WON)
    {
        cout << endl;
        cout << "VICTORY!" << endl;
    }
    else if(result == PLAYER_LOST)
    {
        cout << endl;
        cout << "DEFEAT!" << endl;
    }
    else
    {
        cout << endl;
        cout << "You fled the battle!" << endl;
    }

    delete opponent;

    player->rest();

    cout << "Your health has been restored!" << endl;
}

// Save character
void Game::saveCharacter() const
{
    if(player == nullptr)
    {
        cout << "Create a character first." << endl;
        return;
    }

    string fileName = player->getName() + ".sav";

    ofstream out(fileName);

    if(!out.is_open())
    {
        cout << "Could not save character." << endl;
        return;
    }

    out << "type " << player->getType() << endl;

    player->save(out);

    out.close();

    cout << "Character saved to " << fileName << endl;
}

// Load character
void Game::loadCharacter()
{
    string fileName;

    cout << "Enter the save file name: ";
    getline(cin, fileName);

    ifstream in(fileName);

    if(!in.is_open())
    {
        cout << "Could not open save file." << endl;
        return;
    }

    string label;
    string type;

    in >> label >> type;

    if(label != "type")
    {
        cout << "Invalid save file." << endl;
        return;
    }

    Character * loadedPlayer = createCharacter(type, "");

    if(loadedPlayer == nullptr)
    {
        cout << "Unknown character type." << endl;
        return;
    }

    loadedPlayer->load(in);

    if(in.fail())
    {
        cout << "Could not load character." << endl;
        delete loadedPlayer;
        return;
    }

    delete player;
    player = loadedPlayer;

    cout << "Character loaded successfully!" << endl;

    player->printStats();
}
