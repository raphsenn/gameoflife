

#include "./UserInput.h"

#include <ncurses.h>

bool UserInput::isPressed_Space() { return keycode_ == 32; }

bool UserInput::isPressed_q() { return keycode_ == 113; }

bool UserInput::isPressed_r() { return keycode_ == 114; }

int UserInput::getMouseRow() { return mouseRow_; }

int UserInput::getMouseCol() { return mouseCol_; }

bool UserInput::mouseClicked() { return isMouseEvent(keycode_); }

bool UserInput::isMouseEvent(int keycode) {
  if (keycode == KEY_MOUSE) {
    handleMouseEvent();
    return true;
  }
  return false;
}

void UserInput::handleMouseEvent() {
    MEVENT event;
    if (getmouse(&event) == OK) {
        if (event.bstate && BUTTON1_RELEASED) {
            mouseCol_ = event.x / 2;
            mouseRow_ = event.y;
        }
    }
}


