#ifndef LOGIC_H
#define LOGIC_H

using namespace std;

extern bool is_running;

// Coords def
typedef struct coords{
	int x;
	int y;
} coords;


extern coords fruit_coords;

void inputHandler(void);
void updateFruitCoords(void);

#endif