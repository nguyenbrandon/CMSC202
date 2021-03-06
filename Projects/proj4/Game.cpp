//Name: Brandon Nguyen
//File Name: Game.cpp
//Description: Implement all of the functions used in the Game class. This includes the initialization of Ben and Monsters. Also starts the game, and runs the game. Has the game in a while loop (for m_levels) and inside is another loop (to determine the turn-based attacking) for each level.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Game.h"

using namespace std;
Game::Game(){
  m_level = 1;
  m_levels = NumLevels();
  InitBen();
  InitMonsters();
  Start(100);
}

Game::~Game(){
  //Fuck mem leaks
  for(int i = 0; i < 3; i++){
    delete m_ben[i];
  }
  for(int i = 0; i < m_levels; i++){
    delete m_mons[i];
  }
  delete[] m_ben;
  delete[] m_mons;
}

void Game::InitBen(){

  //fills in the Ben array of length 3 because there are only 3 total forms
  m_ben = new Ben*[3];
  m_ben[0] = new Ben("Ben", 100,"hand-to-hand", "kick", 0, 0.1, 0, 2, 10, 20, 25);
  m_ben[1] = new Pyronite("Pyronite", 100, "fire", "flamer", 0, 0.15, 0, 1, 15, 20, 30);
  m_ben[2] = new Crystalsapien("Crystalsapien", 100, "energy", "laser", 0.25, 0.25, 0, 1, 25, 30, 10);
}

void Game::InitMonsters(){
  m_mons = new Monster*[m_levels];
  for(int i = 0; i < m_levels; i++){
    m_mons[i] = new Monster(i);
  }
  m_currMons = m_mons[0];
}

void Game::SetBen(int startLife){
  
  if(m_level == 1)
    m_formsBen = 1;
  else if(m_level == 2)
    m_formsBen = 2;
  else
    m_formsBen = 3;
  cout<<"Select one from the available forms of Ben at level "<<m_level<<":"<<endl;
  cout<<"1. Ben"<<endl;
  if(m_level > 1){
    cout<<"2. Pyronite"<<endl;
    if(m_level > 2)
      cout<<"3. Crystalsapien"<<endl;
  }
  int selection = -1;
  cout<<"What would you like to do?"<<endl;
  while(selection < 1 || selection > m_formsBen){
    if(m_level == 1)
      cout<<"Enter 1: ";
    else if(m_level == 2)
      cout<<"Enter 1 to 2: ";
    else
      cout<<"Enter 1 to 3: ";
    cin>>selection;
    //switch statement to determine which form ben is in
    switch(selection){
    case 1:
      m_currBen = m_ben[0];
      m_currBen->SetLife(startLife);
      break;
    case 2:
      m_currBen = m_ben[1];
      m_currBen->SetLife(startLife);
      break;
    case 3:
      m_currBen = m_ben[2];
      m_currBen->SetLife(startLife);
      break;
    }
  }
}

void Game::Start(int startLife){
  SetBen(100);
  int currentMonster = 0;
  //while loop that runs until the game is OVER
  while(m_level <= m_levels && m_currBen->GetLife() > 0){
    cout<<"\t\tThe game starts...."<<endl;
    cout<<"\t\tLEVEL "<<m_level<<" of "<<m_levels<<endl;
    m_currMons = m_mons[currentMonster];
    if(m_level > 1){
      SetBen(m_currBen->GetLife());
    }
    cout<<"BEN: "<<m_currBen->GetName()<<endl;
    cout<<"MONSTER: "<<m_currMons->GetName()<<endl;
    cout<<"The start life of "<<m_currBen->GetName()<<" is: "<<m_currBen->GetLife()<<endl;
    cout<<"The start life of "<<m_currMons->GetName()<<" is: "<<m_currMons->GetLife()<<endl;
    //nested loop to orchestrate each level. Exits loop once the level is over (Ben or Monster dies)
    while(Input()){
      cout<<"What would you like to do?"<<endl;
      cout<<"1. Normal Attack"<<endl;
      cout<<"2. Special Attack"<<endl;
      cout<<"3. Ultimate Attack"<<endl;
      cout<<m_currBen->GetName()<<": "<<m_currBen->GetLife()<<"\t"<<m_currMons->GetName()<<": "<<m_currMons->GetLife()<<endl;
      int attackOption;
      cin>>attackOption;
      while(attackOption < 1 || attackOption > 3){
	cout<<"Please enter 1-3"<<endl;
	cin>>attackOption;
      }
      //switch statement to determine which type of attack the user selected
      switch(attackOption){
      case 1:
	m_currBen->Attack(m_currMons);
	break;
      case 2:
	m_currBen->SpecialAttack(m_currMons);
	break;
      case 3:
	m_currBen->UltimateAttack(m_currMons);
	break;
      }
      if(Input() == false){
	cout<<endl;
	cout<<"Congrats! "<<m_currBen->GetName()<<" has won that level."<<endl;
        m_level += 1;
	currentMonster += 1;
	if(m_level > m_levels)
	  cout<<"Congrats! You won the game."<<endl;
	break;
      }
      else{
	cout<<endl;
	m_currMons->Attack(m_currBen);
      }
      if(Input() == false){
	cout<<"Haha, Ben has died - GAME OVER."<<endl;
      }
    }
  }
}

int Game::NumLevels(){
  int numLevels = 30;
  cout<<"How many levels would you like to try?"<<endl;
  while(numLevels > 20 || numLevels < 1){
    cin>>numLevels;
    if(numLevels > 20)
      cout<<"You should do less than 20 levels!"<<endl;
    else if(numLevels < 1)
      cout<<"Invalid input, should be between 1-20"<<endl;
  }
  return numLevels;
}

bool Game::Input(){
  if(m_currBen->GetLife() > 0 && m_currMons->GetLife() > 0)
    return true;
  else
    return false;
}
