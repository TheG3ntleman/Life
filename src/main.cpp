#include <iostream>

#include "window/window.hpp"
#include "life/board.hpp"
#include "life/save.hpp"
#include "life/camera.hpp"

#define BOARD_SIZE 100
#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 100

int main () {

  Board board = Board(BOARD_SIZE);
  Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, "Life");
  
  
  return 0;
}
