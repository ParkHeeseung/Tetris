#include "Z_Block.h"

void Z_Block::tetromino(){
  block[0][0]=0; block[0][1]=6;
  block[1][0]=1; block[1][1]=6;
  block[2][0]=1; block[2][1]=5;
  block[3][0]=2; block[3][1]=5;
  color = 3;
  s = 0;
}
void Z_Block::rotate(){
  int count = 0;
  if(s == 0){
    if(board[block[0][0]][block[0][1]-1] == 0) count ++;
    if(board[block[1][0]-1][block[1][1]] == 0) count ++;
    if(board[block[2][0]][block[2][1]+1] == 0) count ++;
    if(board[block[3][0]-1][block[3][1]+2] == 0) count ++;

    if(count == 4){
      block[0][1] --;
      block[1][0] --;
      block[2][1] ++;
      block[3][0] --; block[3][1]+=2;
      s++;
    }
  }
  else if(s == 1){
    if(board[block[0][0]+2][block[0][1]] == 0) count ++;
    if(board[block[1][0]+1][block[1][1]-1] == 0) count ++;
    if(board[block[3][0]-1][block[3][1]-1] == 0) count ++;

    if(count == 3){
      block[0][0] +=2;
      block[1][0] ++; block[1][1] --;
      block[3][0] --; block[3][1] --;
      s++;
    }
  }
  else if(s == 2){
    if(board[block[0][0]-1][block[0][1]+2] == 0) count ++;
    if(board[block[1][0]][block[1][1]+1] == 0) count ++;
    if(board[block[2][0]-1][block[2][1]] == 0) count ++;
    if(board[block[3][0]][block[3][1]-1] == 0) count ++;

    if(count == 4){
      block[0][0] --; block[0][1] +=2;
      block[1][1] ++;
      block[2][0] --;
      block[3][1] --;
      s++;
    }
  }
  else if(s == 3){
    if(board[block[0][0]-1][block[0][1]-1] == 0) count ++;
    if(board[block[2][0]+1][block[2][1]-1] == 0) count ++;
    if(board[block[3][0]+2][block[3][1]] == 0) count ++;

    if(count == 3){
      block[0][0] --; block[0][1] --;
      block[2][0] ++; block[2][1] --;
      block[3][0] +=2;
      s=0;
    }
  }

}
