#include <iostream>
#include <string>
#include <cstdlib>

#include "screen.h"

using namespace std;


// Dimensions
const int WIDTH 	= 20; // is doubled later for display
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
const string fruit_gfx = "\033[91;40m֍ \033[m";
coords fruit_coords = {0,0};

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

void clearContext(void){
	for(auto _ = HEIGHT - 2; _-->2;){
		printStringAt("                                        ", 2, _);
	}
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


int x = 0;

// TO DO
// solve flickering

void draw(void){
	// Reset cursor to 1, 1
	cout << "\033[2;3H";
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(fruit_coords.x == j && fruit_coords.y == i)
				cout << fruit_gfx;
			else
				cout << "  ";
		}
		cout << "\033[" << i+2 << ";3H";
	}
	//clearContext();
	
	
	fruit_coords.x += 2;
	fruit_coords.x %= WIDTH;
}