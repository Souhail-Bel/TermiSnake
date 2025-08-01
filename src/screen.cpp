#include <iostream>
#include <string>
#include <cstdlib>

#include "screen.h"

using namespace std;


// Dimensions
const int WIDTH 	= 20; // is doubled later
const int HEIGHT 	= 20;





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
const string fruit = "\033[91;40m֍ \033[m";


// 0-indexed coords sys
void printStringAt(string a, int x, int y){
	cout << "\033[" << y+1 << ';' << x+1 << "H" << a;
}

void refreshScreen(void){
	#ifdef _WIN32
		system("cls");		// Windows
	#else
		system("clear");	// Unix
	#endif
}

void initGame(void){
	// exitGame at exit.
	atexit(exitGame);
	
	refreshScreen();
	// Hide cursor
	cout << "\033[?25l";
	
	// Draw top boundary box
	for(auto _ = WIDTH*2 + 4; _--;)
		cout << boundary;
	cout << endl;
	
	// Draw sides of boundary box
	for(int i = 0; i < HEIGHT; i++){
		printStringAt(boundary+boundary, 0, i);
		printStringAt(boundary+boundary, (WIDTH*2)+2, i);
	}
	
	// Draw bottom boundary box
	printStringAt("", 0, HEIGHT);
	for(auto _ = WIDTH*2 + 4; _--;)
		cout << boundary;
	cout << endl;
}


void exitGame(void){
	// Show  cursor
	cout << "\033[?25h";
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
	// Reset cursor to 1, 1
	cout << "\033[H";
	
	
}