#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* next;
};

void insertHead(node* &head){
  int temp;
  cin>>temp;
  while(temp != -1){
    node* newNode = new node;
    newNode->val = temp;
    newNode->next = head;
    head = newNode;
    cin>>temp;
  }
}

int findMid(node* head){
  node *fast = head;
  node *slow = head;
  while(fast->next!= NULL && fast->next->next !=  NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->val;
}

void printLL(node* head){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head->next;
  }
  cout<<endl;
}

int main(){
  node* head = NULL;
  insertHead(head);
  printLL(head);
  cout<<findMid(head)<<endl;
}

