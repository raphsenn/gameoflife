// Author: Raphael Senn

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulation.h"

// ____________________________________________________________________________
int generation;
int num_cells_alive;
int const MAX_NUM_CELLS = 10000;
int SIM_SPEED = 50000;
int PROP_ALIVE = 5;

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
    init_pair(1, COLOR_BLACK, COLOR_BLACK); // COLOR_BLACK
    init_pair(2, COLOR_WHITE, COLOR_WHITE); // COLOR_WHITE
    init_pair(3, COLOR_WHITE, COLOR_BLACK); // TEXT_COLOR
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
                attron(COLOR_PAIR(2)); 
                mvprintw(row, 2 * col, "  "); }
                attroff(COLOR_PAIR(2)); 
        }
    }
}

// ____________________________________________________________________________
void draw_text(int x, int y, char text[], int number) {
    attron(COLOR_PAIR(3));
    mvprintw(x, y, text, number);
    attroff(COLOR_PAIR(3));
}

// ____________________________________________________________________________
void handle_user_input(int key) {
    /*
    Key space:  32 in ASCII
    Key q:      113 in ASCII
    Key r:      114 in ASCII
    */
    switch(key) {
        case 32: is_paused = !(is_paused); break;
        case 113: is_running = false; break;
        case 114: set_cells_random(PROP_ALIVE); break;
    }
}

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
        if (rand_cell_val == 0) { *(current_cells + cell) = 1; }
        else { *(current_cells + cell) = 0; }
    }
}

// ____________________________________________________________________________
int num_alive_neighors(int row, int col) {
    int aliveNeighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
        // Skip the current cell or cells outside the grid boundaries
        if ((i == row && j == col) || i < 0 || i >= y_cord || j < 0 || j >= x_cord) {
            continue;
        }
        if (get_cell(i, j) == 1) { aliveNeighbors++; }
        }
    }
  return aliveNeighbors;

}


// ____________________________________________________________________________
void next_generation() {
    for (int row = 0; row < y_cord; row++) {
        for (int col = 0; col < x_cord; col++) {
            int aliveNeighbors = num_alive_neighors(row, col);
            int currentCell = *(ptr_current_cells + col + row * x_cord);
            if (!currentCell && aliveNeighbors == 3) {
                *(ptr_next_cells + col + row * x_cord) = true;
            } else if (currentCell && aliveNeighbors < 2 || currentCell && aliveNeighbors > 3) {
                *(ptr_next_cells + col + row * x_cord) = false;
            } else {
                *(ptr_next_cells + col + row * x_cord) = currentCell;
            }
        }
    }
    // Switch pointers. 
    int* ptr_temp = ptr_current_cells;
    ptr_current_cells = ptr_next_cells;
    ptr_next_cells = ptr_temp;
}

// ____________________________________________________________________________
void run() {
    // Initialize terminal and game settings. 
    init_terminal();
    init_simulation();
    
    // Game loop.
    while (is_running) {
        int key = getch();
        handle_user_input(key); 

        // Drawing. 
        draw_cells();
        draw_text(0, 0, "Generation: ", generation);
        draw_text(0, 15, "Cells alive: ", num_cells_alive);
        
        next_generation(); 
        usleep(SIM_SPEED);
        generation++;
        
        // Pause loop.
        while (is_paused) {
        int key_pause = getch();
            handle_user_input(key); 
            draw_cells();
        }
    }
    // Closing ncurses.
    endwin();
}