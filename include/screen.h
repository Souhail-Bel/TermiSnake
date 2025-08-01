#ifndef SCREEN_H
#define SCREEN_H

#include <string>

// Dimensions
extern const int WIDTH;
extern const int HEIGHT;

// Coords def
typedef struct coords{
	int x;
	int y;
} coords;

// Elements display
extern const std::string boundary;
extern const std::string snake_head;
extern const std::string snake_body;
extern const std::string fruit_gfx;

// Indiv coords

void printStringAt(std::string a, int x, int y);
void refreshScreen(void);
void clearContext(void);
void initGame(void);
void exitGame(void);
void draw(void);

#endif