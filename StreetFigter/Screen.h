#pragma once
#include <allegro.h>

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
