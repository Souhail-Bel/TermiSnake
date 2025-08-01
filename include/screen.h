#ifndef SCREEN_H
#define SCREEN_H

#include <string>

void printStringAt(std::string a, int x, int y);
void refreshScreen(void);

void initGame(void);
void exitGame(void);

void draw(void);

#endif