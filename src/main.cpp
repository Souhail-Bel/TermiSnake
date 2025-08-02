#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "screen.h"

using namespace std;

const int FRAMERATE = 10;
constexpr int FRAME_DELAY_MS = (1.0/FRAMERATE)*1e3;

bool is_running = false;

int main(void){
	
	is_running = true;
	
	initGame();
	while(is_running){
		update_buffer();
		render();
		
		// Omitted since it works poorly
		// usleep((1.0/FRAMERATE)*1e6);
		this_thread::sleep_for(chrono::milliseconds(FRAME_DELAY_MS));
	}
	
	return 0;
}