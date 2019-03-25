#include"Dnode.h"
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
  cout<<"Create a Dnode type named d1.\n";
  Dnode<int> d1;
  cout<<"Add number 1-6 to d1.\n";
  d1.addBegin(1);
  d1.addBegin(2);
  d1.addBegin(3);
  d1.addBegin(4);
  d1.addBegin(5);
  d1.addend(6);
  cout<<"Finishing adding.\n\n\n";
  cout<<"Now showing the value backward\n";
  d1.iterBack();
  cout<<"Now showing the value forward\n";
  d1.iterForward();
  cout<<"\n";
  cout<<"Removing the numbers from the list\n";
  d1.remove(1);
  d1.remove(2);
  d1.remove(11);
  cout<<"Now the length of d1: "<<d1.getlength()<<endl;

 // cout<<"Initialize a new object named d2 and copy d1's value.\n";
 //  Dnode<int> d2(d1);
 // d2.addBegin(12);
 // cout<<"d2's values.\n";
 // d2.showforward();
 // cout<<"d1's values.\n";
 // d1.showforward();
 //
 //  cout<<"Assign a Dnode type named d3 and with d2's value.\n";
 //  Dnode<int> d3;
 //  d3 = d2;
 //  d3.addBegin(25);
 //  cout<<"d3's values.\n";
 //  d3.showforward();
 //  cout<<"d2's values.\n";
 //  d2.showforward();


// cout<<"comparing to d2 value: \n";
// d2.showforward();
// //   d3.remove(2);
// //   d3.remove(4);
// //  d3.remove(3);
// //   d3.remove(6);
// //   d3.remove(25);
// //   d3.remove(5);
// //   d3.remove(12);
// //   d3.remove(1);
// //   //d3.remove(6);
//
//     // cout<<"Now d3's length: "<<d3.getlength()<<endl;
//     // d3.showforward();


return 0;
}
