#include <iostream>
#include "ReadySupply.h"

using namespace std;

ReadySupply::ReadySupply(){}
ReadySupply::ReadySupply(string shipFile, string cargoFile){
  m_shipFile = shipFile;
  m_cargoFile = cargoFile;
}
void LoadShips(){}
void LoadCargo(){}
vector< Spaceship<Item> > GetItemShips(){}
vector< Spaceship<Person> > GetPersonShips(){}
vector< Item > GetItemCargo(){}
vector< Person > GetPersonCargo(){}

