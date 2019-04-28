#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "ResultPane.h"
#include "Block.h"
#include "Tetris.h"
#include "O_Block.h"
#include "I_Block.h"
#include "Z_Block.h"
#include "L_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "T_Block.h"

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctime>

using namespace std;


int num = 0; // score
char username[8]; // userinput
bool isGameOver = false; // gameover
int color; // randam block color 1~7
int check = 0;
int block[4][2];
int board[21][12];


////////////////////////////////kbhit///////////////////////////////////////////
int kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;

  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);

  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
  return 0;

  if(FD_ISSET(0,&read_fd))
  return 1;

  return 0;
}
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
  ifstream inStream;
  inStream.open("input.txt");

  clock_t startTime, endTime;
  int input, seed, error = 0;
  char key;

  if (argc>1){
    inStream >> username;
    inStream >> seed;
    srand(seed);
  }
  else{
    cout <<"테트리스 게임을 시작합니다."<<endl;
    cout <<"사용자의 이름을 입력하세요."<<endl;
    cout <<"이름: ";
    cin >> username;
    srand(time(NULL));
  }

  Tetris t;

  keypad(stdscr, TRUE);
  t.updateScreen();

  while(!isGameOver){
    if (argc>1){
      inStream >> key;

      if(key == 'q'){
        isGameOver = true;
      }
      t.play(key);
      t.play('g');
      usleep(400000);
    }
    else{
      startTime = clock();
      while(!isGameOver){
        endTime = clock();
        if(kbhit()){
          input = getch();
          if(input == KEY_DOWN) key = 'g';
          else if(input == KEY_LEFT) key = 'l';
          else if(input == KEY_RIGHT) key = 'r';
          else if(input == ' ') key = 'd';
          else if(input == KEY_UP) key = 't';
          else
            key = (char) input;

          if(key == 'q'){
            isGameOver = true;
          }
          t.play(key);
        }
        if((endTime-startTime) > 0.4*CLOCKS_PER_SEC){
          t.play('g');
          break;
        }

      }

    }

  }
  t.result();
  getch();


}
