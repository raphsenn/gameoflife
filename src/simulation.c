// Author: Raphael Senn

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

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

// ____________________________________________________________________________
void draw_cells() {
    for (int row = 0; row < y_cord; row++) {
        for (int col = 0; col < x_cord; col++) {
            int current_cell_state = get_cell(col, row);
            // Cell is dead. 
            if (current_cell_state == 0) {
                attron(COLOR_PAIR(1)); 
                mvprintw(row, 2 * col, "  ");
                attroff(COLOR_PAIR(1)); 
            }
            // Cell is alive.
            else if (current_cell_state == 1) {
                attron(COLOR_PAIR(1)); 
                mvprintw(row, 2 * col, "  "); }
                attroff(COLOR_PAIR(1)); 
        }
    }
}

// ____________________________________________________________________________
void draw_text(int x, int y, char text[]) {}

// ____________________________________________________________________________
int get_cell(int x, int y) {
    return *(current_cells + y + x_cord * x);
}

// ____________________________________________________________________________
void set_cell(int x, int y, int cell_value) {
    *(current_cells + y + x_cord * x) = cell_value;
}

// ____________________________________________________________________________
void set_cells_random(int prob) {
    for (int cell=0; cell < MAX_NUM_CELLS; cell++) {
        int rand_cell_val = rand() % prob;
        if (rand_cell_val == 0) {*(current_cells + cell) = 0;}
        else { *(current_cells + cell) = 1; }
    }
}

// ____________________________________________________________________________
void next_generation() {}

// ____________________________________________________________________________
void run() {
    init_terminal();
    init_simulation();
    set_cells_random(5);
    int speed = 50000; // 50 Milliseconds.
    // Game loop.
    while (is_running) {
        int key = getch();
        // bool userInput = processUserInput(key);
        // showState();
        draw_cells();
        // updateState();
        usleep(speed);
        generation++;
        // Game paused.
        while (is_paused) {
        int key_pause = getch();
        // bool userInput = processUserInput(key_pause);
        // showState();
        }
    }
    endwin();
}