// Character.cpp

#include "Character.h"
#include "UI.h"
#include <iostream>

using namespace std;

Character::Character(const string & _name, const int _maxHealth, const int _attackPower, const int _defense)
{
    name = _name;
    level = 1;
    xp = 0;
    health = _maxHealth;
    maxHealth = _maxHealth;
    attackPower = _attackPower;
    defense = _defense;
    potions = 3;
    defending = false;
}

string Character::getName() const
{
    return name;
}

int Character::getLevel() const
{
    return level;
}

int Character::getHealth() const
{
    return health;
}

int Character::getMaxHealth() const
{
    return maxHealth;
}

bool Character::isAlive() const
{
    // True while health is above 0.
    if(health > 0)
    {
        return true;
    }
    return false;
}

void Character::takeDamage(const int amount)
{
    int damage = amount - defense;
    if(damage < 1)
    {
        damage = 1;
    }
    if(defending)
    {
        damage = max(1, damage / 2);
    }
    health = health - damage;
    if(health < 0)
    {
        health = 0;
    }
    cout << name << " took " << damage << " damage." << endl;
}

void Character::heal(const int amount)
{
    // Raise health by amount, but never above maxHealth.
    if(health <= 0)
    {
        return;
    }
    health = health + amount;
    if(health > maxHealth)
    {
        health = maxHealth;
    }
}

bool Character::usePotion()
{
    if(potion > 0)
    {
        potion = potion - 1;
        health = health + 30;
        cout << name << " used a potion and recovered health!" << endl;
        return true;
    }
    cout << name << " has no potions left!" << endl;
    return false;
}

void Character::gainXP(const int amount)
{
    if(amount <= 0)
    {
        return;
    }
    xp = xp + amount;

    if (xp >= level * 100)
    {
        level++;
        xp = 0;

        // Increase character stats
        maxHealth += 10;
        attackPower += 2;
        defense += 1;

        // Restore health
        health = maxHealth;

        cout << name
            << " leveled up! Now level "
            << level << "!" << endl;
    }

}

void Character::rest()
{
    health = maxHealth;
}

void Character::updateDuringCombat()
{
    defending = false; 
}

void Character::updateAfterCombat(const bool won)
{
    // Stop defending. If won, call gainXP (for example 50).
    // Print a short message either way.
    
}

void Character::defend()
{
    defending = true;
    cout << name << " is defending" << endl;
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
