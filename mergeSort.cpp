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

void printLL(node* head){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head->next;
  }
  cout<<endl;
}
node* findMid(node* head){
  node* slow = head;
  node* fast = head;

  while(fast->next != NULL && fast->next->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
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

node* mergeSort(node* head){
  if(head->next == NULL){
    return head;
  }

  node* mid = findMid(head);
  node* b = mid->next;
  mid->next = NULL;
  head = mergeSort(head);
  b = mergeSort(b);
  return mergeLL(head, b);
}
int main(){
  node* head;
  head = NULL;
  buildLL(head);
  printLL(head);
  head = mergeSort(head);
  printLL(head);
  return 0;
}