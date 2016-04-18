#include "Fighter.h"
#include <iostream>
Fighter::Fighter()
{

}
Fighter::Fighter(BITMAP* img, Point pos) {
    frames = 0;
    state = IDLE;
    this->image = img;
    this->position = pos;
}

Fighter::Fighter(BITMAP* img, float x, float y) {
    frames = 0;
    state = IDLE;
    this->image = img;
    this->position.x = x;
    this->position.y = y;
}

void Fighter::SetPosition(float x,float y) {
    this->position.x = x;
    this->position.y = y;
}

bool Fighter::isAlive() {
    return this->alive;
}

void Fighter::TakeDamage(int dam) {
    this->health = this->health - dam;
    if(this->health < 0){
        this->health = 0;
    }
}

void Fighter::SetState(STATE stat) {
    this->state = stat;
}

void Fighter::Move(float i,float j) {
    this->position.x = this->position.x + i;
    this->position.y = this->position.y + j;
}

void Fighter::Draw(BITMAP* buffer) {
    switch(state){
        case WALK_BACKWARD:
        if(frames%200 < 40){
                masked_blit(this->image, buffer, 295,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);

            }
            else if(frames%200 < 80 && frames%200 >= 40){
                masked_blit(this->image, buffer, 225,240,this->position.x,this->position.y,60,80);
               this->Move(-0.2f,0);
            }
            else if(frames%200 < 120 && frames%200 >= 80) {
                masked_blit(this->image, buffer, 155,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
            else if(frames%200 <= 160 && frames%200 >= 120) {
                masked_blit(this->image, buffer, 85,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
            else if(frames%200 <= 200 && frames%200 >= 160) {
                masked_blit(this->image, buffer, 13,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
        frames++;
    break;
    case WALK_FORWARD:
        if(frames%200 < 40){
                masked_blit(this->image, buffer, 13,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);

            }
            else if(frames%200 < 80 && frames%200 >= 40){
                masked_blit(this->image, buffer, 85,240,this->position.x,this->position.y,60,80);
               this->Move(0.2f,0);
            }
            else if(frames%200 < 120 && frames%200 >= 80) {
                masked_blit(this->image, buffer, 155,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
            else if(frames%200 <= 160 && frames%200 >= 120) {
                masked_blit(this->image, buffer, 225,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
            else if(frames%200 <= 200 && frames%200 >= 160) {
                masked_blit(this->image, buffer, 295,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
        frames++;
    break;
    case KICK:
            if(frames%200 < 40){
                masked_blit(this->image, buffer, 15,475,this->position.x,this->position.y,60,80);

            }
            else if(frames%200 < 80 && frames%125 >= 40){
                masked_blit(this->image, buffer, 80,475,this->position.x,this->position.y,60,80);

            }
            else if(frames%200 < 120 && frames%125 >= 80) {
                masked_blit(this->image, buffer, 140,475,this->position.x,this->position.y,60,80);
            }
            else if(frames%200 <= 160 && frames%125 >= 120) {
                masked_blit(this->image, buffer, 220,475,this->position.x,this->position.y,60,80);
            }
            else if(frames%200 <= 200 && frames%125 >= 160) {
                masked_blit(this->image, buffer, 300,475,this->position.x,this->position.y,60,80);
            }
        frames++;


    case PUNCH:


            if(frames%200 < 50){
                masked_blit(this->image, buffer, 15,160,this->position.x,this->position.y,60,80);

            }
            else if(frames%200 < 100 && frames%200 >= 50){
                masked_blit(this->image, buffer, 85,160,this->position.x,this->position.y,60,80);

            }
            else if(frames%200 <=200 && frames%200 >= 100) {
                masked_blit(this->image, buffer, 155,160,this->position.x,this->position.y,60,80);
            }
            //Has only three frames in sprite
        frames++;


    case IDLE:
         //while(frames < 300)
        {

            if(frames%400 < 100){
                masked_blit(this->image, buffer, 15,80,this->position.x,this->position.y,60,80);

            }
            else if(frames%400 < 200 && frames%400 >= 100){
                masked_blit(this->image, buffer, 85,80,this->position.x,this->position.y,60,80);

            }
            else if(frames%400 < 300 && frames%400 >= 200) {
                masked_blit(this->image, buffer, 155,80,this->position.x,this->position.y,60,80);
            }
            else if(frames%400 <= 400 && frames%400 >= 300) {
                masked_blit(this->image, buffer, 225,80,this->position.x,this->position.y,60,80);
            }
        frames++;
        }
        break;

        //frames = 0;


    default:
        break;

/*        while(frames < 39)
        {
            std::cout << frames << std::endl;
            if(frames < 15){
                masked_blit(this->image, buffer, 15,80,this->position.x,this->position.y,60,80);

            }
            else if(frames < 25 && frames >= 15){
                masked_blit(this->image, buffer, 85,80,this->position.x,this->position.y,60,80);

            }
            else if(frames < 35 && frames >= 25) {
                masked_blit(this->image, buffer, 155,80,this->position.x,this->position.y,60,80);

            }
        frames++;
        }
    }
    frames = 0;
*/
}
}



void Fighter::Action() {

}

Fighter::~Fighter()
{
    //dtor
}
