//Name: Brandon Nguyen
//File Name: Monster.cpp
//Description: Implement all of the functions used in the Monster class


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Monster.h"

using namespace std;

Monster::Monster(int level){
  LoadMonster();
  m_name = SummonMonster();

  //depending on what level it is, generates the monster's stats
  switch(level){
  case 1:
    m_life = rand() % 31 + 20;
    m_attack = rand() % 5 + 1;
    break;
  case 2:
    m_life = rand() % 31 + 30;
    m_attack = rand() % 8 + 3;
    break;
  default:
    m_life = rand() % 31 + 40;
    m_attack = rand() % 11 + 5;
    break;
  }

}

Monster::~Monster(){}

string Monster::SummonMonster(){
  int randMonster = rand() % 28;
  string monsterName;
  monsterName = m_monster[randMonster];
  return monsterName;
}

//loads the enter monster.txt file into m_monster vector
void Monster::LoadMonster(){
  string name;
  ifstream inputFile;
  inputFile.open("monster.txt");
  while(getline(inputFile, name)){
    m_monster.push_back(name);
  }

  inputFile.close();
}
void Monster::Attack(Ben *&target){
  
  cout<<m_name<<" attacks "<<target->GetName()<<" using a normal attack."<<endl;
  
  //if/else used to implement damage reduction for Crystalsapien
  if(target->GetName() == "Crystalsapien"){
    cout<<m_name<<" did "<<(m_attack*3)/4<<" to "<<target->GetName()<<"."<<endl;
    target->SetLife(target->GetLife() - (m_attack*3)/4);
  }
  
  else{
    cout<<m_name<<" did "<<m_attack<<" to "<<target->GetName()<<"."<<endl;
    target->SetLife(target->GetLife() - m_attack);
  }
}
void Monster::SetLife(int life){
  if(life < 0)
    m_life = 0;
  else
    m_life = life;
}
int Monster:: GetLife(){
  return m_life;
}
string Monster::GetName(){
  return m_name;
}
