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
        Point GetPosition();
        virtual void Draw(BITMAP*);
        bool isAlive();
        void SetState(enum STATE);
        STATE GetState();
        void TakeDamage(int);
        int GetHealth();
        void SetHealth(int);
        void Move(float,float);
      //virtual void Update();
        int GetFrameWidth();
        virtual void AI();
        void PlaySounds();


    protected:
        BITMAP* image;
        int frame_width;
        int frame_height;
        int health;
        bool alive;
        STATE state;
        Point position;
        int frames;
        SAMPLE *fireSound;


    private:
};
