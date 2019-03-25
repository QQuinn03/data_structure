#include"ReNode.h"
#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
  ReNode list;
  list.insert(2.5);
  list.insert(7.9);
  list.insert(12.6);
  list.insert(5.6);

 list.remove(7.9);

 list.sortnode();
 list.display();
 // list.insert(6.4);
 // list.insert(11.4);
 // list.sortnode();
 //
 // list.displayreverse();
 //
 // list.tryy(5.6);

 // list.countbigger(2.5);
 // cout<<endl;


 // int i = list.getlength();
 // cout<<i<<endl;
  // cout<<"after sort.\n";
  // list.display();

  // list.remove(7.9);
  // list.remove(12.6);
  // list.display();



  return 0;
}
