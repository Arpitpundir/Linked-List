#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* next;
};

void insertAtTail(node* &head, int val){
  if(head == NULL){
    head = new node;
    head->val = val;
    head->next = NULL;
    return;
  }
  node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  node *newNode = new node;
  newNode->val = val;
  newNode->next = NULL;
  temp->next = newNode;
}

void buildLL(node*&head, int n){
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

bool isPalindrome(node* head, node* end){
  if(head == NULL || head->next == NULL){
    return true;
  }
  while(head != NULL && end != NULL){
    if(head->val != end->val){
      return false;
    }else if(head->next == end){
      return true;
    }else if(head->next == end->next){
      return true;
    }
    head = head->next;
    end = end->next;
  }
}

node* findMid(node* head){
  if(head == NULL && head->next == NULL){
    return head;
  }
  node* slow = head;
  node* fast = head;
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

node* reverseLL(node* head){
  if(head == NULL && head->next == NULL){
    return head;
  }
  node* curr = head->next;
  node* prev = head;
  node* next = NULL;

  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
int main(){
  int n;
  cin>>n;
  node* head = NULL;
  buildLL(head, n);
  printLL(head);
  node* end = reverseLL(mid);
  cout<<end->val<<endl;
  if(isPalindrome(head, end)){
    cout<<"True"<<endl;
  }else{
    cout<<"False"<<endl;
  }
}