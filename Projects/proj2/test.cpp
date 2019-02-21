#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Pokemon.cpp"
#include "MyPokemon.cpp"


using namespace std;


int main(){
  /*
  THIS PART WAS USED TO TEST POKEMON.CPP & POKEMON.H
  
  Pokemon bafoon(151, "bafoon1", 5, 10, 3);
  
  cout<<"Testing GetCPMin()\n"<<bafoon.GetCPMin()<<endl;
  cout<<"Testing GetCPMax()\n"<<bafoon.GetCPMax()<<endl;
  cout<<"Testing GetRarity()\n"<<bafoon.GetRarity()<<endl;
  cout<<"Testing GetName()\n"<<bafoon.GetName()<<endl;
  cout<<"Testing GetNum()\n"<<bafoon.GetNum()<<endl;

  bafoon.SetRarity(1);
  cout<<"New Rarity should be 1:\n"<<bafoon.GetRarity()<<endl;

  bafoon.SetName("bafoon2");
  cout<<"New name should be bafoon2\n"<<bafoon.GetName()<<endl;
  
  bafoon.SetCP(4);
  */
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /*
  THIS TESTS MYPOKEMON.H & MYPOKEMON.CPP

  MyPokemon slave(151, "Pikachu", 100, 200, 5);
  cout<<"Testing GetCP()\n"<<slave.GetCP()<<endl;
  cout<<"Testing GetHP()\n"<<slave.GetHP()<<endl;
  cout<<"Testing GetRarity()\n"<<slave.GetRarity()<<endl;
  cout<<"Testing GetName()\n"<<slave.GetName()<<endl;
  cout<<"Testing GetNum()\n"<<slave.GetNum()<<endl;
  
  slave.SetRarity(3);
  cout<<"New rarity should be 3:\n"<<slave.GetRarity()<<endl;
  slave.SetName("Snorlax");
  cout<<"Pikachu has evolved into...?\n"<<slave.GetName()<<endl;
  slave.SetCP(500);
  cout<<"New CP should be that phat 500:\n"<<slave.GetCP()<<endl;
  slave.SetHP(1000);
  cout<<"Should be old Warmog's HP value:\n"<<slave.GetHP()<<endl;
  
  slave.Train();
  cout<<"New CP should be that phat 510:\n"<<slave.GetCP()<<endl;
  */


  return 0;
}
