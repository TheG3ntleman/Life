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
  board.setCell(1, 5, 5);
  board.setCell(1, 5, 6);
  board.setCell(1, 6, 5);
  board.setCell(1, 6, 6);


  // Running life.

  for (unsigned int i = 0; i < 5; i++) {
    board.print();
    board.update();
  }
  
  return 0;
}
