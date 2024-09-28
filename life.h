// Author: Raphael Senn

#ifndef LIFE_H
#define LIFE_H

#include <ncurses.h>

// ____________________________________________________________________________
// Global variables.
// ____________________________________________________________________________

// Cell settings.

// Current cell generation.
extern int generation;
const int MAX_NUM_CELLS = 10000;

// Cells current generation.
extern bool current_cells[MAX_NUM_CELLS];
extern bool *ptr_current_cells;

// Cells next generation.
extern bool next_cells[MAX_NUM_CELLS];
extern bool *ptr_next_cells;

// Window settings.

extern int x_cord;
extern int y_cord;

extern bool is_running; // Simulation loop.
extern bool is_paused; // Simulation paused.

// ____________________________________________________________________________
// Functions.
// ____________________________________________________________________________

// Initialize the terminal.
void init_terminal();

// Initialize simulation.
void init_simulation();

// Returns cell state.
bool get_cell();

// Inverts cell state.
bool invert_cell();

// Sets randomly (with given probability) cell states to alive.
void set_cells_random(float prob);

#endif // LIFE_h