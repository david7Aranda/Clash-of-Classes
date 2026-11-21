// Character.h
// Character: the base class for every character type (Warrior, Mage, Rogue).

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>
#include <iostream>

class Character // abstract base class: the "= 0" functions make it abstract
{
    protected: // protected, so Warrior, Mage and Rogue can use these directly
        std::string name;
        int level;
        int xp;
        int health;
        int maxHealth;
        int attackPower;
        int defense;
        int potions;
        bool defending;
    public:
        Character(const std::string & _name, const int _maxHealth, const int _attackPower, const int _defense);

        // Getters
        std::string getName() const;
        int getLevel() const;
        int getHealth() const;
        int getMaxHealth() const;
        bool isAlive() const;

        // The five interaction functions
        void takeDamage(const int amount);
        void heal(const int amount);
        bool usePotion();
        void gainXP(const int amount);
        void rest();

        // State updates: during combat (each turn) and after combat
        virtual void updateDuringCombat();
        void updateAfterCombat(const bool won);

        // Each type does these its own way
        virtual std::string getType() const = 0;
        virtual void attack(Character & target) = 0;
        virtual void specialAttack(Character & target) = 0;
        virtual void defend();
        virtual void printPortrait(const bool facingLeft) const = 0;
        virtual void printStats() const;

        // Save and load (each type overrides these to add its own variables)
        virtual void save(std::ofstream & out) const;
        virtual void load(std::ifstream & in);

        virtual ~Character() {} // virtual, so deleting through a Character* works
};

#endif
