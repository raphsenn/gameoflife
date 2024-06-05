
#include "./TerminalManager.h"

TerminalManager::TerminalManager() {
  // Initialize ncurses and some settings suitable for our game.
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // Mouse events.
  mousemask(ALL_MOUSE_EVENTS, NULL);
  mouseinterval(0);

  // Initialize all the colors we need.
  start_color();
  
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);

  // Set logical dimensions of the screen.
  numRows_ = LINES;
  numCols_ = COLS / 2;
}

TerminalManager::~TerminalManager() { endwin(); }

int TerminalManager::getRows() { return numRows_; }
int TerminalManager::getCols() { return numCols_; }

int TerminalManager::White = COLOR_WHITE;
int TerminalManager::Black = COLOR_BLACK;
int TerminalManager::Purple = COLOR_MAGENTA;
int TerminalManager::Yellow = COLOR_YELLOW;

void TerminalManager::drawPixel(int row, int col, int color) {
  // Select color.
  if (color == White) { attron(COLOR_PAIR(1)); }
  else if (color == Black) { attron(COLOR_PAIR(2)); }
  else if (color == Purple) { attron(COLOR_PAIR(3)); }
  else if (color == Yellow) { attron(COLOR_PAIR(4)); }

  // Draw pixel on screen.
  attron(A_REVERSE);
  mvprintw(row, 2 * col, "  ");
}

void TerminalManager::refresh() {
  ::refresh();
}

UserInput TerminalManager::getUserInput() {
  UserInput userInput;
  userInput.keycode_ = getch();
  return userInput;
}
