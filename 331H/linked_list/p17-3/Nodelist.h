#ifndef NODELIST_H
#define NODELIST_H
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

class Nodelist
{
protected:
  Node *head;//headpointer
  int length;
public:
  Nodelist() { head = nullptr;} //constructor
  Nodelist(const Nodelist &other)
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



  ~Nodelist()
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
  void add(double number) //inserting p as head at the front
  //when adding to front, always make head == new pointer!!!
  {
    if(head == nullptr)
    {head = new Node(number,head);
    cout<<head->value<<"add success\n";
   }
     //cout<<head->next<<endl;} //make tail as nullptr;

    else
    {  Node *temp= new Node(number,head);
      temp->value = number;
      temp->next = head;
      head = temp; //assign temp address to head, now head is head again
      cout<<temp->value<<" add success \n";
      //cout<<(temp==head)<<endl; at this time head and temp has same
      //address
      //cout<<head<<endl;
      //cout<<temp<<endl;

    }
  }
  void remove(double number) //delete a given number
  {
     Node *temp1= head, *temp2 = head;

    if(!temp1)
    {cout<<"the list of nodes is empty.\n";
    return;}
    if(temp1->value == number)
    {//temp1 = head;
      head = head->next;
      delete temp1;
      cout<<"delete success.\n";

    }
    else
    {
      while(temp1!=nullptr && temp1->value !=number)
       { temp2= temp1;
         temp1 = temp1->next;
       }
      //how to delete, when the number is found.
      //1)make previous->next = current->next
      //2)delete current.
      if(temp1->value == number)
        { cout<<"The value has been found.\n";
          temp2->next = temp1->next;
          delete temp1;
          cout<<"The value has been deleted.\n";

          //cout<<temp1;
        }
     }

  }
   //cout<<"Non value is match.\n";
  int getlength()
  {
    Node *temp = head;
    int length1 = 0;
   if(head == nullptr) {cout<<"The list is empty.\n"; return 0;}
    while(temp)
     { length1++;
       temp = temp->next;

     }
     length = length1;
     return length;
     //cout<<length<<endl;
  }

  void sortnode()
{   Node *temp1 = nullptr; Node *temp2 = head;
    for(temp2 = head;!temp2;temp2= temp2->next)
    {
      for(temp1 = temp2->next; !temp1; temp1=temp1->next)
      {
        if(temp2->value > temp1->value)
        {swap(temp2->value,temp1->value);
        cout<<"swap success.\n";}
      }
    }

}
  void display()
  {
      Node *temp = head;
     if(head == nullptr) {cout<<"The list is empty.\n"; return;}
      while(temp)
       {
         cout<<temp->value<<" ";
         temp = temp->next;
         //temp = head;
       }
       cout<<endl;

  }
};
#endif
