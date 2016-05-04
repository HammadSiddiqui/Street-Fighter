#pragma once
#include <allegro.h>
#include "Point.h"
class Background
{
    public:
        Background();
        Background(BITMAP*);
        void Draw(BITMAP*);
        ~Background();
        void Move(float);

    protected:

    private:
        BITMAP* image;
        BITMAP* visibleImage;
        float xCordinate;
};
