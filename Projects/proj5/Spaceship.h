#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Item.h"
#include "Person.h"

#include <vector>
#include <sstream> //Used to concatenate a string that includes numbers
#include <iomanip> //Used to format weights to make more sense

using namespace std;

template <class T>
class Spaceship
{
 public:
  //Name: Spaceship
  //Default constructor 
  Spaceship();
  
  //Name: Spaceship(string, string, double) Overloaded constructor.
  //Precondition: Requires ship file has been loaded
  //Postcondition: Builds a new templated ship
  Spaceship(string inName, string inType, double inCapacity);

  //Name: GetCargo
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo
  vector<T> GetCargo() const;

  //Name: GetCargoAt
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo at a specific location
  const T& GetCargoAt(int index) const;

  //Name: AddCargo
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Adds an item into this ship
  void AddCargo(T inputObject);
  //Name: ToString
  //Precondition: Requires that the ships and cargo have been loaded
  //Postcondition: Used to output information about a specific ship
  string ToString() const;
  //Name: GetCapacity
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the capacity of a ship
  double GetCapacity() const;
  //Name: GetName
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the name of a ship
  string GetName() const;

  //Name: operator> (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship heavier including cargo
  template <class U>
  bool operator>( Spaceship<U> &otherShip) ;
  //Name: operator< (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship lighter including cargo
  template <class U>
  bool operator<( Spaceship<U> &otherShip) ;

private:
  string m_name;
  string m_type;
  double m_capacity;
  vector<T> m_cargo;	
};
//*************************************************************
//You need to implement all of this code - it is templated so we can't split the file

#endif
