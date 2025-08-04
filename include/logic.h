#ifndef LOGIC_H
#define LOGIC_H

#include <deque>

using namespace std;

extern bool is_running;

// Coords def
typedef struct coords{
	int x;
	int y;
} coords;


extern coords fruit_coords;
extern coords snake_head_coords;

extern deque<pair<int, int>> snake_tail;
extern int snake_size;

void inputHandler(void);
void updateSnake(void);
void updateFruitCoords(void);

#endif