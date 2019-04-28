#include "Pane.h"

#ifndef __HelpPane_h__
#define __HelpPane_h__

class HelpPane : public Pane{
public:
  HelpPane(int x, int y, int w, int h);
  void draw();
};

#endif //__HelpPane_h__
