//Name: Brandon Nguyen
//File Name: ManageShips.cpp
//Description: ManageShips.cpp contains all of the function implementations for ManageShips. ManageShips has two main vectors that hold all of the personShips and all of the itemShips. Many of the main functions are writtin in this file.

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "ManageShips.h"

using namespace std;

ManageShips::ManageShips(vector< Spaceship <Item> > itemShip,
			 vector< Spaceship <Person> > personShip,
			 vector< Item > itemCargo,
			 vector< Person > personCargo){
  m_itemShips = itemShip;
  m_personShips = personShip;
  m_items = itemCargo;
  m_person = personCargo;
}
void ManageShips::LoadItemShip(){}
void ManageShips::LoadPersonShip(){}
void ManageShips::DisplayItemLeft(){}
void ManageShips::DisplayPersonLeft(){}
void ManageShips::OutputShips(){
  cout<<"File Output"<<endl;
  //opens file for file i/o
  ofstream file("proj5_output.txt");
  file<<"**Personnel Ships**";
  
  //for-loop to print all of the contents of personShips and the contents within each individual ship
  for(int i = 0; i < m_personShips.size(); i++){
    file<<"**Ship Name: "<< m_personShips[i].GetName();
    for(int j = 0; j < m_personShips[i].GetCapacity(); j++){
      file<<m_personShips[i][j].GetFName()<<" "<<m_personShips[i][j].GetLName();
    }
  }
  
  //for-loop to print all of the contents of itemShips and the contents within each individual ship
  file<<"**Item Ships**";
  for(int i = 0; i < m_itemShips.size(); i++){
    file<<"**Ship Name: "<< m_itemShips[i].GetName();
    for(int j = 0; j < m_itemShips[i].GetCapacity(); j++){
      file<<m_itemShips[i][j].GetName();
    }
  }
  file.close();
}
string ManageShips::GetHeaviestShip(){
  vector<int> PersonWeights;
  int TotalWeight;
  string shipType = "Person";
  //Populates vector that holds weights(int) of every PersonShip
  for(int i = 0; i < m_personShips.size(); i++){
    TotalWeight = 0;
    for(int j = 0; j < m_personShips[i].GetCapacity(); j++){
      TotalWeight += m_personShips[i][j].GetWeight();
    }
    PersonWeights.push_back(TotalWeight);
  }
  vector<int> ItemWeights;

  //Populates vector that holds weights(int) of every itemShip
  for(int i = 0; i < m_itemShips.size(); i++){
    TotalWeight = 0;
    for(int j = 0; j < m_itemShips[i].GetCapacity(); j++){
      TotalWeight += m_itemShips[i][j].GetWeight();
    }
    ItemWeights.push_back(TotalWeight);
  }
  
  //determines the heaviest personShip
  int HeaviestPersonShip = PersonWeights[0];
  int personIndex = 0;
  for(int i = 1; i < PersonWeights.size(); i++){
    if(HeaviestPersonShip < PersonWeights[i]){
      HeaviestPersonShip = PersonWeights[i];
      personIndex = i;
    }
  }
  //determines the heaviest itemShip
  int HeaviestItemShip = ItemWeights[0];
  int itemIndex = 0;
  for(int i = 1; i < ItemWeights.size(); i++){
    if(HeaviestItemShip < ItemWeights[i]){
      ItemItemShip = ItemWeights[i];  
      itemIndex = i;
    }
  }
  
  //creates a pointer that will point to the Heaviest Ship (either type)
  Spaceship* HeaviestShip = m_personShips[personIndex];
  //determines if the heaviest ship is from personShips or from itemShips
  if(HeaviestPersonShip < HeaviestItemShip){
    HeaviestShip = m_itemShips[itemIndex];
    shipType = "Item";
  }
  

  //print statements
  cout<<"**Heaviest Ship**"<<endl;
  cout<<"Ship Type: "<<shipType<<endl;
  cout<<"Ship Name: "<<HeaviestShip->GetName()<<endl;
  if(shipType == "Person"){
    cout<<"Total Weight: "<<PersonWeights[personIndex]<<endl;
    cout<<"Total Capacity: "<<HeaviestShip->GetCapacity()<<endl;
  }
  else{
    cout<<"Total Weight: "<<ItemWeights[itemIndex]<<endl;
    cout<<"Total Capacity: "<<HeaviestShip->GetCapacity()<<endl;
  }
  return "\n";
}
string ManageShips::GetLightestShip(){
  vector<int> PersonWeights;
  int TotalWeight;
  string shipType = "Person";
  //Populates vector that holds weights(int) of every PersonShip
  for(int i = 0; i < m_personShips.size(); i++){
    TotalWeight = 0;
    for(int j = 0; j < m_personShips[i].GetCapacity(); j++){
      TotalWeight += m_personShips[i][j].GetWeight();
    }
    PersonWeights.push_back(TotalWeight);
  }
  vector<int> ItemWeights;

  //Populates vector that holds weights(int) of every itemShip
  for(int i = 0; i < m_itemShips.size(); i++){
    TotalWeight = 0;
    for(int j = 0; j < m_itemShips[i].GetCapacity(); j++){
      TotalWeight += m_itemShips[i][j].GetWeight();
    }
    ItemWeights.push_back(TotalWeight);
  }
  //determines the lightest PersonShip
  int HeaviestPersonShip = PersonWeights[0];
  int personIndex = 0;
  for(int i = 1; i < PersonWeights.size(); i++){
    if(HeaviestPersonShip > PersonWeights[i]){
      HeaviestPersonShip = PersonWeights[i];
      personIndex = i;
    }
  }
  //determines the lightest ItemShip
  int HeaviestItemShip = ItemWeights[0];
  int itemIndex = 0;
  for(int i = 1; i < ItemWeights.size(); i++){
    if(HeaviestItemShip > ItemWeights[i]){
      ItemItemShip = ItemWeights[i];
      itemIndex = i;
    }
  }

  Spaceship* HeaviestShip = m_personShips[personIndex];
  if(HeaviestPersonShip > HeaviestItemShip){
    HeaviestShip = m_itemShips[itemIndex];
    shipType = "Item";
  }

  cout<<"**Lightest Ship**"<<endl;
  cout<<"Ship Type: "<<shipType<<endl;
  cout<<"Ship Name: "<<HeaviestShip->GetName()<<endl;
  //different print statements depending on the type of ship
  if(shipType == "Person"){
    cout<<"Total Weight: "<<PersonWeights[personIndex]<<endl;
    cout<<"Total Capacity: "<<HeaviestShip->GetCapacity()<<endl;
  }
  else{
    cout<<"Total Weight: "<<ItemWeights[itemIndex]<<endl;
    cout<<"Total Capacity: "<<HeaviestShip->GetCapacity()<<endl;
  }
  return "\n";
}
string ManageShips::GetLightestItem(){
  Item* LightestInShip;
  Item* LightestOverall;
  LightestOverall = m_itemShips[0][0];
  //for-loop to go through every ship in m_itemShips
  for(int i = 0; i < m_itemShips.size(); i++){
    LightestInShip = m_itemShips[i][0];
    //for-loop to go through every item in each ship
    for(int j = 1; j < m_itemShips[i].GetCapacity(); j++){
      if(LightestInShip->GetWeight() > m_itemShips[i][j]->GetWeight())
        LightestInShip = m_itemShips[i][j];
    }
    if(LightestOverall->GetWeight() > LightestInShip->GetWeight()){
      LightestOverall = LightestInShip;
    }
  }
  cout<<"**Lightest Item**"<<endl;
  cout<<"Item Name: "<<LightestOverall->GetName()<<endl;
  cout<<"ID: "<<LightestOverall->GetId()<<endl;
  cout<<"Weight: "<<LightestOverall->GetWeight();
  return "\n";
}
string ManageShips::GetHeaviestItem(){
  Item* HeaviestInShip;
  Item* HeaviestOverall;
  HeaviestOverall = m_itemShips[0][0];
  //for-loop to go through every ship in m_itemShips
  for(int i = 0; i < m_itemShips.size(); i++){
    HeaviestInShip = m_itemShips[i][0];
    //for-loop to go through every item in each ship
    for(int j = 1; j < m_itemShips[i].GetCapacity(); j++){
      if(HeaviestInShip->GetWeight() < m_HeaviestShips[i][j]->GetWeight())
        HeaviestInShip = m_itemShips[i][j];
    }
    if(HeaviestOverall->GetWeight() < HeaviestInShip->GetWeight()){
      HeaviestOverall = HeaviestInShip;
    }
  }
  cout<<"**Heaviest Item**"<<endl;
  cout<<"Item Name: "<<HeaviestOverall->GetName()<<endl;
  cout<<"ID: "<<HeaviestOverall->GetId()<<endl;
  cout<<"Weight: "<<HeaviestOverall->GetWeight();
  return "\n";
}
string ManageShips::GetOldestPerson(){
  Person* OldestInShip;
  Person* OldestOverall;
  OldestOverall = m_personShips[0][0];
  //for-loop to go through every ship in m_personShips
  for(int i = 0; i < m_personShips.size(); i++){
    OldestInShip = m_personShips[i][0];
    //for-loop to go through every person in each ship
    for(int j = 1; j < m_personShips[i].GetCapacity(); j++){
      if(OldestInShip->GetAge() < m_personShips[i][j]->GetAge())
        OldestInShip = m_personShips[i][j];
    }
    if(OldestOverall->GetAge() < OldestInShip->GetAge()){
      OldestOverall = OldestInShip;
    }
  }
  cout<<"**Oldest Person**"<<endl;
  cout<<"First Name: "<<OldestOverall->GetFName<<endl;
  cout<<"Last Name: "<<OldestOverall->GetLName<<endl;
  cout<<"Age: "<<OldestOverall->GetAge();
  cout<<"Weight: "<<OldestOverall->GetWeight();
  return "\n";
}
string ManageShips::GetYoungestPerson(){
  Person* YoungestInShip;
  Person* YoungestOverall;
  YoungestOverall = m_personShips[0][0];
  //for-loop to go through every ship in m_personShips
  for(int i = 0; i < m_personShips.size(); i++){
    YoungestInShip = m_personShips[i][0];
    //for-loop to go through every person in each ship
    for(int j = 1; j < m_personShips[i].GetCapacity(); j++){
      if(YoungestInShip->GetAge() > m_personShips[i][j]->GetAge())
	YoungestInShip = m_personShips[i][j];
    }
    if(YoungestOverall->GetAge() > YoungestInShip->GetAge()){
      YoungestOverall = YoungestInShip;
    }
  }
  cout<<"**Youngest Person**"<<endl;
  cout<<"First Name: "<<YoungestOverall->GetFName<<endl;
  cout<<"Last Name: "<<YoungestOverall->GetLName<<endl;
  cout<<"Age: "<<YoungestOverall->GetAge();
  cout<<"Weight: "<<YoungestOverall->GetWeight();
  return "\n";
}
