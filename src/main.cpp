#include <iostream>

#include "window/window.hpp"
#include "life/board.hpp"
#include "life/save.hpp"
#include "life/camera.hpp"

#define BOARD_SIZE 10
#define WINDOW_WIDTH 10
#define WINDOW_HEIGHT 10

int main () {

  Board board = Board(BOARD_SIZE);
  //Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, "Life");

  // Setting board
  board.set_cell(1, 4, 5);
  board.set_cell(1, 5, 6);
  board.set_cell(1, 5, 5);
  board.set_cell(1, 5, 4);


  // Running life.

  for (unsigned int i = 0; i < 50; i++) {
    board.print();
    board.update();
  }
  
  return 0;
}
