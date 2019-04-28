#include "Pane.h"

#ifndef __InfoPane_h__
#define __InfoPane_h__


class InfoPane : public Pane{
public:
  InfoPane(int x, int y, int w, int h);
  void draw();
};

#endif
