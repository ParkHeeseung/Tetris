#include "Pane.h"

#ifndef __StatPane_h__
#define __StatPane_h__

class StatPane : public Pane{
public:
  StatPane(int x, int y, int w, int h);
  void draw();
};

#endif //__StatPane_h__
