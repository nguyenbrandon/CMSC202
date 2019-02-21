//Name: Brandon Nguyen
//File Name: Person.cpp
//Description: Person.cpp has all of the code for the functions in Person.h. Just filled in the contructor, basic accessors/mutators and the ToString() function.
#include <iostream>
#include "Person.h"
#include <sstream>

using namespace std;

Person::Person(){}
Person::Person(string infName, string inlName, double inWeight, int inAge, int inId){
  m_fName = infName;
  m_lName = inlName;
  m_weight = inWeight;
  m_age = inAge;
  m_id = inId;
}

int Person::GetId() const{
  return m_id;
}
string Person::GetFName() const{
  return m_fName;
}
string Person::GetLName() const{
  return m_lName;
}
int Person::GetAge() const{
  return m_age;
}
double Person::GetWeight() const{
  return m_weight;
}

string Person::ToString() const{
  ostringstream temp;
  temp << m_id << " " << m_fName << " " << " " << m_lName << " " <<  m_weight <<endl;
  return temp.str();

}
