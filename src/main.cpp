#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "screen.h"

using namespace std;

const int FRAMERATE = 20;

bool is_running = false;

int main(void){
	
	is_running = true;
	
	initGame();
	// while(is_running){
		// draw();
		
		// usleep((1.0/FRAMERATE)*1e6);
	// }
	
	return 0;
}