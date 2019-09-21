#pragma once
#include "Word.h"
#include <allegro.h>

enum SCREEN { SPLASH, MAINMENU, GAMEPLAY, GAMEOVER, INITIALIZE };

class Screen {
public:
  Screen(BITMAP *);
  Screen();
  ~Screen();
  void Draw(BITMAP *);
  void SetState(enum SCREEN);
  SCREEN GetState();
  void SetWord(std::string);

protected:
  BITMAP *image;
  int score;
  Word *word;
  SCREEN state;
  Point position;

private:
};
