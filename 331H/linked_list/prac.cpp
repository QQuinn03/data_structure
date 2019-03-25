#include<iostream>
using namespace std;


//print linked lisrt elements

struct Node
{
  double info;
  struct Node *next;
};

int main()
{
  Node *head = nullptr;
  head = new Node;
  //Node *temp; //= new Node;

  //created 1st node with info = 12.5

  head->info = 12.5;

  head->next = nullptr; //signifying end of list

  //created 2nd with info = 13.5
  Node *sec = nullptr;
  sec = new Node;


  sec->info = 13.5;
  sec->next = nullptr;
  head->next = sec;
  swap(head->info,sec->info);

  // Node *temp = head;
  //
  // head = sec;
  // sec = temp;
  cout<<head->info<<" ";
  cout<<sec->info;
  cout<<endl;

  return 0;
}
