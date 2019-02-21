//Name: Brandon Nguyen
//File Name: Spaceship.cpp 
//Description: Spaceship.cpp is the templated class used in this project. Contains all of the code for the functions seen in Spaceship.h. Also has the overloaded functions for the > and < symbols.
#include <iostream>
#include "Spaceship.h"

using namespace std;

template <class T>
Spaceship::Spaceship(){}
Spaceship::Spaceship(string inName, string inType, double inCapacity){
  m_name = inName;
  m_type = inType;
  m_capacity = inCapacity;
}
vector<T> Spaceship::GetCargo() const{
  return m_cargo;
}
const T& Spaceship::GetCargoAt(int index) const{
  return m_cargo[index];
}
void Spaceship::AddCargo(T inputObject){
  m_cargo.push_back(inputObject);
}
string Spaceship::ToString() const{
  ostringstream temp;
  temp << m_name << " " << m_type << " " << m_capacity << endl;
  return temp.str();
}
double Spaceship::GetCapacity() const{
  return m_capacity;
}
string Spaceship::GetName() const{
  return m_name;
}
template <class U>
bool Spaceship::operator>( Spaceship<U> &otherShip){
  if(m_weight > otherShip.GetWeight())
    return true;
  else
    return false;
}

template <class U>
bool Spaceship::operator<( Spaceship<U> &otherShip){
  if(m_weight < otherShip.GetWeight())
    return true;
  else
    return false;
}

