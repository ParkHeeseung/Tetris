#include "Block.h"

extern int num; // score
extern bool isGameOver; // gameover
extern int color; // randam block color 1~7
extern int check; //drop check
extern int board[][12];
extern int block[][2];

Block::Block(){
  for(int i=0;i<21;i++)
    for(int j=0;j<12;j++)
      board[i][j]=1;

  for(int i=0;i<20;i++)
    for(int j=1;j<11;j++)
      board[i][j]=0;

  width_ = 22;
  height_ = 22;

  win_ = newwin(22, 22, 0, 30);

  tetromino();
}

void Block::draw(){
  gameover();
//////////////////////////NEW_Board/////////////////////////////////////////////
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(8));
  box(win_,0,0);
  for (int i=1; i<height_-1; i++)
    mvwhline(win_, i, 1, ACS_CKBOARD, width_-2);
  wattroff(win_, COLOR_PAIR(8));
  wrefresh(win_);

//////////////////////////NEW_Block////////////////////////////////////////////////
  for (int i=1; i<height_-1; i++){
    for(int j=2;j<22;j+=2){
//////////////////////////O_Block//////////////////////////////////////////////////
      init_pair(9, COLOR_WHITE, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(9));
      box(win_, 0, 0);
      if(board[i-1][j/2]==1) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 & color == 1) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(9));
      wrefresh(win_);
////////////////////////////I_Block////////////////////////////////////////////////
      init_pair(10, COLOR_BLUE, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(10));
      if(board[i-1][j/2]==2) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 2) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(10));
      wrefresh(win_);
////////////////////////////Z_Block////////////////////////////////////////////////
      init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(11));
      if(board[i-1][j/2]==3) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 3) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(11));
      wrefresh(win_);
////////////////////////////L_Block////////////////////////////////////////////////
      init_pair(12, COLOR_GREEN, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(12));
      if(board[i-1][j/2]==4) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 4) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(12));
      wrefresh(win_);
////////////////////////////J_Block////////////////////////////////////////////////
      init_pair(13, COLOR_YELLOW, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(13));
      if(board[i-1][j/2]==5) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 5) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(13));
      wrefresh(win_);
////////////////////////////S_Block////////////////////////////////////////////////
      init_pair(14, COLOR_RED, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(14));
      if(board[i-1][j/2]==6) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 6) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(14));
      wrefresh(win_);
////////////////////////////T_Block////////////////////////////////////////////////
      init_pair(15, COLOR_CYAN, COLOR_BLACK);
      wattron(win_, COLOR_PAIR(15));
      if(board[i-1][j/2]==7) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      for(int k=0;k<4;k++){
        if(block[k][0]== i-1 && block[k][1] == j/2 && color == 7) mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
      }
      wattroff(win_, COLOR_PAIR(15));
      wrefresh(win_);
    }
  }
}


void Block::moveblock(char c){
  int count=0;

  switch(c){
    case 'l':
      for(int i=0;i<4;i++){
        if(board[block[i][0]][block[i][1]-1] == 0) count++;
      }
      if(count==4)
        for(int i=0;i<4;i++) block[i][1]--;
     break;


    case 'r':
      for(int i=0;i<4;i++){
        if(board[block[i][0]][block[i][1]+1] == 0) count++;
      }
      if(count==4)
        for(int i=0;i<4;i++) block[i][1]++;

      break;

    case 'g':
      for(int i=0;i<4;i++){
        if((block[i][0] <19)  && board[block[i][0]+1][block[i][1]] == 0) count++;
      }
      if(count==4)
        for(int i=0;i<4;i++) block[i][0]++;
      else{
        for(int i = 0; i < 4; i++){
          board[block[i][0]][block[i][1]] =  color;
        }
        check = 1;
        input_block_gameover();
        clear();
      }

      break;

    case 'd':
    while(true){
      count = 0;
      for(int i=0;i<4;i++){
          if((block[i][0] <19) && board[block[i][0]+1][block[i][1]] == 0) count++;
      }
      if(count==4)
        for(int i=0;i<4;i++) block[i][0]++;
      else{
        for(int i = 0; i < 4; i++){
          board[block[i][0]][block[i][1]] = color;
        }
      check = 1;
      input_block_gameover();
      clear();

      break;
      }
    }

    break;

    case 't' :
      rotate();
    break;

 }
}

void Block::clear(){
  int count = 0;
  for(int i = 0; i < 20; i++){
    for(int j = 1; j < 11; j++){
      if(board[i][j] != 0) count ++;
    }
    if(count == 10){
      num ++;
      for(int j = 1; j < 11; j++){
        board[i][j] = 0;
      }
      for(int x = i; x > 0; x--){
        for(int y = 1; y <11; y++){
          board[x][y] = board[x-1][y];
        }
      }
      for(int y = 1; y < 11; y++){
        board[0][y] = 0;
      }
    }
    count = 0;
  }
}

void Block::gameover(){
  int count = 0;
  for(int i = 1; i<11; i++){
    if(board[0][i] != 0){
      isGameOver = true;
    }
  }
}


void Block::input_block_gameover(){
  for(int i = 0; i < 3; i++){
    if(board[i][5] != 0 || board[i][6] != 0 ){
      isGameOver = true;
    }
  }
}

void Block::tetromino(){}

void Block::rotate(){}