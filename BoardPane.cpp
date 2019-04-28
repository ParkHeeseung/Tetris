#include "BoardPane.h"


BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void BoardPane::draw(){
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(5));
  for(int i = 1; i < 21; i++){
    mvwhline(win_, i, 1, ACS_CKBOARD, 21);
  }

  box(win_, 0, 0);
  wattroff(win_, COLOR_PAIR(5));
  wrefresh(win_);
}
