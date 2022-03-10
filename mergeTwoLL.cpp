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

node* mergeLL(node* a, node* b){
  if(a == NULL){
    return b;
  }else if(b == NULL){
    return a;
  }

  if(a->val < b->val){
    a->next = mergeLL(a->next, b);
    return a;
  }else{
    b->next = mergeLL(a, b->next);
    return b;
  }
}

void printLL(node* head){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head->next;
  }
  cout<<endl;
}

int main(){
  node* head1, *head2;
  head1 = NULL;
  head2 = NULL;
  buildLL(head1);
  buildLL(head2);
  printLL(head1);
  printLL(head2);
  head1 = mergeLL(head1, head2);
  printLL(head1);

}