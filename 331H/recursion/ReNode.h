#ifndef RENODE_H
#define RENODE_H
#include<iostream>
#include<algorithm>
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

class ReNode
{
protected:
  Node *head;//headpointer
  int length;
public:
  ReNode() { head = nullptr;} //constructor
  ReNode(const ReNode &other)
  {
    if(other.head==nullptr)
    { cout<<"The object is empty.\n";
      head =nullptr;
      //length = 0;
    }
    else
    { double v;
      Node *right = other.head; //temp1 is a pointer to other(right value)
      //length = other.length;
      v = other.head->value;
      head = new Node(v);//set up the left head value.
      //head->value = temp1->value;
      head->next = right->next;
      Node *left = head;
      left = new Node(v);//set up the second pointer in the left
      while(!right->next) //in case there is only one node in other(right value)
      {
        //left->next = new Node(v);
        left = left->next;
        right = right->next;
        left->value = right->value;
      }
      left->next = nullptr;
    }

  }



  ~ReNode()
  {  Node *ptr= head;
    int i = 1;
    while(!ptr)
    {
      Node *garbage = ptr;
      ptr = ptr->next;
      delete garbage;
      cout<<"node "<<i<<" has been deleted"<<endl;
      i++;
    }
  }
  void insert(Node *&head, double item)
  {
    if(head==nullptr || head->value>item)
    {
      // Node *temp = head;
      // head = new Node(item); //confused. does a new pointer
      // head->next = temp;      //created and assigned to head by new Node(item)?
      Node *temp = new Node(item);
      temp->next  = head;
      head = temp;
      length++;
    }
    else{ insert(head->next, item);}

  }

  void insert(double item)
  {
    insert(head, item);
  }

  void remove(Node *head,double item) //delete a given number
  {
      if(head || head->value!=item)
      {
        if(head->value == item)
        {
          Node *temp = head;
          head = head->next;
          delete temp;
        }
        else {remove(head->next, item);}
      }

      // if(head &&head->value !=item)
      // {
      //   remove(head->next,item);
      // }
      // else{
      //   Node *previous = head;
      //   Node *current = head->next;
      //   //previous->next = current->next;
      //   head = current;
      //   delete previous;
      //   length--;
      // }
  }

  void remove(double item)
  { remove(head, item);
    cout<<"Removal successs.\n"; length--;
  }

  int getlength(Node *head)
  {
    int i = 1;
    if(!head) {return 0;}
    else
    {
      return i + getlength(head->next);
    }
  }

  int getlength()
  {
    return getlength(head);
  }

void sortnode()
{
  Node *curNode = head; Node *minNode; Node *temp = head;
  double tempv = curNode->value;
  double t;
  int length = getlength();

  for(int i =1; i<=length-1;i++)
  {
    while(curNode)
    {
      if(curNode->value<=tempv)
      { tempv = curNode->value;
        minNode = curNode;
      }
      curNode = curNode->next;
    }
    t = temp -> value;
    temp -> value = minNode -> value;
    minNode -> value = t;
    temp = temp->next;
    curNode = temp;
    tempv = temp->value;
  }
//return *this;
}
  // using recursion to display the node backwards.
  void displayreverse(Node *head)
  {
       if(head == nullptr) {return;}
       if(head)
       { cout<<head->value<<" ";
          displayreverse(head->next);}
  }

  void tryy(Node *head, double item)
  {
    if(head&&head->value <item) {tryy(head->next,item);}
    else
    {  if(!head) {return;}
       else{
         tryy(head->next,item);
         cout<<head->value<<" ";
       }
    }

  }

  void tryy(double item)
  {
    tryy(head,item);
    cout<<endl;
  }

  int countbigger(Node *head, double item)
  {
    int i =1;
    if(head &&head->value<=item)
    {return 0 + countbigger(head->next,item);}
    else
    {
      if(!head) {return 0;}
      else
      {
      return i+countbigger(head->next,item);}
    }

  }

  void countbigger(double item)
  {
    cout<< countbigger(head,item);

  }
  void displayreverse()
  {
    displayreverse (head);
    cout<<endl;
  }

  void display(Node *head)
  {
    if(!head) {return;}
    else{
      display(head->next);
    }
    cout<<head->value<<" ";

  }
  void display()
  {
    display(head);
    cout<<endl;
  }

  // void display()
  // {
  //     Node *temp = head;
  //    if(head == nullptr) {cout<<"The list is empty.\n"; return;}
  //     while(temp)
  //      {
  //        cout<<temp->value<<" ";
  //        temp = temp->next;
  //        //temp = head;
  //      }
  //      cout<<endl;
  //
  // }



};
#endif
