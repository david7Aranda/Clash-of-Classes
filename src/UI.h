// UI.h
// UI helpers: plain functions (not a class) for menus, boxes, input and random numbers.

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

void printTitle();
void printDivider();
void printBox(const std::string & text);
void printHealthBar(const int current, const int max);
int readChoice(const int min, const int max);
string readName();
int randomNumber(const int min, const int max);
void waitForEnter();

#endif