#ifndef LOGIC_H
#define LOGIC_H

using namespace std;

// Coords def
typedef struct coords{
	int x;
	int y;
} coords;

extern coords fruit_coords;

void updateFruitCoords(void);

#endif