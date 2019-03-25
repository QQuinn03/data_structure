// #ifndef DYSTACK_H
// #define DYSTACK_H
#include<iostream>
using namespace std;


template<class T>
class Dystack
{
protected:
  struct StackNode
  {
     T value;
     StackNode *next;
     StackNode(T v,StackNode * next1 = nullptr )
     {
       value = v;
       next = next1;
     }

  };
  StackNode *top;

public:
  Dystack() {top = nullptr;}
  ~Dystack();
  //Dystack(const Dystack &other);
  //Dystack<T>& operator = (const Dystack<T> &other);
  void push (T v);
  void pop();
  bool isEmpty();
  T getTop(StackNode *top);
  T getTop();

  //class Underflow{};
};

template<class T>
bool Dystack<T>:: isEmpty()
{
  return (top == nullptr);
}

template<class T>
Dystack<T>::~Dystack()
{
  while(top)
  {
    StackNode *temp = top;
    top = top->next;
    temp->next = nullptr;
    delete temp;

  }
}

template<class T>
void Dystack<T>::push (T v)
{
  StackNode *newSNode = new StackNode(v);
  newSNode->value = v;
  newSNode->next = top;
  top = newSNode;
}

template<class T>
void Dystack<T>::pop ()
{ if(top)
  {
  StackNode *temp = top;
  top = top->next;
  delete temp;}
  else
    cout<<"There is nothing there.\n";
  }

template<class T>
T Dystack<T>::getTop(StackNode *top)
{
  if(top)
    return top->value;
    else
      return 0;
}

template<class T>
T Dystack<T>::getTop()
{
  return getTop(top);
}
