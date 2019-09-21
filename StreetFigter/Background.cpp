#include "Background.h"

Background::Background() {
  // ctor
}

Background::Background(BITMAP *img) {
  this->image = img;
  visibleImage = create_sub_bitmap(image, 0, 0, SCREEN_W, SCREEN_H);
  this->xCordinate = 0;
}

Background::~Background() {
  // dtor
  destroy_bitmap(image);
}

void Background::Move(float x) {
  this->xCordinate += x;
  if (xCordinate < 0) {
    xCordinate = 0;
  }
}

int Background::GetCordinate() { return this->xCordinate; }

void Background::SetCordinate(int x) { this->xCordinate = x; }

void Background::Draw(BITMAP *buffer) {

  masked_blit(this->image, buffer, xCordinate, -1, 0, 0, SCREEN_W, SCREEN_H);
}
