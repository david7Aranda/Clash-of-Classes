// CharacterTypes.cpp
// Each commented-out function below has a note saying what it should do.
// When you write one, replace its commented version with your real code.

#include "CharacterTypes.h"
#include "UI.h"
#include "Art.h"

// Warrior::Warrior(const std::string & _name)
//     : Character(_name, startHealth, startAttack, startDefense)
// {
//     // Replace startHealth, startAttack and startDefense with random values that
//     // suit a warrior (high health and defense), for example randomNumber(110, 130).
//     // Set stamina and pick a weapon.
// }

// std::string Warrior::getType() const
// {
//     // Return "Warrior".
// }

// void Warrior::attack(Character & target)
// {
//     // Basic attack: work out the damage (attackPower plus a small random amount),
//     // print a warrior-style message, then call target.takeDamage(damage).
// }

// void Warrior::specialAttack(Character & target)
// {
//     // Power Strike: if there is enough stamina, spend it and deal big damage
//     // with its own message. If not, print a message and do a normal attack.
// }

// void Warrior::defend()
// {
//     // Raise a shield: print your own message and set defending to true.
// }

// void Warrior::updateDuringCombat()
// {
//     // Call Character::updateDuringCombat(), then regain some stamina (up to a maximum).
// }

void Warrior::printPortrait(const bool facingLeft) const
{
    if (facingLeft)
        std::cout << WARRIOR_LEFT;
    else
        std::cout << WARRIOR_RIGHT;
}

// void Warrior::printStats() const
// {
//     // Call Character::printStats(), then print stamina and weapon.
// }

// void Warrior::save(std::ofstream & out) const
// {
//     // Call Character::save(out), then write stamina and weapon.
// }

// void Warrior::load(std::ifstream & in)
// {
//     // Call Character::load(in), then read stamina and weapon.
// }

// Mage::Mage(const std::string & _name)
//     : Character(_name, startHealth, startAttack, startDefense)
// {
//     // Replace the three start values with random values that suit a mage
//     // (low health and defense, high attack). Set mana and spellPower.
// }

// std::string Mage::getType() const
// {
//     // Return "Mage".
// }

// void Mage::attack(Character & target)
// {
//     // Basic attack: work out the damage (attackPower plus a small random amount),
//     // print a mage-style message, then call target.takeDamage(damage).
// }

// void Mage::specialAttack(Character & target)
// {
//     // Fireball: if there is enough mana, spend it and deal spellPower-based
//     // damage with its own message. If not, print a message and do a normal attack.
// }

// void Mage::defend()
// {
//     // Magic barrier: print your own message and set defending to true.
// }

// void Mage::updateDuringCombat()
// {
//     // Call Character::updateDuringCombat(), then regain some mana (up to a maximum).
// }

void Mage::printPortrait(const bool facingLeft) const
{
    if (facingLeft)
        std::cout << MAGE_LEFT;
    else
        std::cout << MAGE_RIGHT;
}

// void Mage::printStats() const
// {
//     // Call Character::printStats(), then print mana and spellPower.
// }

// void Mage::save(std::ofstream & out) const
// {
//     // Call Character::save(out), then write mana and spellPower.
// }

// void Mage::load(std::ifstream & in)
// {
//     // Call Character::load(in), then read mana and spellPower.
// }

// Rogue::Rogue(const std::string & _name)
//     : Character(_name, startHealth, startAttack, startDefense)
// {
//     // Replace the three start values with random values that suit a rogue
//     // (medium health, quick attacks). Set energy and critChance.
// }

// std::string Rogue::getType() const
// {
//     // Return "Rogue".
// }

// void Rogue::attack(Character & target)
// {
//     // Basic attack: work out the damage (attackPower plus a small random amount),
//     // with a critChance percent chance of doing double damage,
//     // print a rogue-style message, then call target.takeDamage(damage).
// }

// void Rogue::specialAttack(Character & target)
// {
//     // Backstab: if there is enough energy, spend it and deal heavy damage
//     // with its own message. If not, print a message and do a normal attack.
// }

// void Rogue::defend()
// {
//     // Dodge stance: print your own message and set defending to true.
// }

// void Rogue::updateDuringCombat()
// {
//     // Call Character::updateDuringCombat(), then regain some energy (up to a maximum).
// }

void Rogue::printPortrait(const bool facingLeft) const
{
    if (facingLeft)
        std::cout << ROGUE_LEFT;
    else
        std::cout << ROGUE_RIGHT;
}

// void Rogue::printStats() const
// {
//     // Call Character::printStats(), then print energy and critChance.
// }

// void Rogue::save(std::ofstream & out) const
// {
//     // Call Character::save(out), then write energy and critChance.
// }

// void Rogue::load(std::ifstream & in)
// {
//     // Call Character::load(in), then read energy and critChance.
// }
