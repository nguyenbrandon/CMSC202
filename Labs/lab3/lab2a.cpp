
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



void extraCredit(int &score){
  int temp = score + 2;
  cout<<temp<<endl;

}

int main(){
  
  int score1, score2;
  cout<<"Enter score 1: ";
  cin>>score1;

  
  cout<<"Enter score 2: ";
  cin>>score2;

  
  extraCredit(score1);
  extraCredit(score2);
  
  
  return 0;
}
