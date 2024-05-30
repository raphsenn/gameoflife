
#pragma once

#include <ncurses.h>
#include "./UserInput.h"

// Define color components for purple.
#define PURPLE_R 700
#define PURPLE_G 0
#define PURPLE_B 700

class TerminalManager {

public:

    static int White;
    static int Black;
    static int Purple;
    static int Yellow;

    // Constructor, starting ncurses and initialize terminal.
    TerminalManager();
    
    // Destructor, close ncurses.
    ~TerminalManager();

    int getRows();
    int getCols();

    // Draw pixel.
    void drawPixel(int row, int col, int color);
    void refresh();

    // Tracking user input.
    UserInput getUserInput();

private:
    int numRows_;
    int numCols_;

};

