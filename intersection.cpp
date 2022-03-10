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
  }
  cout<<endl;
}

int findLength(node* head){
  if(head == NULL){
    return 0;
  }
  int count = 0;
  while(head != NULL){
    count++;
    head = head->next;
  }
  return count;
}

int findIntersection(node* head1, node* head2){
  while(head1 != NULL && head2 != NULL){
    if(head1->val == head2->val){
      return head1->val;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  return -1;
}

int main(){
  int n1;
  cin>>n1;
  node *head1 = NULL, *head2 = NULL;
  buildLL(head1, n1);
  int n2;
  cin>>n2;
  buildLL(head2, n2);
  int l1 = findLength(head1);
  int l2 = findLength(head2);

  int d = abs(l1-l2);
  if(l1 > l2){
    while(d--){
      head1 = head1->next;
    }
  }else if(l2 > l1){
    while(d--){
      head2 = head2->next;
    }
  }
  cout<<findIntersection(head1, head2);
  return 0;
}

