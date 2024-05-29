
#pragma once

#include <ncurses.h>

#include "./UserInput.h"

class TerminalManager {

public:
    // Constructor, starting ncurses and initialize terminal.
    TerminalManager();
    
    // Destructor, close ncurses.
    ~TerminalManager();

    // Tracking user input.
    UserInput getUserInput();

private:
    int numRows_;
    int numCols_;

};

