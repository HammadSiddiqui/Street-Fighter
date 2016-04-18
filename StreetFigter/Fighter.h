#pragma once
#include <allegro.h>
#include "Point.h"

enum STATE {IDLE, WALK_FORWARD, WALK_BACKWARD, JUMP, KICK, PUNCH, CROUCH};

class Fighter
{
    public:
        Fighter();
        Fighter(BITMAP*, Point);
        Fighter(BITMAP*, float,float);
        virtual ~Fighter();
        void SetPosition(float,float);
        void Draw(BITMAP*);
        void Action();
        bool isAlive();
        void SetState(enum STATE);
        void TakeDamage(int);
        void Move(float,float);


    protected:
        BITMAP* image;
        int frame_width;
        int frame_height;
        int health;
        bool alive;
        STATE state;
        Point position;
        int frames;


    private:
};
