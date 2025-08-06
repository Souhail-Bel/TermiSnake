#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "screen.h"
#include "logic.h"

using namespace std;

const int FRAMERATE = 20;
constexpr int FRAME_DELAY_MS = (1.0/FRAMERATE)*1e3;

bool is_running = false;

int snake_size = snake_tail.size();

int main(void){
	
	is_running = true;
	
	initGame();
	while(is_running){
		inputHandler();
		
		update_buffer();
		render();
		
		// Omitted since it works poorly
		// usleep((1.0/FRAMERATE)*1e6);
		this_thread::sleep_for(chrono::milliseconds(FRAME_DELAY_MS));
	}
	exitGame();
	
	cout << "Game over!" << endl;
	cout << "YOUR SCORE: " << snake_size * 10;
	
	return 0;
}