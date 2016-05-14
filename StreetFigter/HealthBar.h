#pragma once
#include"allegro.h"
#include"Point.h"
#include "Word.h"

class HealthBar
{
private:
    Point position;
    BITMAP* image;
    int healthfactor;
public:
    HealthBar(BITMAP*, int, int);
    ~HealthBar();
    void Move(int);
    void Draw(BITMAP*);
};
