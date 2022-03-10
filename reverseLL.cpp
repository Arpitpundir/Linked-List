#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node*  next;
};


void printLL(node* start){
  //node* temp = start; since i am sending data by value then actuall value will not change.
  while(start != NULL){
    //cout<<"jk"<<endl;
    cout<<start->val;
    start = start->next;
  }
}

void insertHead(node* &head){
  //cout<<head<<endl;
  int temp;
  cin>>temp;
  while(temp != -1){
    node* newNode = new node;
    newNode->val = temp;
    newNode->next = head;
    //cout<<newNode->next<<endl;
    head = newNode;
    //cout<<head->val<<endl;
    //printLL(head);
    cin>>temp;
  }
}


void reverse(node* &head){
  node* curr, *next, *prev;
  curr = head;
  next = curr->next;
  prev = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  } 
  head = prev;
}

int main(){
  node* head = new node;
  head = NULL;
  insertHead(head);
  printLL(head);
  reverse(head);
  printLL(head);
  return 0;
}