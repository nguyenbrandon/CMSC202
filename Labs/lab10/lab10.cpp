#include <iostream>
#include <string>
using namespace std;

//Constants for our for loop
const int START = 0;
const int END = 10;

//Our node structure
struct Node {
  int num;
  Node * next;
};

//Prototype for our recursive function
void printList(Node* &ptrNode, int direction);

int main (){
  //Creating a new pointer to the head of our linked list
  Node * head = NULL;
  //For loop that builds our linked list with 0-9
  for(int i = START; i < END;i++){
    if (head == NULL){
      Node* newNode = new Node();
      head = newNode;
      newNode->num = i;
    }
    else{
      Node* newNode= new Node();
      newNode->num = i;
      newNode->next = head;
      head = newNode;
    }
  }
  //Because we don't have a "linked list" we need to pass the head
  Node * ptrNode = head;
  //First try we are going to go through the linked list starting at 0
  cout << "Forward" << endl;
  printList(ptrNode, 1);
  //Second try we are going to go through the linked list starting at 9
  cout << "Backward" << endl;
  printList(ptrNode, 0);

  //Empties Linked List so there is no memory leak
  //PART 2 - Write the while loop to clear out the linked list

  ptrNode = head->next;
  while(ptrNode != NULL){
    delete head;
    head = ptrNode;
    ptrNode = head->next;
  }
  delete head;

  return 0;

}
void printList(Node* &ptrNode, int direction){
  //PART 1 - Write the code to recursively print the linked list
  //Direction indicates forward or backward (0 or 1)

  if(direction == 1 && ptrNode->next != NULL){
    printList(ptrNode->next, direction);
    cout<<ptrNode->num<<endl;
  }
  if(direction == 0 && ptrNode->next != NULL){
    cout<<ptrNode->num<<endl;
    printList(ptrNode->next, direction);
  }

}
