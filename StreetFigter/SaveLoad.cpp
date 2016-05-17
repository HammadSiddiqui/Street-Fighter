#include "SaveLoad.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

SaveLoad::SaveLoad(CircleLinkedList<Fighter*>* playerList, Background* area) {
    this->lst = playerList;
    this->area = area;
}


SaveLoad::SaveLoad()
{
    //ctor
}

SaveLoad::~SaveLoad()
{
    //dtor
    this->lst = NULL;
    this->area = NULL;
}

void SaveLoad::Save() {
  ofstream savefile;
  savefile.open ("saved.txt");
  savefile << area->GetCordinate() << "\n";
  //Fighter Data Start
  int playerPos = this->lst->GetHead()->data->GetPosition().x;
  savefile << playerPos << "\n";
  //Fighter Health
  int playerHealth = this->lst->GetHead()->data->GetHealth();
  savefile << playerHealth << "\n";


  //Fighter Data End

  for(int i = 1; i < lst->GetLength(); i++)
  {
      savefile << lst->GetNode(i)->data->GetPosition().x << "\n";

  }

  savefile.close();
  std::cout << "Game Saved\n";
  return;

}

void SaveLoad::Load(BITMAP* EnemySprite) {
  string line;
  int token = 0;
  ifstream myfile ("saved.txt");
  if (myfile.is_open())
  {
    while (getline (myfile,line) )
    {
     if(token == 0){
        //first token is the xCoordinate of the background
        area->SetCordinate(atoi(line.c_str()));
     }
     else if (token == 1)
     {
         //Second token has the position of the Fighter
        lst->GetHead()->data->SetPosition(float(atoi(line.c_str())), 400.0f);
     }
     else if(token = 2){
        lst->GetHead()->data->SetHealth(atoi(line.c_str()));
     }
     else {
        //All the rest of the tokes have position(s) of the enemies
        Enemy *enemyObj = new Enemy(&EnemySprite[rand()%3], float((atoi(line.c_str()))), 400.0f);
        enemyObj->SetTarget(lst->GetHead()->data);
        lst->Insert(enemyObj);
     }
      cout << line << '\n';
      token++;
    }
    myfile.close();
  }

  else cout << "Unable to open file\n";


}
