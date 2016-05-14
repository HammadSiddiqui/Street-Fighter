#pragma once
#include <allegro.h>
enum SCREEN{SPLASH, MAINMENU, GAMEPLAY, GAMEOVER};
class Screen
{
    public:
        Screen(BITMAP*);
        Screen();
        ~Screen();
        void Draw(BITMAP*);

    protected:
        BITMAP* image;

    private:
};
