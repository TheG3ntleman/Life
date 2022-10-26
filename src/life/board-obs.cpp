#include "board.hpp"

Board::Board(unsigned int size) {
  n = size;
  board = new char*[n];
  for (unsigned int i = 0; i < n; i++){
    board[i] = new char[n];
    for (unsigned int j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }

  bufferBoard = new char*[n];
  for (unsigned int i = 0; i < n; i++){
    bufferBoard[i] = new char[n];
    for (unsigned int j = 0; j < n; j++) {
      bufferBoard[i][j] = 0;
    }
  }
}

Board::~Board() {
  for (unsigned int i = 0; i < n; i++)
    delete board[i];
  delete board;
  for (unsigned int i = 0; i < n; i++)
    delete bufferBoard[i];
  delete bufferBoard;
}

void Board::update() {
  char **currBoard;

  if (state) 
    currBoard = bufferBoard;
  else
    currBoard = board;

  char c; // buffer variable
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      c = getNeighbors(i, j);
      if (currBoard[i][j]) {
        if (c < 2) {
          currBoard[i][j] = 0;
        } else if (currBoard[i][j] > 3)
          currBoard[i][j] = 0;
      } else {
        if (c == 3) 
          currBoard[i][j] = 1;
      }
    }
  }
}

void Board::print() {
  char **currBoard;

  if (state) 
    currBoard = bufferBoard;
  else
    currBoard = board;
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (currBoard[i][j]) 
        std::cout << "#";
      else 
        std::cout << " ";
    }
    std::cout << std::endl;
  }
}

void Board::setCell(char val, unsigned int r, unsigned int c) {

  // Checking bounds could add if MACRO and so 
  // on to get rid of safety for the sake of speed.
  board[r][c] = val; 

}

char Board::getCell(unsigned int r, unsigned int w) {
  return board[r][w];
}

char Board::getNeighbors(unsigned int r, unsigned int c) {
  char count = 0;
  
  // Checking boundary conditions
  // Could eliminate checking boundary conditions by splitting 
  // update loop into multiple case based loops for speed
  // gains.
  int bx1 = r - 1, bx2 = r + 1, by1 = c - 1, by2 = c + 1;
  if (bx1 < 0)
    bx1 = 0;
  if (bx2 > n-1)
    bx2 = n-1;
  if (by1 < 0)
    by1 = 0;
  if (by2 > n-1)
    by2 = n-1;


  char **currBoard;

  if (state) 
    currBoard = board;
  else
    currBoard = bufferBoard;

  // Counting neighbors 
  for (unsigned int i = bx1; i <= bx2; i++) {
    for (unsigned int j = by1; j <= by2; j++) {
      if (currBoard[i][j] == 1)
        count++;
    }
  }

  return count;
}
