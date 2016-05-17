#pragma once
#include <allegro.h>
#include "Word.h"
enum SCREEN{SPLASH, MAINMENU, GAMEPLAY, GAMEOVER, FINISH};
class Screen
{
    public:
        Screen(BITMAP*);
        Screen();
        ~Screen();
        void Draw(BITMAP*);
        void SetState(enum SCREEN);
        SCREEN GetState();
        void SetWord(Word*);
//        void SetWord(std::string);

    protected:
        BITMAP* image;
        int score;
        Word* word;
        SCREEN state;
        Point position;

    private:
};
