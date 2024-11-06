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
extern int SIM_SPEED;
extern int PROP_ALIVE;

// Cells current generation.
extern int current_cells[];
extern int *ptr_current_cells;

// Cells next generation.
extern int next_cells[];
extern int *ptr_next_cells;

// Window settings.

// Maximal x, y coordinates of the window.
extern int x_cord;
extern int y_cord;

// For checking, if game is paused or running.
extern bool is_running;
extern bool is_paused;

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
void draw_text(int row, int col, char text[], int number);

// Catching user input (keys pressed).
void handle_user_input(int key);

// Returns cell state.
int get_cell(int row, int col);

// Set cell state to a value.
void set_cell(int row, int col, int cell_value);

// Sets randomly (with given probability) cell states to alive.
// prob 1 = 1.0
// prob 2 = 0.5
// prob 3 =0.33..
// prob 5 = 0.2
// prob n = 1 / n
void set_cells_random(int prob);

// Returns number of alive neighbors of a cell.
int num_alive_neighbors(int row, int col);

// Returns number of living cells.
int get_cells_alive();

// Changes pointers from current cell to next cell.
void next_generation();

// Drawing.
void render_frame();

// Starts the simulation.
void run();

#endif // SIMULATION_H