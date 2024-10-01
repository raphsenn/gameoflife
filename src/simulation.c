// Author: Raphael Senn

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulation.h"

int generation;
int num_cells_alive;
int const MAX_NUM_CELLS = 15000;
int SIM_SPEED;
int PROP_ALIVE;

int current_cells[MAX_NUM_CELLS];
int *ptr_current_cells;

int next_cells[MAX_NUM_CELLS];
int *ptr_next_cells;

int x_cord_term;
int y_cord_term;

int x_cord_sim;
int y_cord_sim;

bool is_paused;
bool is_running;

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

void init_simulation() {
    x_cord_term = COLS / 2;
    y_cord_term = LINES;

    x_cord_sim = x_cord_term;
    y_cord_sim= y_cord_term; 
    
    is_paused = true;
    is_running = true;

    ptr_current_cells = &current_cells;
    ptr_next_cells = &next_cells;
    generation = 1;
    num_cells_alive = 0;
    SIM_SPEED = 100000; 
    PROP_ALIVE = 8;
    set_cells_random(PROP_ALIVE);
}

void draw_cells() {
    for (int row = 0; row < y_cord_sim; row++) {
        for (int col = 0; col < x_cord_sim; col++) {
            int current_cell_state = get_cell(row, col);
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

void draw_text(int row, int col, char text[], int number) {
    attron(COLOR_PAIR(3));
    mvprintw(row, col, text, number);
    attroff(COLOR_PAIR(3));
}

void handle_user_input(int key) {
    /*
    Key q:      113 in ASCII
    Key r:      114 in ASCII
    Key space:  160 in ASCII
    */
    switch(key) {
        case 113: is_running = false; break;
        case 114: set_cells_random(PROP_ALIVE); generation = 0; num_cells_alive = get_cells_alive(); break;
        case 32: is_paused = !(is_paused); break;
    }
}

int get_cell(int row, int col) {
    return *(current_cells + col + row * x_cord_sim);
}

void set_cell(int row, int col, int cell_value) {
    *(current_cells + col + row * x_cord_sim) = cell_value;
}

void set_cells_random(int prob) {
    for (int cell=0; cell < MAX_NUM_CELLS; cell++) {
        *(current_cells + cell) = (rand() % prob == 0) ? 1 : 0; 
    }
}

int num_alive_neighors(int row, int col) {
    int alive_neighbors = 0;
    for (int y = row - 1; y <= row + 1; y++) {
        for (int x = col - 1; x <= col + 1; x++) {
        // Skip the current cell or cells outside the grid boundaries
        if ((y == row && x == col) || y < 0 || y >= y_cord_sim || x < 0 || x >= x_cord_sim) {
            continue;
        }
        if (get_cell(y, x) == 1) { alive_neighbors++; }
        }
    }
    return alive_neighbors;
}

int get_cells_alive() {
    int living_cells = 0; 
     for (int row = 0; row < y_cord_sim; row++) {
        for (int col = 0; col < x_cord_sim; col++) { 
            if (*(current_cells + row + col * x_cord_sim) == 1) { living_cells++; }
        }
    }
    return living_cells;
}

void next_generation() {
    for (int row = 0; row < y_cord_sim; row++) {
        for (int col = 0; col < x_cord_sim; col++) {
            int alive_neighbors = num_alive_neighors(row, col);
            int current_cell = *(ptr_current_cells + col + row * x_cord_sim);
            if (current_cell + alive_neighbors == 3) {
                *(ptr_next_cells + col + row * x_cord_sim) = 1;
            } else if (current_cell && alive_neighbors < 2 || current_cell && alive_neighbors > 3) {
                *(ptr_next_cells + col + row * x_cord_sim) = 0;
            } else {
                *(ptr_next_cells + col + row * x_cord_sim) = current_cell;
            }
        }
    }
    // Switch pointers.
    int* ptr_temp = ptr_current_cells;
    ptr_current_cells = ptr_next_cells;
    ptr_next_cells = ptr_temp;
}

void render_frame() {
    draw_cells();
    draw_text(0, 0, "Generation: %d", generation);
    draw_text(0, 20, "Cells alive: %d", num_cells_alive);
    draw_text(0, 40, "Paused: %d", is_paused);
}

void run() {
    // Initialize terminal and game settings. 
    init_terminal();
    init_simulation();

    // Game loop.
    while (is_running) {
        // Pause loop.
        while (is_paused && is_running) {
            int key_pause = getch();
            handle_user_input(key_pause); 
            render_frame(); 
        }
        int key = getch();
        handle_user_input(key); 
        num_cells_alive = get_cells_alive();
        render_frame(); 
        next_generation(); 
        usleep(SIM_SPEED);
        generation++;
    }
    // Closing ncurses.
    endwin();
}