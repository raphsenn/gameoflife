
#pragma once

#include "./TerminalManager.h"


class GameOfLife{

private:
    // Pointer to TerminalManager object.
    TerminalManager *terminalManager_;

    // Booleans for running and break state.
    bool isRunning = true;
    bool isBreak = true;

    void processUserInput(UserInput userInput);

public:
    // Constructor.
    GameOfLife(TerminalManager *terminalManager);

    void run();
};

