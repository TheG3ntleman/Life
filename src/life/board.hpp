#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {

public:

  Board(unsigned int side_length);
  ~Board();

  void update();
  char** getBoard();

private:

  unsigned int n;
  char **board;

};

#endif
