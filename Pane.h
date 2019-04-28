#include "ncurses.h"

#ifndef __Pane_h__
#define __Pane_h__
class Pane
{
  protected:
  int width_, height_;
  int x_, y_;
  WINDOW *win_;

  public:
  Pane(int x, int y, int w, int h);
  virtual ~Pane();
  virtual void draw();
};

#endif
