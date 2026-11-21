# Clash of Classes

A text-based RPG duel game in C++. Pick a Warrior, Mage or Rogue, name your
hero, and fight duels against computer opponents. Work in progress.

## Build and run

```bash
make
./clash_of_classes
```

Or without make: `g++ -std=c++17 src/*.cpp -o clash_of_classes`

## Progress checklist

- [ ] `Character` base class with name, level, health and other shared stats
- [ ] Five interaction functions that change a character's stats
- [ ] A function that updates a character during combat, and one after combat
- [ ] Save and load a character to and from a file
- [ ] Warrior, Mage and Rogue derived from `Character`, each with its own variables, messages, attack and defense
- [ ] Each type overrides save and load for its own variables
- [ ] Main menu: choose a character type (with a short description) or load one from a file
- [ ] New character: pick a type and a name, with random starting stats
- [ ] Duel against an opponent: attack or special, defend, flee
- [ ] Save, load and exit from the menu; keep offering duels until the player exits
- [ ] Comments explaining each class and section
- [ ] ASCII menus

## Credits

The ASCII art in `art/ascii_art.txt` (banners and portraits) was created by Claude,
an AI assistant made by Anthropic; the banners use the FIGlet "small" font. The file
layout and the plain-English notes at the top of each file were also set up with
Claude's help. The game code is my own work.
