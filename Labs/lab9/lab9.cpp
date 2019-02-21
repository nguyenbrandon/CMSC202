#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
  IntArray ia(10);
  IntArray dos(-1);
  IntArray tres(0);
  
  IntArray cuatro(ia);
  IntArray cinco = ia;
  if(cuatro == dos)
    cout<<"Hi"<<endl;
  else if(cuatro != dos)
    cout<<"Nty"<<endl;

  tres += tres;

  cout<<ia[-10]<<endl;
  
  IntArray seis = ia + tres + dos;
  IntArray siete = tres + dos;

  ia.Get(-1);
  ia.Get(0);
  ia.Get(100);

  ia.SetItem(-1, 100.0);
  ia.SetItem(100,-1.0);

  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
