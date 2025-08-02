#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "screen.h"
#include "logic.h"


using namespace std;


// Dimensions
const int WIDTH 	= 20; // is doubled later for display
const int HEIGHT 	= 20;


// Empty backdrop
const string backdrop = "  ";

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


vector<string> disp_buffer(HEIGHT*WIDTH, backdrop);
vector<string> disp_buffer_prev(HEIGHT*WIDTH, backdrop);

constexpr int get_idx(int x, int y) {
	return y * WIDTH + x;
}

// 0-indexed coords sys
void printStringAt(string a, int x, int y){
	cout << "\033[" << y+1 << ';' << (x*2)+1 << "H" << a;
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
	
	// Initial screen cleanup
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
		printStringAt(boundary+boundary, WIDTH+1, i);
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


void update_buffer(void){
	// Copy current buffer to previous buffer
	copy(disp_buffer.begin(), disp_buffer.end(), disp_buffer_prev.begin());
	
	// Clear up current buffer
	fill(disp_buffer.begin(), disp_buffer.end(), backdrop);
	
	updateFruitCoords();
	
	disp_buffer[get_idx(fruit_coords.x, fruit_coords.y)] = fruit_gfx;
	
}

void render(void){
	cout << "\033[2;3H";
	
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			int idx = get_idx(j, i);
			if(disp_buffer[idx] != disp_buffer_prev[idx]){
				printStringAt(disp_buffer[idx], j+1, i+1);
			}
		}
	}
	
	cout.flush();
}