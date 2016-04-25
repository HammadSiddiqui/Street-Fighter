#include "Background.h"

Background::Background()
{
    //ctor
}

Background::Background(BITMAP* img) {
    this->image = img;
    this->xCordinate = 0;
}

Background::~Background()
{
    //dtor
}

void Background::Move(float x) {
    this->xCordinate += x;
}

void Background::Draw(BITMAP* buffer) {
    masked_blit(this->image, buffer, xCordinate,0,0,0,SCREEN_W,SCREEN_H);

}
