#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* next;
};

void floydsCycle(node* head){
  if(head == NULL || head->next == NULL){
    return;
  }
  node* slow = head;
  node* fast = head;
  while(slow->val != fast->val){
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = head;
  node* prev = fast;
  while(slow->val != fast->val){
    slow = slow->next;
    fast = fast->next;
    prev = fast;
  }
  prev->next = NULL;
  return;
}

