
#include "./GameOfLife.h"

GameOfLife::GameOfLife(TerminalManager *terminalManager) { terminalManager_ = terminalManager; }

void GameOfLife::run() {
    
    while (isRunning) {
        // Listen for user input. 
        UserInput userInput = terminalManager_->getUserInput();
        processUserInput(userInput);
        
    }

}

void GameOfLife::processUserInput(UserInput userInput) {
    if (userInput.isPressed_q()) { isRunning = false; }
    else if (userInput.isPressed_Space()) {isBreak = !(isBreak); }

}

