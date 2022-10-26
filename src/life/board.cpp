#include "board.hpp"

// Construct and destructor

Board::Board(unsigned int size) {
  n = size;

  // Allocating mem for and initializing board buffers
  
  boards[0] = new char*[n]; boards[1] = new char*[n];
  for (unsigned int i = 0; i < n; i++) {
    boards[0][i] = new char[n]; boards[1][i] = new char[n];
    for (unsigned int j = 0; j < n; j++) {
      boards[0][i][j] = 0;
    }
  }

}

Board::~Board() {

  for (unsigned int i = 0; i < n; i++) {
    delete boards[0][i]; delete boards[1][i];
  }

  delete boards[0]; delete boards[1];

}

// Update and runtime functions
void Board::update() {
  // Loop - case decoupling to avoid boundary checks.
  
  char ** rboard = get_board(state);
  char ** wboard = get_board(!state);

  // Corners
  // Sides
  // Inside
  
  // For now will check boundaries and do it the easy way.

#ifdef BOUNDARY_CHECKS
  char count;
  for (unsigned int r = 0; r < n; r++) {
    for (unsigned int c = 0; c < n; c++) {
      count = get_neighbors(rboard, r, c);
      /*if (count != 0)
        std::cout << "row number: " << r<< ", column number:" << c<< ", Count: "<< static_cast<int>(count) << std::endl;*/
      if (count < 2) 
        wboard[r][c] = 0;
      else if (count > 3)
        wboard[r][c] = 0;
      else if (count == 3)
        wboard[r][c] = 1;
      else 
        wboard[r][c] = rboard[r][c];
    }
  }
#endif

  // Updating state
  toggle_state();

}

void Board::set_cell(char val, unsigned int r, unsigned int c) {
  char **board = get_board(state);
  if (val)
    board[r][c] = 1;
  else
    board[r][c] = 0;
}

char Board::get_cell(unsigned int r, unsigned int c) {
  return get_board(state)[r][c];
}


void Board::print() {
  char **board = get_board(state);
  for (unsigned int r = 0; r < n; r++) {
    for (unsigned int c = 0; c < n; c++) {
      if (board[r][c])
        std::cout << "#";
      else
        std::cout << " ";
    }
    std::cout << std::endl;
  }
}

// Private utility functions

char Board::get_neighbors(char **board, unsigned int r, unsigned int c) {
  char count = 0;
  int x1 = r - 1, x2 = r + 1, y1 = c - 1, y2 = c + 1;
 
#ifdef BOUNDARY_CHECKS
  if (x1 < 0)
    x1 = 0;
  if (y1 < 0)
    y1 = 0;
  if (x2 > n - 1)
    x2 = n - 1;
  if (y2 > n - 1)
    y2 = n - 1;
#endif

  for (unsigned int i = x1; i <= x2; i++) {
    for (unsigned int j = y1; j <= y2; j++) {
      if (!(i == r && j == c)) {
        if (board[i][j])
          count++;
      }
    }
  }

  return count;

}

char** Board::get_board(char st) {
  if (st)
    return boards[1];
  else
    return boards[0];
}

void Board::toggle_state() {
  state = !state;
}

