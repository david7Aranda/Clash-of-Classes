// Art.h
// ASCII art for Clash of Classes, as C++ raw strings.
// The art was created by Claude (an AI assistant made by Anthropic), and Claude
// also typed it into this file. The banners use the FIGlet "small" font.
//
// How to use: #include "Art.h" in any .cpp file, then print a picture with
//     std::cout << TITLE_ART;
// R"( ... )" is a raw string: every character between the brackets is kept
// exactly as written, so backslashes don't need to be doubled.
// Each picture starts and ends with a line break.

#ifndef ART_H
#define ART_H

#include <string>

// Title banner, one line (72 characters wide)
const std::string TITLE_ART = R"(
  ___ _      _   ___ _  _    ___  ___    ___ _      _   ___ ___ ___ ___
 / __| |    /_\ / __| || |  / _ \| __|  / __| |    /_\ / __/ __| __/ __|
| (__| |__ / _ \\__ \ __ | | (_) | _|  | (__| |__ / _ \\__ \__ \ _|\__ \
 \___|____/_/ \_\___/_||_|  \___/|_|    \___|____/_/ \_\___/___/___|___/
)";

// Title banner, stacked (for narrow screens)
const std::string TITLE_ART_STACKED = R"(
  ___ _      _   ___ _  _
 / __| |    /_\ / __| || |
| (__| |__ / _ \\__ \ __ |
 \___|____/_/ \_\___/_||_|

  ___  ___    ___ _      _   ___ ___ ___ ___
 / _ \| __|  / __| |    /_\ / __/ __| __/ __|
| (_) | _|  | (__| |__ / _ \\__ \__ \ _|\__ \
 \___/|_|    \___|____/_/ \_\___/___/___|___/
)";

// Shown between the two fighters
const std::string VS_ART = R"(
__   _____
\ \ / / __|
 \ V /\__ \
  \_/ |___/
)";

// Shown when the player wins
const std::string VICTORY_ART = R"(
__   _____ ___ _____ ___  _____   ___
\ \ / /_ _/ __|_   _/ _ \| _ \ \ / / |
 \ V / | | (__  | || (_) |   /\ V /|_|
  \_/ |___\___| |_| \___/|_|_\ |_| (_)
)";

// Shown when the player loses
const std::string DEFEAT_ART = R"(
 ___  ___ ___ ___   _ _____
|   \| __| __| __| /_\_   _|
| |) | _|| _|| _| / _ \| |
|___/|___|_| |___/_/ \_\_|
)";

// Warrior portrait facing right (the player)
const std::string WARRIOR_RIGHT = R"(
     ,_____,
     |[o o]|  /
     \_____/ /
  [#]--|W|--+
  [#]  |_|
       / \
)";

// Warrior portrait facing left (the opponent)
const std::string WARRIOR_LEFT = R"(
   ,_____,
\  |[o o]|
 \ \_____/
  +--|W|--[#]
     |_|  [#]
     / \
)";

// Mage portrait facing right (the player)
const std::string MAGE_RIGHT = R"(
       /\      *
      /  \    (O)
     /____\    |
     (o  o)    |
    _/ ~~ \_---+
   /________\  |
)";

// Mage portrait facing left (the opponent)
const std::string MAGE_LEFT = R"(
 *      /\
(O)    /  \
 |    /____\
 |    (o  o)
 +---_/ ~~ \_
 |  /________\
)";

// Rogue portrait facing right (the player)
const std::string ROGUE_RIGHT = R"(
      _____
     / ___ \
    | (o.o) |
     \_`-'_/
  <=-/|   |\-=>
     /_____\
)";

// Rogue portrait facing left (the opponent)
const std::string ROGUE_LEFT = R"(
    _____
   / ___ \
  | (o.o) |
   \_`-'_/
<=-/|   |\-=>
   /_____\
)";

#endif
