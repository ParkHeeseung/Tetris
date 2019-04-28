#include "O_Block.h"

void O_Block::tetromino(){
  block[0][0]=0; block[0][1]=5;
  block[1][0]=0; block[1][1]=6;
  block[2][0]=1; block[2][1]=5;
  block[3][0]=1; block[3][1]=6;
  color = 1;
  s = 0;
}

void O_Block::rotate(){}
