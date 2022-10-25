#include "board.hpp"
#include <cstdlib>

Board::Board(unsigned int side_length) {
  n = side_length;
  board = new ker*[n];
  for (unsigned int i = 0; i < n; i++) {
    board[i] = new ker[n];
    for (unsigned int j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }
}

Board::~Board() {
  for (unsigned int i = 0; i < n; i++)
    delete board[i];
  delete board;
}

void Board::print() {
  for  (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {

    }
  }
}
