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
		case 'w':
			if(dir != DOWN) 	dir = UP;
			break;
		case 's':
			if(dir != UP) 		dir = DOWN;
			break;
		case 'd':
			if(dir != LEFT) 	dir = RIGHT;
			break;
		case 'a':
			if(dir != RIGHT) 	dir = LEFT;
			break;
		case 'x':
			is_running = false;
			break;
	}
}


void updateSnake(void){	
	// [[likely]] is C++20 since, but the std here is C++11
	// So we're using the GCC/Clang __builtin_expect function instead
	if(__builtin_expect(dir != NONE, 1)){
		snake_tail.pop_back();
		snake_tail.push_front(snake_head_coords);
	}
	
	
	// Reminder that (0,0) is on the top left
	// This means that the signs are switched for the y-axis
	switch(dir){
		case UP:
			--snake_head_coords.y;
			if(snake_head_coords.y < 0) snake_head_coords.y = HEIGHT-1;
			break;
		case DOWN:
			++snake_head_coords.y;
			break;
		case RIGHT:
			++snake_head_coords.x;
			break;
		case LEFT:
			--snake_head_coords.x;
			if(snake_head_coords.x < 0) snake_head_coords.x = WIDTH-1;
			break;
	}
	
	snake_head_coords.x %= WIDTH;
	snake_head_coords.y %= HEIGHT;
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