#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {

public:

  Board(unsigned int size);
  ~Board();

  void update();
  void print();

  void setCell(char val, unsigned int r, unsigned int c);
  char getCell(unsigned int r, unsigned int c);
  // possible function to get a sort of quick buffer for rendering.

private:
  unsigned int n;
  char **board;
  char **bufferBoard; // Must adjust and tidy up every function
                      // about this bufferBoard or board stuff.
  char state = 0; // Introduced to avoid copying 
                  // after every update.

  char getNeighbors(unsigned int r, unsigned int  c);

};

#endif
