#include "./TerminalManager.h"

TerminalManager::TerminalManager() {
  // Initialize ncurses and some settings suitable for our game.
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // Initialize all the colors we need.
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);

  // Set logical dimensions of the screen.
  numRows_ = LINES;
  numCols_ = COLS / 2;
}

TerminalManager::~TerminalManager() { endwin(); }

UserInput TerminalManager::getUserInput() {
  UserInput userInput;
  userInput.keycode_ = getch();
  return userInput;
}
