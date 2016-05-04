#include "Enemy.h"
#include <iostream>

Enemy::Enemy(BITMAP* img, float x, float y) : Fighter(img, x, y)
{

}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::SetTarget(Fighter* tar) {
    this->target = tar;
}



void Enemy::AI() {
        int probability = rand()%100;
        int temp = this->position.x - this->target->GetPosition().x;

        if (this->position.x - this->target->GetPosition().x >= 60)
        {
                if(probability <= 20)
                {
                    this->SetState(WALK_FORWARD);
                }


                //else move back or attack

        }
        else if (this->position.x - this->target->GetPosition().x <= 30)
                {
                    if(probability >= 20)
                    {
                        this->SetState(KICK);
                    }
                    else if(probability < 20)
                    {
                        this->SetState(WALK_BACKWARD);

                    }
                    else
                    {
                        this->SetState(PUNCH);
                    }

                }


}


void Enemy::Draw(BITMAP* buffer) {
 switch(state)
    {
    case JUMP:
        if(frames%400 < 50)
            {
                masked_blit(this->image, buffer, 15,640,this->position.x,this->position.y,60,80);

            }
            else if(frames%400 < 100 && frames%400 >= 50){
                masked_blit(this->image, buffer, 85,640,this->position.x+10.0f,this->position.y - 9.0f,60,80);
                this->Move(0.4f,0);
            }
            else if(frames%400 < 150 && frames%400 >= 100) {
                masked_blit(this->image, buffer, 160,640,this->position.x+10.0f,this->position.y - 18.0f,60,80);
                this->Move(0.4f,0);
            }
            else if(frames%400 < 200 && frames%400 >= 150) {
                masked_blit(this->image, buffer, 230,640,this->position.x+10.0f,this->position.y - 24.0f,60,80);
                this->Move(0.4f,0);
            }
            else if(frames%400 < 250 && frames%400 >= 200) {
                masked_blit(this->image, buffer, 300,640,this->position.x+10.0f,this->position.y - 18.0f,60,80);
                this->Move(0.4f,0);
            }
            else if(frames%400 <= 300 && frames%400 >= 250) {
                masked_blit(this->image, buffer, 365,640,this->position.x+10.0f,this->position.y - 9.0f,60,80);
                this->Move(0.4f,0);
            }
            else if(frames%400 <= 400 && frames%350 >= 300) {
                masked_blit(this->image, buffer, 440,640,this->position.x+10.0f,this->position.y, 60, 80);
                this->Move(0.4f,0);
            }
            frames++;
        break;

    case CROUCH:
        masked_blit(this->image, buffer, 15,720,this->position.x,this->position.y,60,80);
        frames++;
        break;

    case WALK_BACKWARD:
            if(frames%200 < 40)
            {
               masked_blit(this->image, buffer, 295,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);

            }
            else if(frames%200 < 80 && frames%200 >= 40){
                masked_blit(this->image, buffer, 225,240,this->position.x,this->position.y,60,80);
               this->Move(0.2f,0);
            }
            else if(frames%200 < 120 && frames%200 >= 80) {
                masked_blit(this->image, buffer, 155,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
            else if(frames%200 <= 160 && frames%200 >= 120) {
                masked_blit(this->image, buffer, 85,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
            else if(frames%200 <= 200 && frames%200 >= 160) {
                masked_blit(this->image, buffer, 13,240,this->position.x,this->position.y,60,80);
                this->Move(0.2f,0);
            }
            frames++;
            break;

    case WALK_FORWARD:
        if(frames%200 < 40)
            {
                masked_blit(this->image, buffer, 440,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);

            }
            else if(frames%200 < 80 && frames%200 >= 40){
                masked_blit(this->image, buffer, 85,240,this->position.x,this->position.y,60,80);
               this->Move(-0.2f,0);
            }
            else if(frames%200 < 120 && frames%200 >= 80) {
                masked_blit(this->image, buffer, 365,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
            else if(frames%200 <= 160 && frames%200 >= 120) {
                masked_blit(this->image, buffer, 295,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
            else if(frames%200 <= 200 && frames%200 >= 160) {
                masked_blit(this->image, buffer, 225,240,this->position.x,this->position.y,60,80);
                this->Move(-0.2f,0);
            }
        frames++;
        break;
    case KICK:
            if(frames%200 < 40)
            {
                masked_blit(this->image, buffer, 18,475,this->position.x,this->position.y,60,85);

            }
            else if(frames%200 < 80 && frames%200 >= 40){
                masked_blit(this->image, buffer, 80,475,this->position.x,this->position.y,60,85);
            }
            else if(frames%200 < 120 && frames%200 >= 80) {
                masked_blit(this->image, buffer, 140,475,this->position.x,this->position.y,60,85);
            }
            else if(frames%200 < 160 && frames%200 >= 120) {
                masked_blit(this->image, buffer, 220,475,this->position.x,this->position.y,60,85);
            }
            else if(frames%200 < 200 && frames%200 >= 160) {
                masked_blit(this->image, buffer, 300,475,this->position.x,this->position.y,65,90);
            }
            frames++;
            break;


    case PUNCH:

            if(frames%200 < 50)
            {
                masked_blit(this->image, buffer, 435,160,this->position.x,this->position.y,60,80);
            }
            else if(frames%200 < 100 && frames%200 >= 50){
                masked_blit(this->image, buffer, 350,160,this->position.x,this->position.y,60,80);
            }
            else if(frames%200 <=200 && frames%200 >= 100) {
                masked_blit(this->image, buffer, 295,160,this->position.x,this->position.y,60,80);
            }
            //Has only three frames in sprite
        frames++;
        break;


    case IDLE:
         //while(frames < 300)
        {

            if(frames%400 < 100){
                masked_blit(this->image, buffer, 440,80,this->position.x,this->position.y,60,80);

            }
            else if(frames%400 < 200 && frames%400 >= 100){
                masked_blit(this->image, buffer, 365,80,this->position.x,this->position.y,60,80);

            }
            else if(frames%400 < 300 && frames%400 >= 200) {
                masked_blit(this->image, buffer, 295,80,this->position.x,this->position.y,60,80);
            }
            else if(frames%400 <= 400 && frames%400 >= 300) {
                masked_blit(this->image, buffer, 225,80,this->position.x,this->position.y,60,80);
            }
        frames++;
        }
        break;

        //frames = 0;


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
frames = 0;
}
}
