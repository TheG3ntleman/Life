#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "../compile-settings.hpp"

class Board {

public:

  Board(unsigned int size);
  ~Board();

  void update();

  void set_cell(char val, unsigned int r, unsigned int c);
  char get_cell(unsigned int r, unsigned int c);
  // possible function to get a sort of quick buffer for rendering.

  // IO Functions
  void print();

private:
  unsigned int n;
  char **boards[2];
  bool state = false;

  char get_neighbors(char **board, unsigned int r, unsigned int  c);
  char **get_board(char state);
  void toggle_state();

};

#endif
