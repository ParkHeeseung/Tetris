#include "ResultPane.h"

extern int num;

ResultPane::ResultPane(int x, int y, int w, int h) : Pane(x,y,w,h){}

void ResultPane::draw(){
  init_pair(20, COLOR_CYAN, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(20));
  box(win_, 0, 0);
  mvwprintw(win_,1,10,"GAME OVER");
  mvwprintw(win_,2,1,"SCORE : %d", num);
  mvwprintw(win_,3,1, "Press any key to exit Tetris");
  wattroff(win_, COLOR_PAIR(20));
  wrefresh(win_);

}
