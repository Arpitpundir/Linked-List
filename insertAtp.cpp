#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int val;
  node* next;
};

void insertAtEnd(node* &head, int val){
  if(head == NULL){
    head = new node;
    head->val = val;
    head->next = NULL;
    return;
  }
  node* newNode = new node;
  newNode->val = val;
  node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPos(node* &head, int val, int pos){
  node* newNode = new node;
  newNode->val = val;
  node* temp = head;
  int count = 1;
  while(count != pos){
    temp = temp->next;
    cout<<temp->val<<endl;
    count++;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void printLL(node* start){
  //node* temp = start; since i am sending data by value then actuall value will not change.
  while(start != NULL){
    cout<<start->val;
    start = start->next;
  }
}

int main(){
  node* head = NULL;
  int temp;
  cin>>temp;
  while(temp != -1){
    insertAtEnd(head, temp);
    cin>>temp;
  }
  printLL(head);
  cin>>temp;
  while(temp != -1){
    int p;
    cin>>p;
    insertAtPos(head, temp, p);
    cin>>temp;
  }
  printLL(head);
}
