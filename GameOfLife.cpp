
#include "./GameOfLife.h"

GameOfLife::GameOfLife(TerminalManager *terminalManager) { 
    terminalManager_ = terminalManager; 

    currentCellStateP = currentCellState; 
    nextCellStateP = nextCellState;    
}

void GameOfLife::run() {
    
    while (isRunning) {
        // Listen for user input. 
        UserInput userInput = terminalManager_->getUserInput();
        processUserInput(userInput);
        draw();
        terminalManager_->refresh(); 
    }

}

bool GameOfLife::cellIsAlive(int row, int col) {
    return *(currentCellStateP + col + row * terminalManager_->getRows());
}

void GameOfLife::processUserInput(UserInput userInput) {
    if (userInput.isPressed_q()) { isRunning = false; }
    else if (userInput.isPressed_Space()) {isBreak = !(isBreak); }
}

void GameOfLife::draw() {
    // Draw boarder.
    int COLS = terminalManager_->getCols();
    int ROWS = terminalManager_->getRows();
    for (int row = 0; row < ROWS; row++) {
        terminalManager_->drawPixel(row, 0, terminalManager_->White);
        terminalManager_->drawPixel(row, COLS - 1, terminalManager_->White);
    }
    for (int col = 0; col < COLS; col++) {
        terminalManager_->drawPixel(0, col, terminalManager_->White);
        terminalManager_->drawPixel(ROWS - 1, col, terminalManager_->White);
    }

    // Draw currentCellState
    // Cell alive: Yellow colored.
    // Cell dead: Purple colored.
    for (int row = 1; row < ROWS - 1; row++) {
        for (int col = 1; col < COLS - 1; col++) {
            if (cellIsAlive(row, col)) {
                terminalManager_->drawPixel(row, col, terminalManager_->Yellow);
            } else { terminalManager_->drawPixel(row, col, terminalManager_->Purple); }
        }
    }


}