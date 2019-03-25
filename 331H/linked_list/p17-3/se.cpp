#include"Nodelist.h"
#include<iostream>
using namespace std;

int main()
{
  Nodelist list;
  list.add(2.5);
  list.add(7.9);
  list.add(12.6);
  list.display();
  list.remove(2.5);
  list.remove(7.9);
  list.remove(12.6);
  list.display();



  return 0;
}

//segmatation fault;
