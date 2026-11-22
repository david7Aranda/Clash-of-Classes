// UI.cpp

#include "UI.h"
#include "Art.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

void printTitle()
{
    cout << TITLE_ART << endl;
}

void printDivider()
{
    cout << "========================================" << endl;
}

void printBox(const std::string & text)
{
    string border = "+" + string(text.length() + 2, '-') + "+";

    cout << border << endl;
    cout << "| " << text << " |" << endl;
    cout << border << endl;
}

void printHealthBar(const int current, const int max)
{
    int filled = 0;

    if(max > 0)
    {
        filled = current * 20 / max;
    }

    if(filled < 0)
    {
        filled = 0;
    }

    if(filled > 20)
    {
        filled = 20;
    }

    cout << "[";

    for(int i = 0; i < filled; i++)
    {
        cout << "#";
    }

    for(int i = filled; i < 20; i++)
    {
        cout << "-";
    }

    cout << "] " << current << "/" << max << endl;
}

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

std::string readName()
{
    string name;

    while(true)
    {
        cout << "Enter your name: ";
        getline(cin, name);

        if(name != "")
        {
            return name;
        }

        cout << "Name cannot be empty." << endl;
    }
}

int randomNumber(const int min, const int max)
{
    int number = min + rand() % (max - min + 1);

    return number;
}

void waitForEnter()
{
    cout << "Press Enter to continue..." << endl;

    string input;
    getline(cin, input);
}
