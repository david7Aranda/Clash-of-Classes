// UI.cpp

#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void printTitle()
{
    // Print the title banner from art/ascii_art.txt (use a raw string).
}

void printDivider()
{
    // Print a line of '=' characters.
}

void printBox(const std::string & text)
{
    // Print text inside a box: a +-----+ line above and below, | text | in the middle.
    // Tip: std::string(n, '-') makes a string of n dashes.
}

void printHealthBar(const int current, const int max)
{
    // Print something like [##########----------] 50/100.
    // The number of # is current * 20 / max.
}

int readChoice(const int min, const int max)
{
    // Ask for a number until the user types one from min to max.
    // If cin fails (they typed letters), use cin.clear() and cin.ignore(...) to reset it.
}

std::string readName()
{
    // Ask for a name with getline, and ask again if it's empty.
    // Tip: after cin >> number, call cin.ignore() before getline.
}

int randomNumber(const int min, const int max)
{
    // Return a random number from min to max (including both).
    // Tip: min + rand() % (max - min + 1). Seed once in main with srand(time(0)).
}

void waitForEnter()
{
    // Print "Press Enter to continue..." and wait for Enter.
}