#include <iostream>
#include <vector>
using namespace std;

int main(){
  int selection = 0;
  vector <int> list;
  while(selection != -1){
    cout<<"Enter an integer (-1 to exit): ";
    cin>>selection;
    if(selection != -1)
      list.push_back(selection);
    
  }
  
  int spot1 = 0;
  int spot2 = list.size() - 1;
  
  for(unsigned int i = 0; i < list.size() / 2; i++){
    if(list[spot1] == list[spot2])
      cout<<"front:"<<list[spot1]<<" back:"<<list[spot2]<<" are equal."<<endl;
    if(list[spot1] != list[spot2])
      cout<<"front:"<<list[spot1]<<" back:"<<list[spot2]<<" are not equal."<<endl;
    spot1++;
    spot2--;

  }
  
  return 0;
}
