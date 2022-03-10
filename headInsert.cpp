#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node*  next;
};

void insertHead(node* &start, int val){
  node* newNode = new node;
  newNode->val = val;
  newNode->next = start;
  start = newNode;
}

void printLL(node* start){
  //node* temp = start; since i am sending data by value then actuall value will not change.
  while(start != NULL){
    cout<<start->val;
    start = start->next;
  }
}
int main(){
  node* start = new node;
  start = NULL;
  int temp;
  cin>>temp;
  while(temp != -1){
    //start = insertHead(start, temp);no need to do this since we have send pointer by reference.
    insertHead(start, temp);
    cin>>temp;
  }
  printLL(start);
}