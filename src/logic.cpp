#include <random>
#include <unistd.h>

#include "logic.h"
#include "screen.h"

random_device rd;  // a seed source for the random number engine
mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

// Random X Y coords
uniform_int_distribution<> randX(0, WIDTH-1);
uniform_int_distribution<> randY(0, HEIGHT-1);

coords fruit_coords = {0, 0};


void inputHandler(void){
	char c = 0;
	
	read(STDIN_FILENO, &c, 1);
	
	switch(c) {
		case 'x': is_running = false; break;
	}
}


void updateFruitCoords(void){

	
	// fruit_coords.x += 1;
	// if(fruit_coords.x == WIDTH){
		// fruit_coords.x = 0;
		// fruit_coords.y += 1;
	// }
	// fruit_coords.y %= HEIGHT-1; // 0-indexed coords reminder
	
	fruit_coords.x = randX(gen);
	fruit_coords.y = randY(gen);
}