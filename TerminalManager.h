
#pragma once

#include <ncurses.h>

class TerminalManager {

public:
    // Constructor, starting ncurses and initialize terminal.
    TerminalManager();
    
    // Destructor, close ncurses.
    ~TerminalManager();

private:
    int numRows_;
    int numCols_;

};

