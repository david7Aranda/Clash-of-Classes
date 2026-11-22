// UI.cpp
// Each commented-out function below has a note saying what it should do.
// When you write one, replace its commented version with your real code.

#include "UI.h"
#include "Art.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iostream>

using namespace std;

void printTitle()
{
    cout << TITLE_ART << endl;
}

// void printDivider()
// {
//     // Print a line of '=' characters.
// }

// void printBox(const std::string & text)
// {
//     // Print text inside a box: a +-----+ line above and below, | text | in the middle.
//     // Tip: std::string(n, '-') makes a string of n dashes.
// }

// void printHealthBar(const int current, const int max)
// {
//     // Print something like [##########----------] 50/100.
//     // The number of # is current * 20 / max.
// }

int readChoice(const int min, const int max)
{
    int choice;
    while (true)
    {
        cout << "Choose an option: ";
        if (cin >> choice)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice >= min && choice <= max)
            {
                return choice;
            }
            cout << "Invalid choice." << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Not a number." << endl;
        }
    }
}

// std::string readName()
// {
//     // Ask for a name with getline, and ask again if it's empty.
//     // Tip: after cin >> number, call cin.ignore() before getline.
// }

// int randomNumber(const int min, const int max)
// {
//     // Return a random number from min to max (including both).
//     // Tip: min + rand() % (max - min + 1). Seed once in main with srand(time(0)).
// }

// void waitForEnter()
// {
//     // Print "Press Enter to continue..." and wait for Enter.
// }
