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
//  int playerPos = this->lst->GetHead()->data->GetPosition().x;
//  string strbuffer = std::to_string(12);
  savefile << "Hello world\n";
//myfile << "Writing this to a file.\n";
  savefile.close();
  std::cout << "Hola";
  return;

}
