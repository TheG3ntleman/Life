#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

/*
 * Using 8x8 kernals which get along
 * really well with long type variables
 *
 * Can store kernal combination information 
 * on disk after initial startup to 
 * eliminate calculting them each time
 * the program starts up.*/

#define KS 8 // kernal size
typedef long ker; // kernal type def.

class Board {

public:

  Board(unsigned int side_length);
  ~Board();

  void print();
  

private:
  unsigned int n;
  ker **board;
  

};

#endif
