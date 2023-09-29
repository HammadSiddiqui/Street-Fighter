#pragma once
#include "Point.h"
#include <allegro.h>
class Background {
public:
  Background();
  Background(BITMAP *);
  void Draw(BITMAP *);
  ~Background();
  void Move(float);
  int GetCordinate();
  void SetCordinate(int);

protected:
private:
  BITMAP *image;
  BITMAP *visibleImage;
  float xCordinate;
};
