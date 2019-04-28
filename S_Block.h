#include "Block.h"

#ifndef __S_Block_h__
#define __S_Block_h__

extern int board[][12];
extern int block[][2];
extern int color;


class S_Block : public Block{
private:
  int s;
public:
  void tetromino();
  void rotate();
};

#endif
