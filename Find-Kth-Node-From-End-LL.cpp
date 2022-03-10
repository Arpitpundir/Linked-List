#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* next;
};

void insertAtTail(node* &head, int val){
  node* newNode = new node;
  newNode->val = val;
  if(head == NULL){
    newNode->next = head;
    head = newNode;
    return;
  }
  node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;
}

void buildLL(node* &head){
  int temp;
  cin>>temp;
  while(temp!=-1){
    insertAtTail(head, temp);
    cin>>temp;
  }
}

int findKth(node* head, int k){
  node* slow = head;
  node* fast = head;
  while(k--){
    fast = fast->next;
  }
  while(fast != NULL){
    slow = slow->next;
    fast = fast->next;
  }
  return slow->val;
}

int main(){
  node* head = NULL;
  buildLL(head);
  cout<<findKth(head, 3)<<endl;
  return 0;
}