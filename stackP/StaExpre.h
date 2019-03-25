#include<iostream>
using namespace std;


template<class T>
class StaExpre
{
protected:
  struct Node
  {
     T value;
     Node *next;
     Node(T v,Node * next1 = nullptr )
     {
       value = v;
       next = next1;
     }

  };
  Node *top;
public:
  StaExpre () {top = nullptr;}
  ~StaExpre ();
  //Dystack(const Dystack &other);
  //Dystack<T>& operator = (const Dystack<T> &other);
  void push (T v);
  void pop();
  bool isEmpty();
  T getTop(Node *top);
  T getTop();
  // string infixTopost(string a);

  //class Underflow{};
};

template <class T>
StaExpre<T>::~StaExpre()
{
    Node *iter = top;
    while(iter)
    {
      Node *garbage = iter;
      iter = iter->next;
      delete garbage;
    }
  }

template <class T>
void StaExpre<T>:: push(T v)
{
  Node *temp = new Node(v);
  //emp->value = v;
  temp->next = top;
  top = temp;
}

template <class T>
void StaExpre<T>:: pop()
{
  if(top!=nullptr)
  {
    Node *temp = top;
    top = top->next ;
    delete temp;
  }
}

template <class T>
bool StaExpre<T>::isEmpty()
{
  if(!top) {return true;}
  return false;
}

template <class T>
T StaExpre<T>::getTop(Node *top)
{
  if(top!=nullptr) {return top->value;}
  return 0;
}

template <class T>
T StaExpre<T>::getTop()
{
  return getTop(top);
}
