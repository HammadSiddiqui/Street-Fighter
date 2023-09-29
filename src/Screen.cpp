#include "Screen.h"
#include <iostream>

Screen::Screen(BITMAP *img) {

  this->image = img;
  this->position.x = SCREEN_W / 2;
  this->position.y = SCREEN_H / 2;
}

Screen::Screen() {
  // ctor
}

Screen::~Screen() {
  // dtor
}

void Screen::SetWord(std::string wrd) {

  word = new Word(wrd, this->image, &this->position);
  if (word == NULL)
    std::cout << "Word in NULL\n";
}
/*
void Screen::SetWord(Word* wrd){
    this->word = wrd;
}
*/
void Screen::SetState(enum SCREEN st) { this->state = st; }

SCREEN Screen::GetState() { return this->state; }

void Screen::Draw(BITMAP *buffer) {
  if (state == SPLASH) {
    masked_blit(image, buffer, 0, 290, 0, 0, SCREEN_W, SCREEN_H);
  } else if (state == GAMEOVER) {
    word->Draw(buffer, 1, false);
  } else if (state == MAINMENU) {
    word->Draw(buffer, 1, false);
  }
}
