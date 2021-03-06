/* File name: proj2.cpp
   Name: Brandon Nguyen
   Date: October 18, 2016
   Description: This file is where all of the functions from proj2.h are implemented. This is where most of the code resides and the program is suppose to function as a mini-PokemonGo. The user is able to catch pokemon, battle their pokemon, and train pokemon.

*/

#include "proj2.h"
#include <iostream>     /* cout, cin */
#include <vector>       /* vector */
#include <string>       /* string */
#include <fstream>      /* fstream, ifstream, ofstream */
#include <iomanip>      /* setw, setfill, etc */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void getPokeDex(vector <Pokemon> & pokeDex){
  int num;
  string name;
  int cpMin;
  int cpMax;
  int rarity;
  
  ifstream inputFile;
  inputFile.open(POKEDEX);
  //runs till 151
  for(int i = 0; i < POKECOUNT; i++){
    inputFile>>num;
    inputFile>>name;
    inputFile>>cpMin;
    inputFile>>cpMax;
    inputFile>>rarity;
    //creates temporary Pokemon and adds it to the pokeDex vector
    Pokemon temp(num, name, cpMin, cpMax, rarity);
    pokeDex.push_back(temp);
    }
  inputFile.close();
}

void getMyCollection(vector<MyPokemon> & myCollection){
  int num;
  string name;
  int CP;
  int HP;
  int rarity;

  ifstream inputFile;
  inputFile.open(MYCOLLECTION);
  while(!inputFile.eof()){
  
    inputFile>>num;
    inputFile>>name;
    inputFile>>CP;
    inputFile>>HP;
    inputFile>>rarity;
    //creates temporary MyPokemon and adds it to myCollection vector
    MyPokemon temp(num, name, CP, HP, rarity);
    myCollection.push_back(temp);
  }
  myCollection.pop_back();
  inputFile.close();

}
void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  
  int rarityChoice;
  cout<<"What type of Pokemon would you like to try and catch?:"<<endl;
  cout<<"1. Very Common (Very High Probability)"<<endl;
  cout<<"2. Common (High Probability)"<<endl;
  cout<<"3. Uncommon (Normal Probability)"<<endl;
  cout<<"4. Rare (Low Probability)"<<endl;
  cout<<"5. Ultra Rare (Extremely Low Probability)"<<endl;
  cin>>rarityChoice;
  
  int randNum; //variable used to determine if the user has caught a Pokemon
  randNum = rand() % 100 + 1;
  cout<<"Your start to search."<<endl;
  
  switch(rarityChoice){ //switches to the rarity selected
  case 1:
    if(randNum >= 1 && randNum <= 65) //depending on rarity, checks to see if caught
      foundPokemon(rarityChoice, pokeDex, myCollection);
    else
      cout<<"You did not find any Pokemon"<<endl;
    break;
  case 2:
    if(randNum >= 1 && randNum <= 45) //depending on rarity, checks to see if caught
      foundPokemon(rarityChoice, pokeDex, myCollection);
    else
      cout<<"You did not find any Pokemon"<<endl;
    break;
  case 3:
    if(randNum >= 1 && randNum <= 25) //depending on rarity, checks to see if caught
      foundPokemon(rarityChoice, pokeDex, myCollection);
    else
      cout<<"You did not find any Pokemon"<<endl;
    break;
  case 4:
    if(randNum >= 1 && randNum <= 10) //depending on rarity, checks to see if caught
      foundPokemon(rarityChoice, pokeDex, myCollection);
    else
      cout<<"You did not find any Pokemon"<<endl;
    break;
  case 5:
    if(randNum == 1) //depending on rarity, checks to see if caught
      foundPokemon(rarityChoice, pokeDex, myCollection);
    else
      cout<<"You did not find any Pokemon"<<endl;
    break;
  default:
    cout<<"Invalid input!"<<endl;
    break;

  }
}

void printPokeDex(vector <Pokemon> & pokeDex){
  for(unsigned int i = 0; i< pokeDex.size(); i++){
    cout<<pokeDex[i].GetNum()<<" "<<pokeDex[i].GetName()<<endl;;
  }
}

void printMyCollection(vector <MyPokemon> & myCollection){
  for(unsigned int i = 0; i< myCollection.size(); i++){
    cout<<i<<". "<<myCollection[i].GetNum()<<" "<<myCollection[i].GetName()<<" "<<myCollection[i].GetCP()
	<<" "<<myCollection[i].GetHP()<<" "<<myCollection[i].GetRarity()<<endl;
  }

}
void foundPokemon(int rarity,vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection ){
  //creates a temporary Vector of Pokemon
  vector<Pokemon> tempVec;
  //fills the temp vector with Pokemon of selected rarity
  for(unsigned int i = 0; i<pokeDex.size(); i++){
    if(pokeDex[i].GetRarity() == rarity){
      tempVec.push_back(pokeDex[i]);
    }
  }
  //selects a random Pokemon out of tempVec
  int randomPokemon;
  randomPokemon = rand() % tempVec.size() + 0;
  int tempNum = tempVec[randomPokemon].GetNum(); //num of selected pokemon
  string tempName = tempVec[randomPokemon].GetName(); //name of pokemon
  int cp = rand() % tempVec[randomPokemon].GetCPMax() + tempVec[randomPokemon].GetCPMin(); //CP of pokemon
  int hp = cp * 0.1; // hp of pokemon

  cout<<"Congrats! You found a "<<tempName<<endl; //informs user of caught pokemon
  MyPokemon tempPoke(tempNum, tempName, cp, hp, rarity); //creates a temp MyPokemon of the caught pokemon and adds it to the end of MyCollection
  myCollection.push_back(tempPoke);
}
void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> &myCollection){
  int selection;
  int stopper = 0;
  
  while(stopper != -1){
    cout<<"What would you like to do?:"<<endl;
    cout<<"1. See the PokeDex"<<endl;
    cout<<"2. See your collection"<<endl;
    cout<<"3. Search for a new Pokemon"<<endl;
    cout<<"4. Battle your Pokemon"<<endl;
    cout<<"5. Train your Pokemon"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>selection;
    cout<<endl;
    switch(selection){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex, myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      stopper = -1;
      break;
    default:
      cout<<"invalid input, please enter 1 - 6"<<endl;
    }
    cout<<endl;
  }
}

void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  printMyCollection(myCollection);
  int randPokemon = rand() % 151 + 1; //random opponent selected
  cout<<"You are going to fight a "<<pokeDex[randPokemon].GetName()<<endl;
  int randCP = rand() % pokeDex[randPokemon].GetCPMax() + pokeDex[randPokemon].GetCPMin(); //random CP generated for the opponent
  cout<<"The enemy has a CP of "<<randCP<<endl;
  cout<<"Which of your Pokemon would you like to use?:"<<endl;
  unsigned int contestant = -1;
  const unsigned int poo = -1;
  while(contestant == poo){//input validation for user selecting their pokemon
    cin>>contestant;
    if(contestant < 0 || contestant >myCollection.size()){
      cout<<"invalid input"<<endl;
      cout<<"Which of your Pokemon would you like to use?:"<<endl;
      contestant = -1;
    }
  }
  if(myCollection[contestant].GetCP() > randCP)
    cout<<"You win!"<<endl;
  else
    cout<<"You lose!"<<endl;
}

void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  cout<<"Which of your Pokemon would you like to use?:"<<endl;
  printMyCollection(myCollection);
  int trainee;
  cin>>trainee;
  
  myCollection[trainee].Train();
  cout<<"Your "<<myCollection[trainee].GetName()<<" trained."<<endl;
  cout<<"Your CP is now "<<myCollection[trainee].GetCP()<<endl;
}

void exitPokemon(vector<MyPokemon> & myCollection){
  saveMyCollection(myCollection);
}

void saveMyCollection(vector<MyPokemon> & myCollection){
  ofstream outputFile;
  outputFile.open(MYCOLLECTION);
  for(unsigned int i=0; i < myCollection.size(); i++){
    outputFile<<myCollection[i].GetNum()<<" "<<myCollection[i].GetName()<<" "<<myCollection[i].GetCP()<<" "
	      <<myCollection[i].GetHP()<<" "<<myCollection[i].GetRarity()<<endl;
  }
  
  outputFile.close();
  cout<<"File Saved"<<endl;

}



int main(){
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;

  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu(pokeDex, myCollection);
  
  cout<<"Thank you for playing Pokemon UMBC!"<<endl;
  return 0;
}
