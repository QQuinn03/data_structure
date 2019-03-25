// contents of Double.h
#include"Dnode.h"
#include<iostream>
using namespace std;
//template<class T>
// class Double
// {
// protected:
//   struct Node
//   {
//     T value;
//     Node *next;
//     Node *previous;
//     Node(T v, Node *next1 = nullptr, Node *previous1 = nullptr)
//     {
//       value = v;
//       next = next1;
//       previous = previous1;
//     }
//   };
//  Node *head;
//  Node *tail;
//  int length;
// public:
//   Double(){head = nullptr; tail = nullptr;}
template <class T>
Dnode<T>::~Dnode()
  {
    Node *iter = head;
    while(!iter->next)
    {
      Node *garbage = iter;
      iter = iter->next;
      if(!iter->next) {garbage->next = nullptr;}
      if(!iter->previous) {garbage->previous = nullptr;}
      //delete garbage;
    }
  }

  template <class T>
  Dnode<T>::Dnode(const Dnode &other)
  {
      T v;
      Node *right = other.head; //temp1 is a pointer to other(right value)
      //length = other.length;
      v = other.head->value;
      head = new Node(v);//set up the left head value.
      //head->value = temp1->value;
      head->next = right->next;
      head->previous = right->previous;
      Node *left = head;
      left = new Node(v);
      //set up the second pointer in the left
      Node *temp = head;
      while(!right->next) //in case there is only one node in other(right value)
      {
        left->value = right->value;
        temp = left;
        left = left->next;
        left->previous = temp;
        right = right->next;
      }
      left->next = nullptr;


  }

  template <class T>
 Dnode<T>& Dnode<T>:: operator = (const Dnode<T> &other)
  {
    if(other.head==nullptr)
    { cout<<"The object is empty.\n";
      head =nullptr;
      //length = 0;
    }
    else{
     T v;
      Node *right = other.head; //temp1 is a pointer to other(right value)

      v = other.head->value;
      head = new Node(v);//set up the left head value.
      //head->value = temp1->value;
      head->next = right->next;
      head->previous = right->previous;
      Node *left = head;
      left = new Node(v);
      //set up the second pointer in the left
      Node *temp = head;
      while(!right->next) //in case there is only one node in other(right value)
      {
        left->value = right->value;
        temp = left;
        left = left->next;
        left->previous = temp;
        right = right->next;
      }
      left->next = nullptr;
   }
   cout<<"The existing object has been assigned. \n";
   return *this;

  }
  template <class T>
  void Dnode<T>:: remove(T number) //delete a given number
  {
     Node *temp1= head, *temp2 = head;

    if(!temp1)
    {cout<<"the list of nodes is empty.\n"; return;}
    if(temp1->value == number)
    {//temp1 = head;
      head = head->next;
      head->previous = nullptr;
      delete temp1;
      cout<<"delete success.\n";
      length--;
    }
    else
    {
      while(temp1->next!=nullptr && temp1->value !=number)
       { temp2= temp1;
         temp1 = temp1->next;
       }

      if(temp1->next ==nullptr && temp1->value == number)
        {  cout<<"The value: "<<temp1->value<<" has been found.\n";
           temp2->next = nullptr;
           delete temp1;
           cout<<"The value has been deleted.\n";
           length--;
         }
      else if(temp1->value == number)
        { cout<<"The value: "<<temp1->value<<" has been found.\n";
          temp2->next = temp1->next;
          temp1->next->previous = temp2;
          delete temp1;
          cout<<"The value has been deleted.\n";
          length--;
        }
      else if(length ==1 && temp1->value == number)
      {
        cout<<"This is the last node.";
        delete temp1;
       }
      else{cout<<"The number was not found.\n";}
     }

  }
template <class T>
int Dnode<T>:: getlength()
{
    Node *iter = head;
    int length1 = 0;
   if(head == nullptr && head->next == nullptr)
   {cout<<"The list is empty.\n"; return 0;}
   while(iter)
     {
       length1++;
       iter = iter->next;

     }
    length = length1;
    return length;

  }
template <class T>
void Dnode<T>:: addBegin(T v)
  {  Node *newNode = new Node(v);
    //if no doublely linked list exit
    if(head == nullptr) {head = newNode;}
    else
     {
      newNode->next = head;
      head->previous = newNode;
      //newNode->previous = nullptr; //we don't need this bcz the head ==null
                                    // aready when create a new node;
      head = newNode;
      cout<<"Adding a number at the head position success.\n";
    }
    length++;
  }
template <class T>
void Dnode<T>:: addend(T v)
  {  Node *newNode = new Node(v);
    //if no doublely linked list exit
    Node *iter = head;
  if(head == nullptr) {head = newNode;}
  else
    {
      while(iter->next){ iter = iter->next;}
      //cout<<iter->value;
      //Node *temp = iter;
      newNode->previous = iter;
      iter->next = newNode;
      iter = newNode;
      iter->next = nullptr;
      //if I comment the above two lines, why infinite loop?
    cout<<"Add new node to the end success. New value is: "<<newNode->value
        <<endl;

   }
  length++;
  }

template <class T>
void Dnode<T>:: showforward()
  {
    Node *iter = head;
   if(head == nullptr && tail == nullptr)
      {cout<<"The list is empty.\n";}
   else
      {  cout<<"Now show the nodes forward.\n";
          while(iter)
         {
          cout<<iter->value<<" ";
          iter = iter->next;
         }
       cout<<endl;
      }
  }

template <class T>
void Dnode<T>:: showbackward()
  {
    Node *iter = head;
   if(head == nullptr && tail == nullptr)
      {cout<<"The list is empty.\n"; return;}
   else
   {
     cout<<"Now print the list in backwards.\n";
     while(iter->next){ iter = iter->next;}
     if(iter->next ==nullptr)
       {
         cout<<iter->value<<" ";
         iter = iter->previous;
         while(iter)
         {
        cout<<iter->value<<" ";
        iter = iter->previous;
        }
      }
    }
    cout<<endl;

   }
