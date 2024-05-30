
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


}



void GameOfLife::processUserInput(UserInput userInput) {
    if (userInput.isPressed_q()) { isRunning = false; }
    else if (userInput.isPressed_Space()) {isBreak = !(isBreak); }

}

