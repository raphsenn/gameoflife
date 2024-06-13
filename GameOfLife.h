
#pragma once

#include "./TerminalManager.h"


class GameOfLife{

private:
    int numRows_; // Num cells in row.
    int numCols_; // Num cells in col.

    int lastClickedRow_;
    int lastClickedCol_;

    // Size of the world.
    static const int MAXCELLS = 1000000;

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
    bool getCell(int row, int col);

    // Set cell at row, col.
    void setCell(int row, int col);

    // Returns number of alive neighbors of a cell.
    int numAliveNeighbors(int row, int col);

    // Initializes cells randomly.
    void setCellsRandomly(int probability=2);

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

