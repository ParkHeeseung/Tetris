#include "Block.h"

#ifndef __L_Block_h__
#define __L_Block_h__

extern int board[][12];
extern int block[][2];
extern int color;


class L_Block : public Block{
private:
  int s;
public:
  void tetromino();
  void rotate();
};

#endif
