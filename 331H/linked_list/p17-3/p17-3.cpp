#include"Nodelist.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  Nodelist list;
  list.add(2.5);
  list.add(7.9);
  list.add(12.6);
  list.add(5.6);
  //list.display();
  // cout<<list.getlength()<<endl;
  //  list.remove(2.5);
  //  list.display();
  //   cout<<list.getlength()<<endl;
  //   list.add(5.6);
  //   cout<<list.getlength()<<endl;
  // list.display();
  // Nodelist l2(list);
  // l2.display();
  // list.add(6.7);
  list.display();
  //l2.display();
  list.sortnode();
  cout<<"after sort.\n";
  list.display();

  // list.remove(7.9);
  // list.remove(12.6);
  // list.display();



  return 0;
}
