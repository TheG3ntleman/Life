#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Board {

public:

  Board(unsigned int side_length);
  Board(std::string path);
  ~Board();

  void update();
  char operator ()(unsigned int x, unsigned int y);

private:

  unsigned int n;
  char **board; // can have far more effecient board representation 
                // by using char and bit operators, then storing cell
                // states directly into bits and have read/write cell
                // interface functions.

};

#endif
