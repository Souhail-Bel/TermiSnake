#include "logic.h"
#include "screen.h"

coords fruit_coords = {0, 0};

void updateFruitCoords(void){
	fruit_coords.x += 1;
	if(fruit_coords.x == WIDTH){
		fruit_coords.x = 0;
		fruit_coords.y += 1;
	}
	fruit_coords.y %= HEIGHT-1; // 0-indexed coords reminder
}