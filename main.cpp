
#include "./GameOfLife.h"


int main() {
    TerminalManager terminalManager;
    GameOfLife gol(terminalManager);
    gol.run();
}