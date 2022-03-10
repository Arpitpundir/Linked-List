#include<bits/stdc++.h>
using namespace std;

class node {
  public:
  int val;
  node* next;
};

void deleteHead(node* &head){
  if(head == NULL){
    return;
  }
  node* temp = head;
  head = head->next;
  delete temp;
  return;
}

void deleteMiddle(node* &head, int pos){
  if(head == NULL){
    return;
  }
  node* temp = head;
  node* prev = head;
  int count = 1;
  while(count < pos){
    if(temp == NULL)
    return;
    prev = temp;
    temp = temp->next;
    count++;
  }
  prev->next = temp->next;
  delete temp;
  return;
}

void deleteTail(node* &head){
  if(head == NULL)
  return;

  node* temp = head;
  node* prev = head;
  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  delete temp;
}

void insertHead(node* &start, int val){
  node* newNode = new node;
  newNode->val = val;
  node* temp = start;
  start = newNode;
  newNode->next = temp;
}

void printLL(node* start){
  //node* temp = start; since i am sending data by value then actuall value will not change.
  while(start != NULL){
    cout<<start->val;
    start = start->next;
  }
  cout<<endl;
}
int main(){
  node* head = new node;
  head = NULL;
  int temp;
  cin>>temp;
  while(temp != -1){
    //start = insertHead(start, temp);no need to do this since we have send pointer by reference.
    insertHead(head, temp);
    cin>>temp;
  }
  printLL(head);
  deleteHead(head);
  printLL(head);
  deleteTail(head);
  printLL(head);
  deleteMiddle(head, 6);
  printLL(head);
}