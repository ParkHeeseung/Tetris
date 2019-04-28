#include "Tetris.h"
extern int check;

Tetris::Tetris(){
  initscr();
  start_color();
  curs_set(0); //커서 사라짐
  noecho(); //문자 입력 시 입력한 값을 화면에 보이지 않게함
  cbreak();
  refresh();
  infoPane_ = new InfoPane(1,1,25,5);
  helpPane_ = new HelpPane(1,6,25,12);
  nextPane_ = new NextPane(1,18,25,5);
  boardPane_ = new BoardPane(30,0,22,22);
  statPane_ = new StatPane(60,3,20,20);
  ResultPane_ = new ResultPane(27, 8, 30, 5);
  Block_ = new Block();
  O_Block_ = new O_Block();
  I_Block_ = new I_Block();
  Z_Block_ = new Z_Block();
  L_Block_ = new L_Block();
  J_Block_ = new J_Block();
  S_Block_ = new S_Block();
  T_Block_ = new T_Block();
}

Tetris::~Tetris(){
  delete infoPane_;
  delete helpPane_;
  delete nextPane_;
  delete boardPane_;
  delete statPane_;
  delete ResultPane_;
  delete O_Block_;
  delete I_Block_;
  delete Z_Block_;
  delete L_Block_;
  delete J_Block_;
  delete S_Block_;
  delete T_Block_;
  endwin();
}

void Tetris::play(char input){
  new_block_->moveblock(input);
  new_block_->draw();
  statPane_->draw();

  if(check==1){
    check=0;
    NEW_Block();
    new_block_->tetromino();
    new_block_->draw();
  }
}

void Tetris::result(){
  ResultPane_->draw();
}

void Tetris::NEW_Block(){
  int randam  = rand() % 7 + 1;
  switch (randam) {
    case 1 :
      new_block_=O_Block_;
    break;
    case 2 :
      new_block_=I_Block_;
    break;
    case 3 :
      new_block_=Z_Block_;
    break;
    case 4 :
      new_block_=L_Block_;
    break;
    case 5 :
      new_block_=J_Block_;
    break;
    case 6 :
      new_block_=S_Block_;
    break;
    case 7 :
      new_block_=T_Block_;
    break;
  }
}

void Tetris::updateScreen(){
  infoPane_->draw();
  helpPane_->draw();
  nextPane_->draw();
  boardPane_->draw();
  statPane_->draw();
  NEW_Block();
  new_block_->tetromino();
  new_block_->draw();
}
