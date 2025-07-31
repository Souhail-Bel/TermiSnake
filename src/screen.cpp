#include <iostream>
#include <string>

#include "screen.h"

using namespace std;

// Solid boundary block
const string boundary = "█";

// Double characters (or wide) are used
// because terminal characters are longer
// than they are wider

// Green snake (not MGS)
// ▒▒▒▒▒▒▓▓  ֍ 
const string snake_head = "\033[32;40m▓▓\033[m";
const string snake_body = "\033[32;40m▒▒\033[m";
// Bright red fruit
const fruit = "\033[91;40m֍ \033[m"

void refreshScreen(void){
	#ifdef _WIN32
		system("cls");		// Windows
	#else
		system("clear");	// Unix
	#endif
}

// TODO:
// Make it so it goes through the entire
// HEIGHT*WIDTH of the screen
// if the character is to draw
	// draw it
// else
	// draw space
// such that I wouldn't have to refresh the screen
// when I can just overwrite it (Solves flickering)

void draw(void){
	refreshScreen();
	
	cout << "\033[" << y << ";" << x << "H" << c;
}