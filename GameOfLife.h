
#pragma once

#include "./TerminalManager.h"


class GameOfLife{

private:
    // Pointer to TerminalManager object.
    TerminalManager *terminalManager_;

    bool isRunning = true;

public:
    // Constructor.
    GameOfLife(TerminalManager &terminalManager);

    void initGame();
    void run();
};

