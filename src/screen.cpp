#include <iostream>

#include "screen.h"

using namespace std;

void refreshScreen(void){
	// 		Clear Disp	Reset Cursor
	cout << "\033[2J" << "\033[H";
}

void printCharAt(char c, int x, int y){
	cout << "\033[" << y << ";" << x << "H" << c;
}