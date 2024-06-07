
#include "./GameOfLife.h"

#include <cstdlib>

GameOfLife::GameOfLife(TerminalManager *terminalManager) { 
    terminalManager_ = terminalManager; 

    currentCellStateP = currentCellState; 
    nextCellStateP = nextCellState;    

    numRows_ = terminalManager_->getRows();
    numCols_ = terminalManager_->getCols();
}

void GameOfLife::run() {
    
    while (isRunning) {
        // Listen for user input. 
        UserInput userInput = terminalManager_->getUserInput();
        processUserInput(userInput);
        updateState();
        draw();
        terminalManager_->refresh(); 
    }
}

void GameOfLife::updateState() {
    // Copy CurrentCellState into nextCellState and switch pointers.
    for (int row = 0; row < terminalManager_->getRows(); row++) {
        for (int col  = 0; col < terminalManager_->getCols(); col++) {
            *(nextCellStateP + col + row * (numCols_)) = *(currentCellStateP + col + row * numCols_); 
        }
    }
    // Switch pointers.
    bool *tempP = currentCellStateP;
    currentCellStateP = nextCellStateP;
    nextCellStateP = tempP;
}

bool GameOfLife::getCell(int row, int col) {
    return *(currentCellStateP + col + row * numCols_);
}

void GameOfLife::setCell(int row, int col) {
    *(currentCellStateP + col + row * numCols_) = !*(currentCellStateP + col + row * numCols_);
}


void GameOfLife::setCellsRandomly(int probability) {
    for (int i = 0; i < MAXCELLS; i++) {
        *(currentCellStateP + i) = rand() % probability == 0 ? true: false;
    }

}

void GameOfLife::processUserInput(UserInput userInput) {
    // Handle key events. 
    if (userInput.isPressed_q()) { isRunning = false; }
    else if (userInput.isPressed_r()) { setCellsRandomly(); }
    else if (userInput.isPressed_Space()) {isBreak = !(isBreak); }


    // Handle Mouse events.
    if (userInput.mouseClicked()) {
        userInput.handleMouseEvent();
        // Set cell at mouse position.
        setCell(userInput.getMouseRow(), userInput.getMouseCol());
        // setCell(2, 2);

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
    // Draw currentCellState
    // Cell alive: Yellow colored.
    // Cell dead: Purple colored.
    for (int row = 1; row < ROWS - 1; row++) {
        for (int col = 1; col < COLS - 1; col++) {
            if (getCell(row, col)) {
                terminalManager_->drawPixel(row, col, terminalManager_->Yellow);
            } else { terminalManager_->drawPixel(row, col, terminalManager_->Purple); }
        }
    }


}
