#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "screen.h"

using namespace std;

const int FRAMERATE = 60;

bool is_running = false;

int main(void){
	
	is_running = true;
	
	
	while(is_running){
		refreshScreen();
		printCharAt('#', 1, 5);
		printCharAt('@', 10, 10);
		
		usleep((1.0/FRAMERATE)*1e6);
	}
	
	return 0;
}