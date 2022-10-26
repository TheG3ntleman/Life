#include <iostream>

#include "window/window.hpp"
#include "life/board.hpp"
#include "life/save.hpp"
#include "life/camera.hpp"

#define BOARD_SIZE 10
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main () {

  Window window (WINDOW_WIDTH, WINDOW_HEIGHT, "Life");
  window.run();

  return 0;
}
