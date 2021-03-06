//Name: Brandon Nguyen
//File Name: Pyronite.cpp
//Description: Implement all of the functions used in the Pyronite class - overrides the Attack and SpecialAttack functions.


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Pyronite.h"
#include "Monster.h"
using namespace std;


void Pyronite::Attack(Monster *&target){
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

void Pyronite::SpecialAttack(Monster *&target){
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


