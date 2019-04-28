#include "Pane.h"

#ifndef __BoardPane_h__
#define __BoardPane_h__

class BoardPane : public Pane{
public:
  BoardPane(int x, int y, int w, int h);
  void draw();
};

#endif
