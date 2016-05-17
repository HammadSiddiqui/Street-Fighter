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

void SaveLoad::Load() {
  string line;
  int token = 0;
  ifstream myfile ("saved.txt");
  if (myfile.is_open())
  {
    while (getline (myfile,line) )
    {
     if(token == 0){
        area->SetCordinate(std::stoi(line)); //take care of the \n in the end
     }
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";


}
