//Name: Brandon Nguyen
//File Name: Ben.cpp
//Description: Implement all of the functions used in the Ben class


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Ben.h"
#include "Monster.h"
using namespace std;

Ben::Ben(string name, int life){
  //default values for Ben
  m_name = name;
  m_life = life;
  m_nameNormal = "hand-to-hand";
  m_nameSpecial = "kick";
  m_defenseBonus = 0;
  m_missPercent = 0.1;
  m_usedSpecial = 0;
  m_maxSpecial = 2;
  m_minDamageNormal = 10;
  m_maxDamageNormal = 20;
  m_damageSpecial = 25;
}

Ben::Ben(string name, int life, string nameNorm, string nameSpecial,
	 double defenseBonus, double missPercent, int usedSpecial,
	 int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec){
  m_name = name;
  m_life = life;
  m_nameNormal = nameNorm;
  m_nameSpecial = nameSpecial;
  m_defenseBonus = defenseBonus;
  m_missPercent = missPercent;
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial;
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm;
  m_damageSpecial = damSpec;

}

Ben::~Ben(){}

void Ben::Attack(Monster *&target){
  double hit = ((double) rand() / 1.0);
  int damage;
  //if the attack missed
  if(hit < m_missPercent){
    cout<<m_name<<" missed his "<<m_nameNormal<<" attack."<<endl;
  }
  //if the attack successfully hit
  else{
    cout<<m_name<<" attacks using his "<<m_nameNormal<<" attack."<<endl;
    damage = rand() % (m_maxDamageNormal - m_minDamageNormal + 1) + m_minDamageNormal;
    cout<<m_name<<" did "<<damage<<" to "<<target->GetName()<<"."<<endl;
    target->SetLife(target->GetLife() - damage);
  }
  cout<<m_name<<": "<<m_life<<"\t"<<target->GetName()<<": "<<target->GetLife();
  
}

void Ben::SpecialAttack(Monster *&target){
  //checks to see if there are any special attacks available
  if(m_usedSpecial == m_maxSpecial){
    cout<<m_name<<" is out of special attacks!"<<endl;
  }
  else{
    cout<<m_name<<" attacks using his "<<m_nameSpecial<<" attack."<<endl;
    cout<<m_name<<" did "<<m_damageSpecial<<" to "<<target->GetName()<<"."<<endl;
    target->SetLife(target->GetLife() - m_damageSpecial); 
    cout<<m_name<<": "<<m_life<<"\t"<<target->GetName()<<": "<<target->GetLife();
    m_usedSpecial += 1;
  }
}
void Ben::UltimateAttack(Monster *&target){
  cout<<GetName()<<" has no Ultimate Attack!"<<endl;
}


//Basic accessors and mutator
void Ben::SetLife(int life){
  if(life < 0)
    m_life = 0;
  else
    m_life = life;
}

string Ben::GetName(){
  return m_name;
}

int Ben::GetLife(){
  return m_life;
}

