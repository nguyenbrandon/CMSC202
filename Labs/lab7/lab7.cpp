#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//This code is supposed to randomly generate an integer.
//Then it is supposed to print out the integer
//Then it is supposed to print out the pointer to the integer
//Then it passes the pointer to the function.
//The function prints out each of the digits in reverse order.
//For example, 345 would print 5 then 4 then 3

//There are two errors - one is a runtime that causes a segmentation fault
//The other is a logical error. Find them using gdb.

void printEach(int num); //Function Prototype
int main () {
  cout << "Welcome to Lab 7" << endl;
  int num = 10; //New integer
  int *ptrNum = &num; //New pointer to num
  srand(time(NULL)); //Seeds the random number generator
  num = rand(); //Generates a new random number for num
  cout << num << endl; //Prints num
  cout << *ptrNum << endl; //Prints the dereferenced ptrNum
  printEach(*ptrNum); //Passes the dereferenced ptrNum to printEach
  return 0;
}

void printEach(int num){
  //Figures out how many digits are in the number
  int numDigits = num > 0 ? (int) log10 ((double) num) + 1 : 1;
  cout << numDigits << endl;
  //Iterates through the number and prints each number out in reverse order
  for(int i = 0; i < numDigits ; i++){
    cout << num % (10) << endl;
    num /= 10;
  }
}
