// #ifndef DNODE_H
// #define DNODE_H
#include <iostream>
using namespace std;


void displayMenu()
  {
     cout<<"  Client's choices \n";
     cout << "-------------------------------------\n";
     cout << "1) Read the value\n";
     cout << "2) Stop reading and exit\n";
  }


template<class T>
class Dnode
{
protected:
  struct Node
  {
    T value;
    Node *next;
    Node *previous;
    Node(T v, Node *next1 = nullptr, Node *previous1 = nullptr)
    {
      value = v;
      next = next1;
      previous = previous1;
    }
  };

 Node *head;
 Node *tail;
 int length;
public:
  Dnode(){head = nullptr; tail = nullptr;}
  ~Dnode();
  Dnode(const Dnode &other);
  Dnode<T>& operator = (const Dnode<T> &other);
  void remove(T );
  int getlength();
  void addBegin(T v);
  void addend(T v);
  void showforward();
  void showbackward();
  void iterForward();
  void iterBack();

};

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
      //head->next = right->next;
      head->previous = nullptr;
      Node *left = head;
      //set up the second pointer in the left
      Node *temp = left->previous;
      right = right->next;

      while(right) //in case there is only one node in other(right value)
      {
        temp = left;
        left = new Node(right->value);
        left->previous = temp;
        temp->next = left;
        right = right->next;
      }
      tail = left;
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
    else
    {
     // T v;
     //  Node *right = other.head; //temp1 is a pointer to other(right value)
     //
     //  v = other.head->value;
     //  head = new Node(v);//set up the left head value.
     //  //head->value = temp1->value;
     //  head->next = right->next;
     //  head->previous = right->previous;
     //  Node *left = head;
     //  left = new Node(v);
     //  //set up the second pointer in the left
     //  Node *temp = head;
     //  while(right->next) //in case there is only one node in other(right value)
     //  {
     //    left->value = right->value;
     //    temp = left;
     //    left = left->next;
     //    left->previous = temp;
     //    right = right->next;
     //  }
     //    tail = left;
     T v;
     Node *right = other.head; //temp1 is a pointer to other(right value)
     //length = other.length;
     v = other.head->value;
     head = new Node(v);//set up the left head value.
     //head->value = temp1->value;
     //head->next = right->next;
     head->previous = nullptr;
     Node *left = head;
     //set up the second pointer in the left
     Node *temp = left->previous;
     right = right->next;

     while(right)
     {
       temp = left;
       left = new Node(right->value);
       left->previous = temp;
       temp->next = left;
       right = right->next;
     }
     tail = left;
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
    {
      head = head->next;
      head->previous = nullptr;
      delete temp1;
      cout<<number<<" has been deleted successful.\n";
      length--;
    }
    if(tail->value ==number && length ==2)
    {
      cout<<"The tail value: "<<tail->value<<" has been found.\n";
      Node *temp = tail;
      tail = head;
      tail->next = nullptr;
      tail->previous = nullptr;
      delete temp;
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
           tail = temp2;
           tail->next = nullptr;
           delete temp1;
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

      else{cout<<"The number "<<number<<" was not found.\n";}
     }

  }
template <class T>
int Dnode<T>:: getlength()
{
    Node *iter = head;
    int length1 = 0;
   if(head == nullptr ||tail == nullptr)
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
    if(head == nullptr)
    { head = newNode;
      tail = newNode;
      cout<<"Adding number "<< head->value<<" at the head position success.\n";
    }
    else
     {
      newNode->next = head;
      head->previous = newNode;
      head = newNode;
      cout<<"Adding number "<< head->value<<" at the head position success.\n";
    }
    length++;
  }
template <class T>
void Dnode<T>:: addend(T v)
  {  Node *newNode = new Node(v);
    //if no doublely linked list exit
  if(head == nullptr)
  { head = newNode;
    tail = newNode;
    }
  else
    {
      tail->next = newNode;
      newNode->previous = tail;
      tail = newNode;
      tail->next = nullptr;
    cout<<"Add new node to the end success. New tail value is: "<<tail->value
        <<endl;
   }
  length++;
  }

template <class T>
void Dnode<T>:: iterForward()
  { int times = length;
    Node *iter = head;
    char choice;
    char MAX = '2';
   if(head == nullptr ||tail == nullptr)
      {cout<<"The list is empty.\n";}
   else
      { displayMenu();
        cout<<"Please enter a choice between 1-2\n";
        do{

         cin>>choice;
         switch(choice)
         {
          case '1': if(iter == tail)
                      {cout<<iter->value<<endl;
                      cout<<"End of list. Please enter 2 to exit.\n";}
                    else{
                    cout<<"Continue reading the value"<<endl;
                    cout<<iter->value<<endl;
                    iter = iter->next;
                    times--;}
                    break;
          case'2':  cout<<"Stop reading"<<endl;
                    break;

          default:
                    break;

        }
      }while(choice != MAX);
       cout<<endl;
      }
    }


template <class T>
void Dnode<T>:: iterBack()
{ int times = length;
  Node *iter = tail;
  char choice;
  char MAX = '2';
 if(head == nullptr ||tail == nullptr)
    {cout<<"The list is empty.\n";}
 else
    { displayMenu();
      cout<<"Please enter a choice between 1-2\n";
      do{

       cin>>choice;
       switch(choice)
       {
        case '1': if(iter == head)
                    {cout<<iter->value<<endl;
                    cout<<"Reading backward has reached the head value. Please enter 2 to exit.\n";}
                  else{
                  cout<<"Continue reading the value"<<endl;
                  cout<<iter->value<<endl;
                  iter = iter->previous;
                  times--;}
                  break;
        case'2':  cout<<"Stop reading"<<endl;
                  break;

        default:
                  break;

      }
    }while(choice != MAX);
     cout<<endl;
    }
  }
  template <class T>
  void Dnode<T>:: showforward()
{
  Node *iter = head;
  if(head == nullptr) {cout<<"The object is an empty list.\n";}
  else
  {
    while(iter)
    {
      cout<<iter->value<<" ";
      iter = iter->next;
    }
  }
  cout<<endl;
}

template <class T>
void Dnode<T>:: showbackward()
{
Node *iter = tail;
if(head == nullptr) {cout<<"The object is an empty list.\n";}
else
{
  while(iter)
  {
    cout<<iter->value<<" ";
    iter = iter->previous;
  }
}
cout<<endl;
}
