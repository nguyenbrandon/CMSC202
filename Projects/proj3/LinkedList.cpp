#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
  m_head = NULL;
}

LinkedList::~LinkedList(){

  Node *current = m_head;
  Node *nextNode = current->m_next;
  while (nextNode != NULL){
    delete current;
    current = nextNode;
    nextNode = nextNode->m_next;
  }
  current = NULL;
  nextNode = NULL;
  m_head = NULL;
  m_tail = NULL;

}


Node* LinkedList::CreateNode(int newInt, string newPayload){
  //creates the temporary node to be filled
  Node *temp = new Node();
  temp->m_int = newInt;
  temp->m_payload = newPayload;
  return temp;
}

void LinkedList::InsertEnd(int newInt, string newPayload){
  //need to create a node before you add it to the LL
  Node *newNode = CreateNode(newInt, newPayload);
  //checks to see if it's empty first
  if(IsEmpty()){
    m_head = newNode;
    m_tail = newNode;
  }
  else{
    newNode->m_next = NULL;
    m_tail->m_next = newNode;
    m_tail = m_tail->m_next;
  }
}

void LinkedList::Display(){

  cout<<"Payload of list are:"<<endl;
  Node *current = m_head;


  while(current != NULL){
    cout<<current->m_payload<<"->";
    current = current->m_next;
  }
  
  cout<<"END"<<endl;
  
}
void LinkedList::Sort(){
  Node *current1 = m_head;
  Node *next1 = current1->m_next;
  //used counter to measure the length of the LL
  int counter = 0;
  while(next1 != NULL){
    counter++;
    current1 = next1;
    next1 = current1->m_next;
  }
  Node *current;
  Node *next;
  Node *temp;

  //runs till the end of the LL
  for(int i = 0; i < counter; i++){
    current = m_head;
    next = current->m_next;
    //nest loops for bubble sort()
    while(current->m_next != NULL){
      if(current->m_int > next->m_int){
	temp = CreateNode(current->m_int, current-> m_payload);
	current->m_int = next->m_int;
	current->m_payload = next->m_payload;
	next->m_int = temp->m_int;
	next->m_payload = temp->m_payload;
      }
      current = next;
      next = current->m_next;
    }
  }
}
bool LinkedList::IsEmpty(){
  if(m_head == NULL)
    return true;
  return false;
}

LinkedList LinkedList::Decrypt(){
  Node *current = m_head;
  LinkedList newList;
  //adds the node to the LL if it's a perfect square or cube
  while(current != NULL){
    if(IsPerfectSquare(current->m_int)){
      newList.InsertEnd(sqrt(current->m_int), current->m_payload);
    }
    else if(IsPerfectCube(current->m_int)){
      newList.InsertEnd(cbrt(current->m_int), current->m_payload);
    }
    current = current->m_next;
  }
  

  
  return newList;
}
bool LinkedList::IsPerfectSquare(int n){
  int num = 0;

  while(true){
    if(num*num == n)
      return true;
    else if(num*num > n){
      return false;
    }
      num++;
  }
}
bool LinkedList::IsPerfectCube(int n){
  int num = 0;

  while(true){
    if(num*num*num == n)
      return true;
    else if(num*num*num > n){
      return false;
    }
    num++;
  }
}

void LinkedList::Clear(){
  Node *current = m_head;
  Node *nextNode = current->m_next;
  while (nextNode != NULL){
    delete current;
    current = nextNode;
    nextNode = nextNode->m_next;
  }
  delete current;
  current = NULL;
  delete nextNode;
  nextNode = NULL;
  m_head = NULL;
  m_tail = NULL;
}
