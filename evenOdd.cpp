#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int val;
  node *next;
};

void insertAtTail(node *&head, int val)
{
  node *newNode = new node;
  newNode->val = val;
  if (head == NULL)
  {
    newNode->next = head;
    head = newNode;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;
}

void buildLL(node *&head, int n)
{
  int temp;
  while (n--)
  {
    cin >> temp;
    insertAtTail(head, temp);
  }
}

void printLL(node *head)
{
  while (head != NULL)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void arrange(node *&head)
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }
  
  node *oddEnd = NULL;
  node *evenHead = NULL;
  node* next = NULL;
  while(head->next != NULL){
    next = head->next;
    if(head->val%2 == 0){
      head->next = even;
      evenHead = head;
    }else{
      oddEnd->next = head;
      head->next = NULL;;
    }
    head = next;
  }

}

int main()
{
  int n;
  cin >> n;
  node *head = NULL;
  buildLL(head, n);
  arrange(head);
  printLL(head);
}