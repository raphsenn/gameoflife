// Author: Raphael Senn

#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdbool.h>

// ____________________________________________________________________________
// Global variables.
// ____________________________________________________________________________

// Cell settings.

// Current cell generation.
extern int generation;
extern int num_cells_alive;
extern const int MAX_NUM_CELLS;

// Cells current generation.
extern int current_cells[];
extern int *ptr_current_cells;

// Cells next generation.
extern int next_cells[];
extern int *ptr_next_cells;

// Window settings.

extern int x_cord;
extern int y_cord;

extern bool is_running; // Simulation loop.
extern bool is_paused; // Simulation paused.

// ____________________________________________________________________________
// Terminal stuff.
// ____________________________________________________________________________

// Initialize the terminal.
void init_terminal();

// Initialize simulation.
void init_simulation();

// Draw pixel at give position x and y.
void draw_cells();

// Draw text at give position x and y.
void draw_text(int x, int y, char text[]);

// Returns cell state.
int get_cell(int x, int y);

// Set cell state to a value.
void set_cell(int x, int y, int cell_value);

// Sets randomly (with given probability) cell states to alive.
// prob 1 = 1.0
// prob 2 = 0.5
// prob 3 =0.33..
// prob 5 = 0.2
// prob n = 1 / n
void set_cells_random(int prob);

// Changes pointers from current cell to next cell.
void next_generation();

// Starts the simulation.
void run();

#endif // SIMULATION_H