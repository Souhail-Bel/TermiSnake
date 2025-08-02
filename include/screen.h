#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

using namespace std;

// Dimensions
extern const int WIDTH;
extern const int HEIGHT;

// Elements display
extern const string backdrop;
extern const string boundary;
extern const string snake_head;
extern const string snake_body;
extern const string fruit_gfx;

// Display buffers
// Suggested by awss1236
// MASSIVELY helps with display since terminal I/O is sluggish
extern vector<string> disp_buffer;
extern vector<string> disp_buffer_prev;

constexpr int get_idx(int x, int y);
void printStringAt(string a, int x, int y);
void refreshScreen(void);
void initGame(void);
void exitGame(void);
void update_buffer(void);
void render(void);

#endif