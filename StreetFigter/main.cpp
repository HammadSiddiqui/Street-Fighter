#include <allegro.h>
#include <iostream>
#include "Fighter.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "CircleLinkedList.h"
#include "Background.h"
#include "Screen.h"

volatile long speed_counter = 0; // A long integer which will store the value of the speed counter.
volatile long objectCounter = 0;
void increment_speed_counter() // A function to increment the speed counter
{
    speed_counter++; // This will just increment the speed counter by one. :)
    objectCounter++;
}
END_OF_FUNCTION(increment_speed_counter);




int main(int argc, char* argv[])
{
    //Enumerater for Different types of screen

    //  SCREEN screenMode = SPLASH;
    srand(time(0));
    if (allegro_init() != 0)
    {
        allegro_message("Cannot initialize Allegro.\n");
        return 1;
    }

    //Set the window title when in a GUI environment
    set_window_title("Street Fighter 2016");

    if (install_keyboard())
    {
        allegro_message("Cannot initialize keyboard input.\n");
        return 1;
    }

    if (install_timer())
    {
        allegro_message("Cannot initialize timer.\n");
        return 1;
    }

    LOCK_VARIABLE(speed_counter); //Used to set the timer - which regulates the game's speed
    LOCK_FUNCTION(increment_speed_counter);
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));//Set our BPS

    //set graphics mode, trying all acceptable depths
    set_color_depth(32);


    int w, h;
    get_desktop_resolution(&w, &h);
    set_color_depth(desktop_color_depth());

    set_gfx_mode(GFX_SAFE, 800, 600, 0, 0);
    //set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0);
    //set_gfx_mode(GFX_DIRECTX_ACCEL, 800, 600, 0, 0);

    /*Buffer*/
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    /*Background*/
    BITMAP* background = load_bitmap("images/Area1.bmp", NULL);
    /*Splash Image*/
    BITMAP* splashImg = load_bitmap("images/splash.bmp", NULL);
    /*Fighter Image*/
    BITMAP* gameSprite = load_bitmap("images/ken.bmp", NULL);
    /*Enemy Image*/
    BITMAP* EnemySprite[3];
    EnemySprite[0] = load_bitmap("images/enemy1.bmp", NULL);
    EnemySprite[1] = load_bitmap("images/enemy2.bmp", NULL);
    EnemySprite[2] = load_bitmap("images/enemy3.bmp", NULL);
    //Game Health Bar
    BITMAP* ui = load_bitmap("images/ui.bmp", NULL);
    Word* gameOver = new Word("GAMEOVER",ui,SCREEN_W/2,SCREEN_H/2);

    if(gameSprite == NULL or background == NULL or EnemySprite == NULL or splashImg == NULL or ui == NULL)
    {
        allegro_message("Sprite not loaded\n");
        return 1;

    }

    Screen *screenMode = new Screen(ui);
    screenMode->SetState(SPLASH);
    Background *area = new Background(background);
    Fighter *player = new Fighter(gameSprite, 150.0,380.0);
    Enemy *kasungai = new Enemy(EnemySprite[0], 500, 380);
    HealthBar* healthBar = new HealthBar(ui,1,1);
    kasungai->SetTarget(player);
    CircleLinkedList<Fighter*>* playerList = new CircleLinkedList<Fighter*>;
    playerList->Insert(player);
    playerList->Insert(kasungai);

    STATE state;
    state = IDLE;
    int enemyCounter = 0;

    srand((unsigned)time(0));
    //y = 210 + (rand() % (int)(110));

    //Point p(SCREEN_W/2, 32);



    //  LinkedList* objects = new LinkedList(gameSprite);



    // Terrain* terrainTop = new Terrain(gameSprite, 0, -640, 0, 0);
    //Terrain* terrainBottom = new Terrain(gameSprite, 0, 0, 0, 0);


    int spaceDelay = 0;

    while(!key[KEY_ESC])
    {

        //Add your game logic here
        if(screenMode->GetState() == SPLASH)
        {
            //draw_sprite(buffer, splashImg, 0, 0);
            screenMode->Draw(buffer);
            if(key[KEY_SPACE])
            {
                screenMode->SetState(GAMEPLAY);
            }
        }


        else if (screenMode->GetState() == GAMEPLAY)
        {
            if(player->isAlive() == false)
            {
                screenMode->SetState(GAMEOVER);
            }

            while (speed_counter > 0)
            {
                playerList->AI();
                playerList->CollisionFunction();
                if(key[KEY_RIGHT]) // If the user hits the right key, change the picture's X coordinate
                {

                    player->SetState(WALK_FORWARD);

                }
                else if(key[KEY_LEFT]) // Ditto' - only for left key
                {
                    player->SetState(WALK_BACKWARD);

                }
                else if(key[KEY_DOWN]) // Ditto' - only for down
                {
                    player->SetState(CROUCH);
                }
                else if(key[KEY_S]) // If the user hits the up key, change the picture's Y coordinate
                {

                    player->SetState(KICK);

                }
                else if(key[KEY_A]) // Ditto' - only for down
                {
                    player->SetState(PUNCH);
                }
                else if(key[KEY_SPACE]) // press space to fire
                {
                    player->SetState(JUMP);
                }

                if(spaceDelay >= 30)
                {
                    player->SetState(IDLE);
                    spaceDelay = 0;
                }


                spaceDelay++;
                /*
                            if(terrainTop->GetPosition()->y>640)
                            {
                                cout<<"\nTerrainTop Y:"<<terrainTop->GetPosition()->y;
                                delete terrainTop;
                                terrainTop = new Terrain(gameSprite, 0, -640, 0, 0);
                            }
                            if(terrainBottom->GetPosition()->y>640)
                            {
                                cout<<"\nTerrainBottom Y:"<<terrainBottom->GetPosition()->y;
                                delete terrainBottom;
                                terrainBottom = new Terrain(gameSprite, 0, -640, 0, 0);
                            }

                            objects->MoveAll();
                            terrainTop->Move();
                            terrainBottom->Move();
                            CreateObjects(objects, gameSprite);


                            speed_counter--;
                            */

               switch(area->GetCordinate())
                {
                case 120:
                    if(enemyCounter == 0)
                    {

                        Enemy *enemyObj = new Enemy(EnemySprite[rand()%3], 600, 380);
                        enemyObj->SetTarget(player);
                        playerList->Insert(enemyObj);

                    }
                    enemyCounter = 1;
                    break;

               /* case 140:
                    if(enemyCounter == 1)
                    {
                        Enemy *enemyObj2 = new Enemy(EnemySprite[rand()%3], 600, 380);
                        enemyObj2->SetTarget(player);
                        playerList->Insert(enemyObj2);
                    }
                    enemyCounter = 2;
                    break;
                    */
                default:
          /*             if(playerList->GetLength() < 2)
                       {
                           if(rand()%500 <= 2)
                           {
                               Enemy *enemyObj2 = new Enemy(EnemySprite[rand()%3], 600, 380);
                               enemyObj2->SetTarget(player);
                               playerList->Insert(enemyObj2);
                           }
                       }
            */
                    break;
                }



                if(player->GetPosition().x >= 500)
                {
                    player->Move(-3.0f, 0.0f);
                    area->Move(1.8f);
                }
                else if (player->GetPosition().x <= 100)
                {
                    player->Move(1.0f, 0.0f);
                    area->Move(-1.8f);
                }


                speed_counter--;

                healthBar->Move(player->GetHealth());

            }


            playerList->DeleteDead();
            area->Draw(buffer);
            healthBar->Draw(buffer);
            playerList->Draw(buffer);

        }
        else if (screenMode->GetState() == GAMEOVER)
        {

            if(player->isAlive() == false)
            {
                screenMode->SetWord(gameOver);
            }
            screenMode->Draw(buffer);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear_bitmap(buffer);


        /*
                terrainBottom->Draw(buffer);
                terrainTop->Draw(buffer);

                objects->DrawAll(buffer, false);

        		draw_sprite(screen, buffer, 0, 0);
        		clear_bitmap(buffer);
                objects->CleanAll();
                playerList->DeleteDead();
        */

    }
    //Cleaning Memory
    destroy_bitmap(buffer);
    destroy_bitmap(gameSprite);
    destroy_bitmap(splashImg);
    destroy_bitmap(background);
    for(int i = 0; i < 3; i++)
    {
        destroy_bitmap(EnemySprite[i]);
    }
    delete playerList;
//	destroy_sample(fireSound);
//	delete terrainTop;
//	delete terrainBottom;
//	delete objects;

    return 0;
    //Allegro will automatically deinitalize itself on exit

}
END_OF_MAIN();
/*
void CreateObjects(LinkedList* objects, BITMAP* gameSprite)
{
    if(objectCounter%200 == 0)
    {
        Viper* viper = new Viper(gameSprite, 192, 0, 64, 64, (rand() % (int)(SCREEN_W)), -128, 21);
        viper->SetTarget(player);
        objects->Append(viper);
    }
    if(objectCounter%100 == 0)
    {
        Cobra* cobra = new Cobra(gameSprite, 384, 0, 64, 64, (rand() % (int)(SCREEN_W)), -128, 22);
        cobra->SetTarget(player);
        objects->Append(cobra);
    }
}
*/
