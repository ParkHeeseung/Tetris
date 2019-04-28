#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "Block.h"
#include "ResultPane.h"
#include "O_Block.h"
#include "I_Block.h"
#include "Z_Block.h"
#include "L_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "T_Block.h"

#ifndef __Tetris_h__
#define __Tetris_h__


class Tetris {
 Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_, *ResultPane_;
 Block *Block_, *O_Block_, *I_Block_, *Z_Block_, *L_Block_, *J_Block_, *S_Block_, *T_Block_;
 Block *new_block_;
  public:
  Tetris();
  ~Tetris();
  void play(char input);
  void NEW_Block();
  void result();
  void updateScreen();
};

#endif
