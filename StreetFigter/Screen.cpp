#include "Screen.h"


Screen::Screen(BITMAP* img) {

    this->image = img;
    this->position.x = SCREEN_W/2;
    this->position.y = SCREEN_H/2;
//    word = new Word("Game Over",img,this->position)

}

Screen::Screen()
{
    //ctor
}


Screen::~Screen()
{
    //dtor
}

void Screen::SetWord(Word* wrd){
    this->word = wrd;
}

void Screen::SetState(enum SCREEN st) {
    this->state = st;
}

SCREEN Screen::GetState() {
    return this->state;
}

void Screen::Draw(BITMAP* buffer) {
    if(state == SPLASH)
    {
        masked_blit(image,buffer,0,290,0,0,SCREEN_W - 128,SCREEN_H - 32);
    }
    else if(state == GAMEOVER)
    {
        word->Draw(buffer, 1,false);
    }
}
