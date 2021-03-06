#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<Student>&);
// fill vector - fills student info
// @param vector<Student>& - students in class
// Passed by reference

void printVector(vector<Student>&);
// printVector - prints the information of all students
// @param const vector<Student>& students in class
// Passed by reference

int main () {
  //Creates a new vector of Students
  vector<Student> myClass;

  //Populates the vector
  fillVector(myClass);

  //Prints the contents of the vector
  printVector(myClass);

  return 0;
}


void fillVector(vector<Student>& newMyClass) {
  //Write this function
  //Needs to ask how many students
  //Gets first name, last name, and ID of a student
  //Uses the overloaded constructor for the Student
  //Needs to add student to the vector
  string fname, lname;
  int numStud, studId;
  cout<<"Hello, how many new students are there?: ";
  cin>>numStud;
  
  for(int i = 0; i < numStud; i++){
    
    cout<<"Hello, please enter the first name of the student: ";
    cin>>fname;
    cout<<"Hello, please enter the last name of the student: ";
    cin>>lname;
    cout<<"Hello, please enter the student's ID: ";
    cin>>studId;
    cout<<endl;

    Student newStudent(fname, lname, studId);
    newMyClass.push_back(newStudent);

  }
}

void printVector(vector<Student>& newMyClass){
  //Needs to loop through the vector of Students and outputs the information
  for(unsigned int i = 0; i< newMyClass.size(); i++){
    cout<<newMyClass[i].GetFirstName()<<endl;;
    cout<<newMyClass[i].GetLastName()<<endl;;
    cout<<newMyClass[i].GetID()<<endl;;
  }




}
