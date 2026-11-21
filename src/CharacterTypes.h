// CharacterTypes.h
// The three character types, each derived from Character.

#ifndef CHARACTERTYPES_H
#define CHARACTERTYPES_H

#include "Character.h"

class Warrior : public Character // tough: high health and defense
{
    private:
        int stamina;        // spent on Power Strike
        std::string weapon;
    public:
        Warrior(const std::string & _name); // picks random starting stats
        std::string getType() const override;
        void attack(Character & target) override;
        void specialAttack(Character & target) override;
        void defend() override;
        void updateDuringCombat() override;
        void printPortrait(const bool facingLeft) const override;
        void printStats() const override;
        void save(std::ofstream & out) const override;
        void load(std::ifstream & in) override;
};

class Mage : public Character // strong attacks, low health
{
    private:
        int mana;           // spent on Fireball
        int spellPower;
    public:
        Mage(const std::string & _name); // picks random starting stats
        std::string getType() const override;
        void attack(Character & target) override;
        void specialAttack(Character & target) override;
        void defend() override;
        void updateDuringCombat() override;
        void printPortrait(const bool facingLeft) const override;
        void printStats() const override;
        void save(std::ofstream & out) const override;
        void load(std::ifstream & in) override;
};

class Rogue : public Character // fast: critical hits
{
    private:
        int energy;         // spent on Backstab
        int critChance;     // percent chance of a critical hit
    public:
        Rogue(const std::string & _name); // picks random starting stats
        std::string getType() const override;
        void attack(Character & target) override;
        void specialAttack(Character & target) override;
        void defend() override;
        void updateDuringCombat() override;
        void printPortrait(const bool facingLeft) const override;
        void printStats() const override;
        void save(std::ofstream & out) const override;
        void load(std::ifstream & in) override;
};

#endif
