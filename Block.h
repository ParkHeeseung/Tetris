#include "ncurses.h"
#include <cstdlib>

#ifndef __Block_h__
#define __Block_h__


class Block
{
  protected:
  int width_, height_;
  int s;  //count of spin

  WINDOW *win_;


  public:
  Block();
  void draw();
  void moveblock(char c);
  void clear();
  void gameover();
  void input_block_gameover();
  virtual void tetromino();
  virtual void rotate();
};

#endif
