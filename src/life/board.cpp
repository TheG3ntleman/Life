#include "board.hpp"

Board::Board(unsigned int side_length) {
  n = side_length;
  board = new char*[n];
  for (unsigned int i = 0; i < n; i++) {
    board[i] = new char[n];
  }
}

Board::~Board() {
  for (unsigned int i = 0; i < n; i++)
    delete board[i];
  delete board;
}

void Board::update() {
   
}

char Board::operator ()(unsigned int x, unsigned int y) {
  return board[x][y];
}

