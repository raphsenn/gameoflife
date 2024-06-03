
#pragma once

#include "./TerminalManager.h"


class GameOfLife{

private:
    // Size of the world.
    static const int MAXCELLS = 10000;

    // Current cell state and next cell state.
    bool currentCellState[MAXCELLS];
    bool nextCellState[MAXCELLS];

    // Pointer to current cell and next cell state.
    bool *currentCellStateP;
    bool *nextCellStateP;

    // Pointer to TerminalManager.
    TerminalManager *terminalManager_;

    // Booleans for running and break state.
    bool isRunning = true;
    bool isBreak = true;

    // Returns wether a cell is dead (false) or alive (true).
    bool cellIsAlive(int row, int col);

    // Updates cell state.
    void updateState();

    // Percepts user inputs and acts.
    void processUserInput(UserInput userInput);

    // Draw world, text and walls.    
    void draw();

public:
    // Constructor.
    GameOfLife(TerminalManager *terminalManager);

    // game loop.
    void run();
};

