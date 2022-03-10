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

void buildLL(node* &head, int n){
  int temp;
  while(n--){
    cin>>temp;
    insertAtTail(head, temp);
  }
}

void printLL(node* head){
  while(head != NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

node* kReverse(node* head, int k){
  if(head == NULL){
    return head;
  }
  node* curr = head;
  node* prev = head;
  node* next = head;

  int count = 0;
  while(count < k && curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  head->next = kReverse(curr, k);
  return prev;
}

int main(){
  int n, k;
  cin>>n>>k;
  node* head = NULL;
  buildLL(head, n);
  head = kReverse(head, k);
  printLL(head);
}

