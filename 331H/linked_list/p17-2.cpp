//bulding and traversal of a linked list

#include<iostream>
#include<fstream>
using namespace std;

struct Node
{
  double value;
  Node *next;
  Node(double v, Node *next1 = nullptr)
  {
    value = v;
    next = next1;
  }
};

int main()
{
  double num;
  Node *head = nullptr;

  for(int i=1;i<=4;i++)
  {
    head = new Node(i, head);
    cout<<i<<" item finish entering."<<endl;

  }
  cout<<head->value<<endl;

  Node *temp = head;
  while(temp !=nullptr)
  {
    cout<<temp->value<<" ";
    temp = temp->next;
  }
  cout<<endl;

  return 0;

}
