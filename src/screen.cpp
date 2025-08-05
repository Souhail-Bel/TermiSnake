#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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

void nonBlockingInput(void){
	struct termios orig_term, new_term;
	tcgetattr(STDIN_FILENO, &orig_term);
	new_term = orig_term;
	// Disable canon mode and echo
	//new_term.c_lflag &= ~(ICANON | ECHO);
	new_term.c_iflag &= ~(IXON | ICRNL);
	new_term.c_oflag &= ~(OPOST);
	new_term.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	// TCSANOW: the change should take place immediately
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	// Directly modify the file descriptor STDIN_FILENO's operating mode O_NONBLOCK
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void initGame(void){
	
	// Initial screen cleanup
	refreshScreen();
	
	// Set input to non-blocking + other fixes
	nonBlockingInput();
	
	// Hide cursor
	cout << "\033[?25l";
	
	// Draw top boundary box
	for(auto _ = WIDTH*2 + 4; _--;)
		cout << boundary;
	cout << endl;
	
	// Draw sides of boundary box
	for(int i = 0; i <= HEIGHT; i++){
		printStringAt(boundary+boundary, 0, i);
		printStringAt(boundary+boundary, WIDTH+1, i);
	}
	
	// Draw bottom boundary box
	printStringAt("", 0, HEIGHT+1);
	for(auto _ = WIDTH*2 + 4; _--;)
		cout << boundary;
	cout << endl;
	
	// Controls UI
	printStringAt("WASD - Move, ✗ - Exit", WIDTH/4, HEIGHT+2);
}

void restoreInput(void){
	struct termios curr_term;
	tcgetattr(STDIN_FILENO, &curr_term);
	// curr_term.c_lflag |= (ICANON | ECHO);
	curr_term.c_iflag |= (IXON | ICRNL);
	curr_term.c_oflag |= (OPOST);
	curr_term.c_lflag |= (ECHO | ICANON | ISIG | IEXTEN);
	tcsetattr(STDIN_FILENO, TCSANOW, &curr_term);
}

void exitGame(void){
	// Show  cursor
	cout << "\033[?25h";
	refreshScreen();
	restoreInput();
}


void update_buffer(void){
	// Copy current buffer to previous buffer
	copy(disp_buffer.begin(), disp_buffer.end(), disp_buffer_prev.begin());
	
	// Clear up current buffer
	fill(disp_buffer.begin(), disp_buffer.end(), backdrop);
	
	
	
	// Get next fruit
	// updateFruitCoords();
	
	// Fruit display
	// disp_buffer[
		// get_idx(fruit_coords.x,
				// fruit_coords.y)
	// ] = fruit_gfx;
	
	
	// Move snake logic
	updateSnake();	
	
	
	// Snake display
		
	for(auto part : snake_tail){
		disp_buffer[
			get_idx(part.x,
					part.y)
		] = snake_body;
	}
	
	disp_buffer[
		get_idx(snake_head_coords.x,
				snake_head_coords.y)
	] = snake_head;
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