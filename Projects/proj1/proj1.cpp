/* Student name: Brandon Nguyen
   Date: September 26, 2016
   Assignment: Project 1
   Descrption: First project is an ATM simulator that excercises the usage of
               branching structures, calling functions, simple file I/O, and
	       the differnece between pass by value and pass by reference.

*/

#include "proj1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//First menu, should only be displayed once. Returns 1-3
int menuStart(){
  cout<<endl;
  cout<<"Welcome to the UMBC ATM"<<endl;
  cout<<"Choose from below:"<<endl;
  cout<<"1. Load a user Profile from File"<<endl;
  cout<<"2. Enter a new User Profile"<<endl;
  cout<<"3. Exit"<<endl;
  cout<<"Enter your choice: ";
  int selection;
  cin>>selection;
  return selection;
}

//Second menu that comes after user information has been loaded.
//Prints after every function until user exits the ATM machine.
int menuMain(){
  cout<<endl;
  cout<<"********Please choose option from the menu*********"<<endl;
  cout<<"1. Account Balance"<<endl;
  cout<<"2. Deposit money"<<endl;
  cout<<"3. Withdraw money"<<endl;
  cout<<"4. Display your account details"<<endl;
  cout<<"5. Exit"<<endl;
  cout<<"Enter your choice: ";
  int selection2;
  cin>>selection2;
  return selection2;
}

//if user selects '4', all account details are printed
void displayAccountDetails(string fName, string lName, int age, float accountBalance){
  cout<<"First Name: " + fName<<endl;
  cout<<"Last Name: " + lName<<endl;
  cout<<"Age: ";
  cout<<age<<endl;
  displayBalance(accountBalance);
  
}

//if user selects '1', only the account balance is displayed.
//function is also called by the displayAccountDetails() function
void displayBalance(float accountBalance){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout.fill(0);

  cout<<"Account Balance: $";
  cout<<accountBalance<<endl;
}

//function used to deposit money into the user's account. 
//User cannot deposit a negative amount
void deposit(float &accountBalance){
  cout<<"Please enter the amount to be deposited"<<endl;
  
  float depositAmount;
  cin>>depositAmount;
  if(depositAmount < 0)
    cout<<"Amount should be greater than 0"<<endl;
  else{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.fill(0);

    cout<<"$";
    cout<<depositAmount;
    cout<<" deposited to your account"<<endl;
    accountBalance += depositAmount;
  }
}

//Function used to withdraw money from the account balance.
//User cannot withdraw a negative amount of money.
void withdraw(float &accountBalance){
  cout<<"Please enter the amount to be withdrawn"<<endl;

  float withdrawAmount;
  cin>>withdrawAmount;
  if(withdrawAmount < 0)
    cout<<"Amount should be greater than 0"<<endl;
  else if(withdrawAmount > accountBalance)
    cout<<"Insufficient funds"<<endl;
  else{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.fill(0);
    
    cout<<"$";
    cout<<withdrawAmount;
    cout<<" withdrawn from your account"<<endl;
    accountBalance -= withdrawAmount;

  }
}

//main function that exercises all functions above.
int main(){
  
  //creates variables for user information
  string fName;
  string lName;
  int age;
  float accountBalance;
  string fileName;

  //selection - variable used to exit first menu
  //selction2 - variable used to exit second menu
  int selection = 1;
  int selection2 = 1;
  
  //using a do-while loop because menuStart() is ran at least once
  do{
    selection = menuStart();
    switch(selection){
      
    case 1:
      {
	cout<<"Input file name: ";
	cin>>fileName;
	cout<<endl;
	ifstream inputFile;
	inputFile.open(fileName.c_str());
	string var;
	inputFile>>fName;
	inputFile>>lName;
	inputFile>>age;
	inputFile>>accountBalance;
	inputFile.close();
	selection = 3;
	break;
      }
    case 2:
      cout<<"Please enter the following:"<<endl;
      cout<<"First name:"<<endl;
      cin>>fName;
      cout<<"Last Name:"<<endl;
      cin>>lName;
      cout<<"Age:"<<endl;
      cin>>age;
      cout<<"Initial Deposit:"<<endl;
      cin>>accountBalance;
      cout<<"$";
      cout<<accountBalance;
      cout<<" deposited"<<endl;
      selection = 3;
      break;
    case 3:
      cout<<"Exiting now."<<endl;
      selection2 = 5;
      break;
    default:
      cout<<"Invalid input, please enter a number 1-3"<<endl;
      
    }
  }while(selection != 3);
  

  //use a while loop for the second menu because menuMain() is not always run.
  //The ONLY time menuMain() is not run is when the user enters '3' during menuStart()
  while(selection2 != 5){
    selection2 = menuMain();
    
    switch(selection2){
    case 1:
      displayBalance(accountBalance);
      break;
    case 2:
      deposit(accountBalance);
      break;
    case 3:
      withdraw(accountBalance);
      break;
    case 4:
      displayAccountDetails(fName, lName, age, accountBalance);
      break;
    case 5:
      {
	//saves user information and account balance to the desired file name that they entered earlier
	cout<<"Would you like to save your account information?:"<<endl;
	cout<<"yes or no"<<endl;
	string decision;
	cin>>decision;
	if(decision == "yes"){
	  ofstream outputFile;
	  outputFile.open(fileName.c_str());
	  outputFile<<fName<<" "<<lName<<" "<<age<<" "<<accountBalance;
	  outputFile.close();
	  cout<<"File Saved"<<endl;
	}
	
	selection2 = 5;
	break;
      }
    default:
      cout<<"Invalid input, please enter a number 1-5"<<endl;
    }
  }

  cout<<"Thank you for using the UMBC ATM!"<<endl;
  return 0;
}
