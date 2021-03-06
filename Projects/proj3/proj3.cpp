#include "LinkedList.h"
#include "proj3.h"

int main () {
  LinkedList list;
  mainMenu(list);
  return 0;
}

void readFile(LinkedList &list){
  //check to see if another file has been loaded
  string fname;  
  int num;
  string payload;
  ifstream inputFile;
  if(list.IsEmpty()){
    
    
    cout<<"What is the file name?: "<<endl;
    cin>>fname;
    cout<<"New message loaded"<<endl;
    inputFile.open(fname.c_str());
    while(inputFile >> num && inputFile >> payload){
      list.InsertEnd(num, payload);
    }
    inputFile.close();
  }

  else{
    int decision;
    cout<<"Do you want to:"<<endl;
    cout<<"1. Overwrite the message"<<endl;
    cout<<"2. Append the message"<<endl;
    cout<<"3. Cancel"<<endl;
    cin>>decision;
    do{
      switch(decision){
      case 1:
	list.Clear();
	cout<<"What is the file name?: "<<endl;
	cin>>fname;
	cout<<"New message loaded"<<endl;
	inputFile.open(fname.c_str());
	while(inputFile >> num && inputFile >> payload){
	  list.InsertEnd(num, payload);
	}
	break;
      case 2:
	cout<<"What is the file name?: "<<endl;
	cin>>fname;
	cout<<"File appended"<<endl;
	inputFile.open(fname.c_str());
	while(inputFile >> num && inputFile >> payload){
	  list.InsertEnd(num, payload);
	}
	break;
      case 3:
	break;
      }
    }while(decision < 1 || decision > 3);
  }
  inputFile.close();
}

void mainMenu(LinkedList &list){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout<<endl;//I'm OC about spacing
      cout << "What would you like to do?: " << endl;
      cout << "1. Load a new encrypted message" << endl;
      cout << "2. Display a raw message" << endl;
      cout << "3. Display an encrypted message" << endl;
      cout << "4. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 4);

    switch(option){
    case 1:
      readFile(list);
      break;
    case 2:
      displayMessage(list);
      break;
    case 3:
      displayEncrypt(list);
      break;
    case 4:
      exitLinked(list);
      isExit = 1;
      break;
    }
  }while(isExit == 0);
}

void displayMessage(LinkedList &list){
  if(list.IsEmpty())
    cout<<"You haven't loaded an encrypted message yet."<<endl;

  else{
    list.Display();
    list.Sort();
    list.Display();
  }
}

void exitLinked(LinkedList &list){
  cout<<"Have a nice day!"<<endl;
}

void displayEncrypt(LinkedList &list){
  if(list.IsEmpty())
    cout<<"You haven't loaded an encrypted message yet."<<endl;

  else{
    LinkedList list2 = list.Decrypt();
    list2.Sort();
    list2.Display();
  }
}
