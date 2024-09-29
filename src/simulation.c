// Author: Raphael Senn

#include <ncurses.h>

#include "simulation.h"

// ____________________________________________________________________________
int generation;
int num_cells_alive;
int const MAX_NUM_CELLS = 10000;

int current_cells[MAX_NUM_CELLS];
int *ptr_current_cells;

int next_cells[MAX_NUM_CELLS];
int *ptr_next_cells;

int x_cord;
int y_cord;

bool is_paused;
bool is_running;


// ____________________________________________________________________________
void init_terminal() {
    initscr(); // Starting ncurses mode.
    curs_set(false);
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // White cell: alive, dead cell: black
    init_pair(2, COLOR_BLACK, COLOR_BLACK); // Background
}

// ____________________________________________________________________________
void init_simulation() {
    x_cord = COLS / 2;
    y_cord = LINES;
    is_paused = false;
    is_running = true;

    ptr_current_cells = &current_cells;
    ptr_next_cells = &next_cells;
    generation = 1;
    num_cells_alive = 0;
}

