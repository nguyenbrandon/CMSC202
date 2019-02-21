//Name: Brandon Nguyen
//File Name: Item.cpp
//Description: Item.cpp has all of the code for the functions from Item.h. Just filled in the contructor, basic accessors/mutators and the ToString() function.
#include <iostream>
#include "Item.h"
#include <sstream>

using namespace std;

Item::Item(){}
Item::Item(int inId, string inName, float inWeight){
  m_id = inId;
  m_name = inName;
  m_weight = inWeight;
}

int Item:: GetId() const{
  return m_id;
}
string Item::GetName() const{
  return m_name;
}
float Item::GetWeight() const{
  return m_weight;
}

string Item::ToString() const{
  ostringstream temp;
  temp << m_id << " " << m_name << " " << m_weight <<endl;
  return temp.str();
}

