
#include "CharacterTypes.h"
#include "UI.h"
#include "Art.h"
#include <iostream>
#include <string>

using namespace std;

// ==================== WARRIOR ====================

Warrior::Warrior(const string & _name) : Character(_name, randomNumber(110, 130), randomNumber(10, 15), randomNumber(6, 10))
{
    stamina = 100;

    int choice = randomNumber(1, 3);

    if(choice == 1)
    {
        weapon = "Sword";
    }
    else if(choice == 2)
    {
        weapon = "Axe";
    }
    else
    {
        weapon = "Hammer";
    }
}

string Warrior::getType() const
{
    return "Warrior";
}

void Warrior::attack(Character & target)
{
    int damage = attackPower + randomNumber(1, 6);

    cout << name << " attacks " << target.getName() << " with a " << weapon << "!" << endl;
    target.takeDamage(damage);
}

void Warrior::specialAttack(Character & target)
{
    if(stamina >= 20)
    {
        stamina = stamina - 20;
        int damage = attackPower * 2 + randomNumber(5, 10);

        cout << name << " uses Power Strike on " << target.getName() << "!" << endl;
        target.takeDamage(damage);
    }
    else
    {
        cout << name << " does not have enough stamina!" << endl;
        attack(target);
    }
}

void Warrior::defend()
{
    defending = true;
    cout << name << " raises a shield to defend!" << endl;
}

void Warrior::updateDuringCombat()
{
    Character::updateDuringCombat();

    stamina = stamina + 10;

    if(stamina > 100)
    {
        stamina = 100;
    }
}

void Warrior::printPortrait(const bool facingLeft) const
{
    if(facingLeft)
    {
        cout << WARRIOR_LEFT;
    }
    else
    {
        cout << WARRIOR_RIGHT;
    }
}

void Warrior::printStats() const
{
    Character::printStats();

    cout << "Stamina: " << stamina << "/100" << endl;
    cout << "Weapon: " << weapon << endl;
}

void Warrior::save(std::ofstream & out) const
{
    Character::save(out);

    out << "stamina " << stamina << endl;
    out << "weapon " << weapon << endl;
}

void Warrior::load(std::ifstream & in)
{
    Character::load(in);

    string label;

    in >> label >> stamina;
    in >> label >> weapon;
}


// ==================== MAGE ====================

Mage::Mage(const string & _name) : Character(_name, randomNumber(70, 90), randomNumber(14, 20), randomNumber(1, 3))
{
    mana = 100;
    spellPower = randomNumber(15, 25);
}

string Mage::getType() const
{
    return "Mage";
}

void Mage::attack(Character & target)
{
    int damage = attackPower + randomNumber(1, 6);

    cout << name << " casts a magic attack on " << target.getName() << "!" << endl;
    target.takeDamage(damage);
}

void Mage::specialAttack(Character & target)
{
    if(mana >= 25)
    {
        mana = mana - 25;

        int damage = attackPower + spellPower + randomNumber(5, 10);

        cout << name << " casts Fireball on " << target.getName() << "!" << endl;
        target.takeDamage(damage);
    }
    else
    {
        cout << name << " does not have enough mana!" << endl;
        attack(target);
    }
}

void Mage::defend()
{
    defending = true;
    cout << name << " creates a magic barrier!" << endl;
}

void Mage::updateDuringCombat()
{
    Character::updateDuringCombat();

    mana = mana + 10;

    if(mana > 100)
    {
        mana = 100;
    }
}

void Mage::printPortrait(const bool facingLeft) const
{
    if(facingLeft)
    {
        cout << MAGE_LEFT;
    }
    else
    {
        cout << MAGE_RIGHT;
    }
}

void Mage::printStats() const
{
    Character::printStats();

    cout << "Mana: " << mana << "/100" << endl;
    cout << "Spell Power: " << spellPower << endl;
}

void Mage::save(std::ofstream & out) const
{
    Character::save(out);

    out << "mana " << mana << endl;
    out << "spellPower " << spellPower << endl;
}

void Mage::load(std::ifstream & in)
{
    Character::load(in);

    string label;

    in >> label >> mana;
    in >> label >> spellPower;
}


// ==================== ROGUE ====================

Rogue::Rogue(const string & _name) : Character(_name, randomNumber(90, 110), randomNumber(12, 17), randomNumber(3, 5))
{
    energy = 100;
    critChance = randomNumber(20, 30);
}

string Rogue::getType() const
{
    return "Rogue";
}

void Rogue::attack(Character & target)
{
    int damage = attackPower + randomNumber(1, 8);

    int chance = randomNumber(1, 100);

    if(chance <= critChance)
    {
        damage = damage * 2;

        cout << name << " lands a critical hit on " << target.getName() << "!" << endl;
    }
    else
    {
        cout << name << " quickly attacks " << target.getName() << "!" << endl;
    }

    target.takeDamage(damage);
}

void Rogue::specialAttack(Character & target)
{
    if(energy >= 20)
    {
        energy = energy - 20;

        int damage = attackPower * 2 + randomNumber(5, 12);

        cout << name << " uses Backstab on " << target.getName() << "!" << endl;
        target.takeDamage(damage);
    }
    else
    {
        cout << name << " does not have enough energy!" << endl;
        attack(target);
    }
}

void Rogue::defend()
{
    defending = true;
    cout << name << " enters a dodge stance!" << endl;
}

void Rogue::updateDuringCombat()
{
    Character::updateDuringCombat();

    energy = energy + 15;

    if(energy > 100)
    {
        energy = 100;
    }
}

void Rogue::printPortrait(const bool facingLeft) const
{
    if(facingLeft)
    {
        cout << ROGUE_LEFT;
    }
    else
    {
        cout << ROGUE_RIGHT;
    }
}

void Rogue::printStats() const
{
    Character::printStats();

    cout << "Energy: " << energy << "/100" << endl;
    cout << "Critical Chance: " << critChance << "%" << endl;
}

void Rogue::save(std::ofstream & out) const
{
    Character::save(out);

    out << "energy " << energy << endl;
    out << "critChance " << critChance << endl;
}

void Rogue::load(std::ifstream & in)
{
    Character::load(in);

    string label;

    in >> label >> energy;
    in >> label >> critChance;
}
