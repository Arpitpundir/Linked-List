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

node* reverseLL(node* head){
  //cout<<"rwe";
  node* curr = head;
  node* prev = NULL;
  node* next = NULL;

  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

node* kAppend(node* head, int r){
  if(r == 0){
    return head;
  }else if(head == NULL){
    return head;
  }else if(head->next == NULL){
    return head;
  }
  node* slow = head;
  node* fast = head;
  
  while(r-- && fast->next != NULL){
    fast = fast->next;
  }
  
  while(fast->next != NULL && fast != NULL){
    fast = fast->next;
    slow = slow->next;
  }

  node* newHead = slow->next;
  slow->next = NULL;
  fast->next = head;
  return newHead;
}

int main(){
  int n, k;
  cin>>n;
  node* head = NULL;
  buildLL(head, n);
  cin>>k;
  int t = 0;
  int r = k;
  if(k >= n){
    t = k/n;
    r = k%n;
  }
  if(t%2 != 0){
    //head = reverseLL(head);
  }
  head = kAppend(head, r);
  printLL(head);
}

