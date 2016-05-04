#include "Background.h"

Background::Background()
{
    //ctor
}

Background::Background(BITMAP* img) {
    this->image = img;
    visibleImage = create_sub_bitmap(image,0,0,SCREEN_W,SCREEN_H);
    this->xCordinate = 0;
}

Background::~Background()
{
    //dtor
    destroy_bitmap(image);
}

void Background::Move(float x) {
    this->xCordinate += x;
    if(xCordinate < 0){
        xCordinate = 0;
    }
}

void Background::Draw(BITMAP* buffer) {

        masked_blit(this->image, buffer, xCordinate,0,0,0,SCREEN_W,SCREEN_H);
}
