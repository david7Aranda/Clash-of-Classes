// Character.cpp

#include "Character.h"
#include "UI.h"

Character::Character(const std::string & _name, const int _maxHealth, const int _attackPower, const int _defense)
{
    // Set the name and stats from the parameters.
    // Start at level 1 with 0 XP, full health (health = maxHealth),
    // 3 potions, and not defending.
}

std::string Character::getName() const
{
    // Return the name. (The other getters work the same way.)
}

int Character::getLevel() const
{
}

int Character::getHealth() const
{
}

int Character::getMaxHealth() const
{
}

bool Character::isAlive() const
{
    // True while health is above 0.
}

void Character::takeDamage(const int amount)
{
    // Subtract defense from amount, but always take at least 1 damage.
    // If defending, cut the damage in half.
    // Lower health, but never below 0. Print how much damage this character took.
}

void Character::heal(const int amount)
{
    // Raise health by amount, but never above maxHealth.
}

bool Character::usePotion()
{
    // If there are potions left: use one, heal (for example 30), return true.
    // Otherwise print a message and return false.
}

void Character::gainXP(const int amount)
{
    // Add amount to xp. When xp reaches level * 100, level up:
    // level goes up by 1, xp starts over, maxHealth/attackPower/defense go up a little,
    // and health refills. Print a level-up message with the name.
}

void Character::rest()
{
    // Refill health to maxHealth. Used between duels.
}

void Character::updateDuringCombat()
{
    // Called at the start of this character's turn: stop defending.
    // Warrior, Mage and Rogue override this: they call Character::updateDuringCombat()
    // first, then regain some stamina, mana or energy.
}

void Character::updateAfterCombat(const bool won)
{
    // Stop defending. If won, call gainXP (for example 50).
    // Print a short message either way.
}

void Character::defend()
{
    // Set defending to true and print a message with the name.
}

void Character::printStats() const
{
    // Print name, type (getType()), level, XP, health with a health bar
    // (printHealthBar from UI), attack, defense and potions.
}

void Character::save(std::ofstream & out) const
{
    // Write one value per line with a label, for example:
    // name David
    // level 3
    // (Game writes the type line before calling this, so don't write it here.)
}

void Character::load(std::ifstream & in)
{
    // Read the values back in the same order save wrote them.
    // Tip: in >> label >> value reads a line like "level 3".
    // If names can have spaces, read the name with getline.
}
