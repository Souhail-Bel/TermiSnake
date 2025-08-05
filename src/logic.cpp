#include <random>
#include <unistd.h>
#include <deque>

#include "logic.h"
#include "screen.h"

random_device rd;  // a seed source for the random number engine
mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

// Random X Y coords
uniform_int_distribution<> randX(0, WIDTH-1);
uniform_int_distribution<> randY(0, HEIGHT-1);

coords fruit_coords = {0, 0};


deque<coords> snake_tail = {
	{WIDTH/2, HEIGHT/2},
	{(WIDTH/2)+1, HEIGHT/2}
};
coords snake_head_coords = {(WIDTH/2)-1, HEIGHT/2};

int snake_size = 3;

enum Direction {
	NONE = 0,
	UP, DOWN,
	RIGHT, LEFT
};

Direction dir = NONE;


void inputHandler(void){
	char c = 0;
	
	read(STDIN_FILENO, &c, 1);
	
	// If not going the opposite direction, follow
	// X is to exit
	switch(c) {
		case 'z':
			if(dir != DOWN) 	dir = UP;
			break;
		case 's':
			if(dir != UP) 		dir = DOWN;
			break;
		case 'd':
			if(dir != LEFT) 	dir = RIGHT;
			break;
		case 'q':
			if(dir != RIGHT) 	dir = LEFT;
			break;
		case 'x':
			is_running = false;
			break;
	}
}


void updateSnake(void){	
	snake_tail.pop_back();
	snake_tail.push_front(snake_head_coords);
	
	++snake_head_coords.x;
	snake_head_coords.x %= WIDTH;
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