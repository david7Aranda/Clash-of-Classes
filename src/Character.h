// Character.h
// Character: the base class for every character type.
//
// What goes here:
//  - The stats every character keeps track of: name, level, health, XP, and
//    anything else every type shares.
//  - Five interaction functions that change those stats (for example: rest,
//    use a healing item, gain XP and level up, take damage, ...).
//  - A function that updates the character during combat (each turn), and
//    one for after combat.
//  - Save and load functions that write the character's data to a file and
//    read it back.
//  - The things each type does differently (attack, defend, a special
//    ability, the messages it prints). Make those virtual so each type can
//    override them.
