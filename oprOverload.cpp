#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* next;
};
void buildLL(node* &head){
  int temp;
  cin>>temp;
  while(temp != -1){
    node* newNode = new node;
    newNode->val = temp;
    //node* tempNode = head;
    newNode->next = head;
    head = newNode;
  }
}

void printLL(node* start){
  //node* temp = start; since i am sending data by value then actuall value will not change.
  while(start != NULL){
    cout<<start->val;
    start = start->next;
  }
  cout<<endl;
}

istream& operator >>(istream &is, node* &head){
  buildLL(head);
  return is;
}

ostream& operator <<(ostream &os, node* head){
  printLL(head);
  return os;
}

int main(){
  node* head = new node;
  cin>>head;
  cout<<head;
}